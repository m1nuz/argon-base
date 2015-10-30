#pragma once

#include <stddef.h>
#include <stdint.h>

typedef struct BlockPool BLOCK_POOL;

BLOCK_POOL* new_block_pool(size_t num, size_t block_size);
void free_block_pool(BLOCK_POOL *pool);

void* block_alloc(BLOCK_POOL *pool);
void block_free(BLOCK_POOL *pool, void *obj);
