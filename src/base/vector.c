#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifdef USE_MEMTRACK
#include <memtrack.h>
#endif

#include "base/vector.h"

#define VECTOR_BASE_CAPACITY 10
#define VECTOR_EXPAND_RATIO 2

#define ELEM(v, i) ((char *) ((v)->elements) + (i) * ((v)->element_size))

static void default_vector_free(void *element) {
    (void)element;
}

static bool vector_brim(struct Vector *v) {
    assert(v != NULL);

    return v->size == v->capacity ? true : false;
}

static bool vector_grow(struct Vector *v) {
    assert(v != NULL);

    size_t more = v->size * VECTOR_EXPAND_RATIO;
#ifndef VDBG
    void *temp = realloc(v->elements, more * v->element_size);

    if (!temp)
        return false;

    v->elements = temp;
#endif
    v->capacity = more;

    return true;
}

VECTOR vector_new(size_t hint, size_t element_size, void (*freefn)(void *)) {
    struct Vector *v = malloc(sizeof(struct Vector));

    if (!v)
        return NULL;

    v->capacity = hint ? hint : VECTOR_BASE_CAPACITY;
    v->freefn = freefn ? freefn : default_vector_free;
    v->size = 0;
    v->element_size = element_size ? element_size : 1;
#ifndef VDBG
    v->elements = malloc(v->capacity * element_size);
#endif

    return v;
}

void vector_free(struct Vector *v) {
    assert(v != NULL);

    for (size_t i = 0; i < v->size; i++)
        v->freefn(ELEM(v, i));
#ifndef VDBG
    free(v->elements);
#endif
    free(v);
}

size_t vector_size(struct Vector *v) {
    assert(v != NULL);

    return v ? v->size : 0;
}

bool vector_empty(struct Vector *v) {
    assert(v != NULL);

    return v ? (v->size == 0) : true;
}

bool vector_clear(struct Vector *v) {
    if (!v)
        return false;

    size_t sz = v->size;
    for (size_t i = 0; i < sz; i++)
        v->freefn(ELEM(v, i));

    v->size = 0;

    return true;
}

void* vector_at(struct Vector *v, size_t index) {
    assert(v != NULL);
    assert(index < v->size);

    return v ? ELEM(v, index) : NULL; // unsafe access
}

bool vector_get(struct Vector *v, size_t index, void *elem) {
    assert(v != NULL);
    assert(elem != NULL);

    if (!v || (index >= v->size) || !elem)
        return false;

    memcpy(elem, ELEM(v, index), v->element_size);

    return true;
}

bool vector_append(struct Vector *v, void *elem) {
    assert(v != NULL);

    if (!v)
        return false;

    if (vector_brim(v) && !vector_grow(v))
        return false;

    if (elem) {
        memcpy(ELEM(v, v->size++), elem, v->element_size);
        return true;
    }

    return false;
}

bool vector_insert(struct Vector *v, size_t index, void *elem) {
    if (!v || index >= v->size)
        return false;

    if (vector_brim(v) && !vector_grow(v))
        return false;

    memmove(ELEM(v, index + 1), ELEM(v, index), ((v->size++ - index) * v->element_size));
    memcpy(ELEM(v, index), elem, v->element_size);

    return true;
}

bool vector_remove(struct Vector *v, size_t index, void *elem) {
    if (!v || index >= v->size)
        return false;

    if (elem)
        memcpy(elem, ELEM(v, index), v->element_size);
    else
        v->freefn(*(void **)(ELEM(v, index)));

    memmove(ELEM(v, index), ELEM(v, index + 1), ((v->size-- - index) * v->element_size));

    return true;
}

void vector_foreach(struct Vector *v, VECTOR_ITERATOR_FUNC each) {
    for (size_t i = 0; i < v->size; i++)
        each(v, ELEM(v, i));
}


// for test
/*void print_int(VECTOR *self, void *elem) {
    int b = *(int*)elem;
    printf("%d ", b);
}

void test2() {
    VECTOR *v = vector_new(5, sizeof(int), NULL);

    for (int i = 0; i < 5; i++)
    {
        int a = i;
        vector_append(v, &a);

        int b = *(int*)vector_at(v, i);
        printf("%d ", b);
    }
    printf("\n");

    int a = 8;
    vector_insert(v, 2, &a);
    a = 7;
    vector_insert(v, 2, &a);

    for (int i = 0; i < vector_size(v); i++) {
        int b = 0;
        vector_get(v, i, &b);
        printf("%d ", b);
    }
    printf("\n");

    vector_foreach(v, print_int);
    printf("\n");

    vector_clear(v);

    printf("vector %s\n", vector_empty(v) ? "empty" : "not empty");

    for (int i = 0; i < 10; i++) {
        vector_append(v, &i);
    }

    vector_remove(v, 1, &a);
    vector_remove(v, 6, NULL);

    vector_foreach(v, print_int);
    printf("\n");

    vector_free(v);
    exit(0);
}*/
