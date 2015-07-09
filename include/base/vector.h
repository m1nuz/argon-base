#pragma once

#include <stddef.h>
#include <stdbool.h>

//#define VDBG

struct Vector {
#ifdef VDBG
    int    elements[100];
#else
    void    *elements;
#endif
    size_t  size;
    size_t  capacity;
    size_t  element_size;
    void (*freefn)(void *);
};

typedef struct Vector *VECTOR;
typedef bool (*VECTOR_ITERATOR_FUNC)(VECTOR, void *);

VECTOR vector_new(size_t hint, size_t element_size, void (*freefn)(void *));
void vector_free(struct Vector *v);
size_t vector_size(struct Vector *v);
bool vector_empty(struct Vector *v);
bool vector_clear(struct Vector *v);
void* vector_at(struct Vector *v, size_t index);
bool vector_get(struct Vector *v, size_t index, void *elem);
bool vector_append(struct Vector *v, void *elem);
bool vector_insert(struct Vector *v, size_t index, void *elem);
bool vector_remove(struct Vector *v, size_t index, void *elem);
void vector_foreach(struct Vector *v, VECTOR_ITERATOR_FUNC each);
