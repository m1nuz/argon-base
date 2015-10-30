#include <stdlib.h>
#include <assert.h>

#ifdef USE_MEMTRACK
#include <memtrack.h>
#endif

#include "base/objects_pool.h"

struct ObjectsPool {
    size_t      capacity;
    size_t      object_size;
    size_t      num_objects;
    void        *objects;
    INDEX       *indices;
    uint32_t    *ids;
    uint16_t    freelist_enqueue;
    uint16_t    freelist_dequeue;
    uint32_t    start_id;
};

#define SINGLE_MALLOC

OBJECTS_POOL*
new_objects_pool(OBJECTS_POOL_INFO info) {
    assert(info.capacity < MAX_OBJECTS);
#ifdef SINGLE_MALLOC
    size_t sz = sizeof(OBJECTS_POOL) +
            info.object_size * info.capacity +
            sizeof(INDEX) * info.capacity +
            sizeof(uint32_t) * info.capacity;
    OBJECTS_POOL *p = malloc(sz);
#else
    OBJECTS_POOL *p = malloc(sizeof(OBJECTS_POOL));
#endif // NO SINGLE_MALLOC
    p->capacity = info.capacity;
    p->object_size = info.object_size;
    p->num_objects = 0;
#ifdef SINGLE_MALLOC
    p->objects = (void*)((char*)p + sizeof(OBJECTS_POOL));
    p->indices = (void*)((char*)p->objects + p->object_size * p->capacity);
    p->ids = (void*)((char*)p->indices + sizeof(INDEX) * p->capacity);
#else
    p->objects = malloc(p->object_size * p->capacity);
    p->indices = malloc(sizeof(INDEX) * p->capacity);
    p->ids = malloc(sizeof(uint32_t) * p->capacity);
#endif // NO SINGLE_MALLOC
    p->freelist_dequeue = 0;
    p->freelist_enqueue = p->capacity - 1;
    p->start_id = info.start_with_id;

    for (size_t i = 0; i < p->capacity; i++) {
        p->indices[i].id = i;
        p->indices[i].next = i + 1;
    }

    memset(p->ids, 0, sizeof(uint32_t) * p->capacity);

    return p;
}

void
free_objects_pool(OBJECTS_POOL *p) {
#ifndef SINGLE_MALLOC
    free(p->objects);
    free(p->indices);
    free(p->ids);
#endif // NO #SINGLE_MALLOC
    free(p);
}

bool
in_objects_pool(const OBJECTS_POOL *p, uint32_t id) {
    INDEX *in = &p->indices[id & INDEX_MASK];
    return (in->id == id) && (in->index != UINT16_MAX);
}

void*
lookup_objects_pool(const OBJECTS_POOL *p, uint32_t id) {
    return (char*)p->objects + p->indices[id & INDEX_MASK].index * p->object_size;
}

uint32_t
objects_pool_append(OBJECTS_POOL *p) {
    INDEX *in = &p->indices[p->freelist_dequeue];
    p->freelist_dequeue = in->next;
    in->id += p->start_id;
    in->index = p->num_objects++;
    //void *obj = (char*)p->objects + in->index * p->object_size;
    p->ids[in->index] = in->id;

    return in->id;
}

void
objects_pool_remove(OBJECTS_POOL *p, uint32_t id) {
    INDEX *in = &p->indices[id & INDEX_MASK];

    p->num_objects--;
    void *obj = (char*)p->objects + in->index * p->object_size;
    void *mov_obj = (char*)p->objects + p->object_size * p->num_objects;
    uint32_t o_id = p->ids[p->num_objects];

    memcpy(obj, mov_obj, p->object_size);

    p->indices[o_id & INDEX_MASK].index = in->index;
    in->index = UINT16_MAX;

    p->indices[p->freelist_enqueue].next = id & INDEX_MASK;
    p->freelist_enqueue = id & INDEX_MASK;
}

size_t
objects_pool_size(const OBJECTS_POOL *p) {
    return p->num_objects;
}

void*
objects_pool_at(const OBJECTS_POOL *p, size_t index) {
    return (void*)((char*)p->objects + index * p->object_size);
}

/*#include <base/objects_pool.h>

static void
test(void) {
    int n = 10;
    OBJECTS_POOL *p = new_objects_pool((POOL_INFO){.capacity = 10, .object_size = sizeof(int), .start_with_id = 1000});

    for (int i = 0; i < n; i++) {
        int id = objects_pool_append(p);
        int *v = lookup_objects_pool(p, id);
        *v = rand() % 10 + 10;

        printf("id=%u v=%d\n", id, *v);
    }

    objects_pool_remove(p, 5);
    objects_pool_remove(p, 7);
    puts("");

    for (int i = 0; i < n; i++) {
        if (in_objects_pool(p, i))
            printf("id=%d v=%d\n", i, *(int*)lookup_objects_pool(p, i));
    }

    free_objects_pool(p);
}*/
