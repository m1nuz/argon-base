#pragma once

#include <stddef.h>

typedef struct MemoryBlocksPool MEMORY_BLOCKS_POOL;

#define MBP_alloc(bsz, bnum) mem_blocks_pool_alloc(bsz, bnum)
#define MBP_free(p) mem_blocks_pool_free(p)
#define MBP_size(p) mem_blocks_pool_size(p)
#define MBP_block_index(p, id) mem_blocks_pool_get_block_index(p, id)
#define MBP_block(p, id) mem_blocks_pool_get_block(p, id)
#define MBP_block_at(p, index) mem_blocks_pool_block_at(p, index)
#define MBP_append_block(p, blk_ptr) mem_blocks_pool_append_block(p, blk_ptr)
#define MBP_remove_block(p, id) mem_blocks_pool_remove_block(p, id)

/* managment */
MEMORY_BLOCKS_POOL *mem_blocks_pool_alloc(size_t block_size, size_t blocks_num);
void mem_blocks_pool_free(MEMORY_BLOCKS_POOL *pool);
size_t mem_blocks_pool_size(MEMORY_BLOCKS_POOL *pool);

/* access to block */
int mem_blocks_pool_get_block_index(const MEMORY_BLOCKS_POOL *pool, int id);
void *mem_blocks_pool_get_block(const MEMORY_BLOCKS_POOL *pool, int id);
void *mem_blocks_pool_block_at(const MEMORY_BLOCKS_POOL *pool, int index);

/* blocks operation */
int mem_blocks_pool_append_block(MEMORY_BLOCKS_POOL *pool, void *value);
void mem_blocks_pool_remove_block(MEMORY_BLOCKS_POOL *pool, int id);
