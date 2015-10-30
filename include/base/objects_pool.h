#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_OBJECTS         (64 * 1024)
#define INDEX_MASK          0xffff

typedef struct Index {
    uint32_t id;
    uint16_t index;
    uint16_t next;
} INDEX;

typedef struct ObjectsPool OBJECTS_POOL;

typedef struct PoolInfo {
    size_t      capacity;
    size_t      object_size;
    uint32_t    start_with_id;
} OBJECTS_POOL_INFO;

OBJECTS_POOL* new_objects_pool(OBJECTS_POOL_INFO info);
void free_objects_pool(OBJECTS_POOL *p);

bool in_objects_pool(const OBJECTS_POOL *p, uint32_t id);
void* lookup_objects_pool(const OBJECTS_POOL *p, uint32_t id);
uint32_t objects_pool_append(OBJECTS_POOL *p);
void objects_pool_remove(OBJECTS_POOL *p, uint32_t id);

size_t objects_pool_size(const OBJECTS_POOL *p);
void* objects_pool_at(const OBJECTS_POOL *p, size_t index);
