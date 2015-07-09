#ifdef USE_MEMTRACK
#include <memtrack.h>
#endif

#include "base/memory_blocks_pool.h"

struct MemoryBlocksPool {
    void    *blocks;
    int     *ids;
    size_t  blocks_count;
    size_t  block_size;
    size_t  blocks_num;
};

#define GET_INDEX(id) ((id) >> 16)
#define GET_ID(id) ((id) & 0xffff)
#define MAKE_ID(id, index) ((id << 16) + (index))
#define MEM_BLOCK_AT_POOL(pool, index) ((char *) ((pool)->blocks) + (index) * ((pool)->block_size))

extern MEMORY_BLOCKS_POOL*
mem_blocks_pool_alloc(size_t block_size, size_t blocks_num) {
    MEMORY_BLOCKS_POOL *pool = malloc(sizeof(MEMORY_BLOCKS_POOL));

    pool->block_size = block_size;
    pool->blocks_num = blocks_num;
    pool->blocks_count = 0;
    pool->blocks = malloc(block_size * blocks_num);
    pool->ids = malloc(sizeof(int) * blocks_num);

    return pool;
}

extern void
mem_blocks_pool_free(MEMORY_BLOCKS_POOL *pool) {
    free(pool->blocks);
    pool->blocks = NULL;

    free(pool->ids);
    pool->ids = NULL;

    free(pool);
}

extern size_t
mem_blocks_pool_size(MEMORY_BLOCKS_POOL *pool) {
    return pool->blocks_count;
}

extern int
mem_blocks_pool_get_block_index(const MEMORY_BLOCKS_POOL *pool, int id) {
    int real_id = GET_ID(id);
    int index = GET_INDEX(id);

    if (pool->ids[index] == real_id)
        return index;

    return -1;
}

extern void *
mem_blocks_pool_get_block(const MEMORY_BLOCKS_POOL *pool, int id) {
    int index = mem_blocks_pool_get_block_index(pool, id);

    if (index != -1)
        return MEM_BLOCK_AT_POOL(pool, index);

    return NULL;
}

extern void *
mem_blocks_pool_block_at(const MEMORY_BLOCKS_POOL *pool, int index) {
    return MEM_BLOCK_AT_POOL(pool, index);
}

extern int
mem_blocks_pool_append_block(MEMORY_BLOCKS_POOL *pool, void *value) {
    static int object_id = 0;

    int index = pool->blocks_count;
    memcpy(MEM_BLOCK_AT_POOL(pool, index), value, pool->block_size);
    pool->blocks_count++;
    int id = object_id++; // TODO: make thread safe
    pool->ids[index] = id;

    return MAKE_ID(id, index);
}

extern void
mem_blocks_pool_remove_block(MEMORY_BLOCKS_POOL *pool, int id) {
    int index = mem_blocks_pool_get_block_index(pool, id);

    if (index == -1)
        return;

    memcpy(MEM_BLOCK_AT_POOL(pool, index), MEM_BLOCK_AT_POOL(pool, pool->blocks_count - 1), pool->block_size);
    pool->ids[index] = pool->ids[pool->blocks_count - 1];
    pool->blocks_count--;
}

/*void
MBP_test(void) {
    int values[] = {10, 20, 30, 40, 50};
    MEMORY_BLOCKS_POOL *pool;
    int id;

    pool = mem_blocks_pool_alloc(sizeof(int), countof(values));
    for (size_t i = 0; i < countof(values); i++) {
        int o = mem_blocks_pool_append_block(pool, &values[i]);

        if (i == 2)
            id = o;
    }

    for (int i = 0; i < MBP_size(pool); i++)
        printf("%d\n", *((int*)MBP_block_at(pool, i)));

    int v = -1;
    if (mem_blocks_pool_get_block(pool, id))
        v = *((int*)mem_blocks_pool_get_block(pool, id));
    printf("ID %#x VALUE=%d\n", id, v);

    mem_blocks_pool_remove_block(pool, id);

    for (int i = 0; i < MBP_size(pool); i++)
        printf("%d\n", *((int*)MBP_block_at(pool, i)));

    v = -1;
    if (mem_blocks_pool_get_block(pool, id))
        v = *((int*)mem_blocks_pool_get_block(pool, id));
    printf("ID %#x VALUE=%d\n", id, v);

    mem_blocks_pool_free(pool);

    exit(0);
}*/
