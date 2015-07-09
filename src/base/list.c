/*
 * Copyright (c) 2015 Poddubny Michael
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include "base/list.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#ifdef USE_MEMTRACK
#include <memtrack.h>
#endif

struct SListNode {
    struct SListNode    *next;
    void                *element;
};

struct SList {
    struct SListNode    *head;
    struct SListNode    *tail;

    size_t              size;
    size_t              element_size;
};

extern SLIST *
slist_alloc(size_t element_size) {
    SLIST *list = malloc(sizeof(SLIST));

    if (list == NULL)
        return NULL;

    list->element_size = element_size;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

extern void
slist_free(SLIST *list) {
    struct SListNode *node;

    while (list->head != NULL) {
        node = list->head;
        list->head = node->next;

        free(node->element);
        node->element = NULL;

        free(node);
        node = NULL;
    }

    free(list);
}

extern int
slist_prepend(SLIST *list, void *element) {
    struct SListNode *node = malloc(sizeof(struct SListNode));

    if(node == NULL)
        return 0;

    node->element = malloc(list->element_size);

    memcpy(node->element, element, list->element_size);

    node->next = list->head;
    list->head = node;

    if (list->tail == NULL)
        list->tail = list->head;

    return list->size++;
}

extern int
slist_append(SLIST *list, void *element) {
    struct SListNode *node = malloc(sizeof(struct SListNode));

    if (node == NULL)
        return 0;

    node->element = malloc(list->element_size);
    node->next = NULL;

    memcpy(node->element, element, list->element_size);

    if (list->head == NULL)
        list->head = list->tail = node;
    else {
        list->tail->next = node;
        list->tail = node;
    }

    return list->size++;
}

extern int
slist_remove(SLIST *list, void *element) {
    (void)list;
    (void)element;

    /* NOT IMPLEMENTED */

    return -1;
}

extern SLIST_ITERATOR
slist_head(SLIST *list, void *element) {
    struct SListNode *node = list->head;

    if (element)
        memcpy(element, node->element, list->element_size);

    return list->head;
}

extern SLIST_ITERATOR
slist_tail(SLIST *list, void *element) {
    struct SListNode *node = list->tail;

    if (element)
        memcpy(element, node->element, list->element_size);

    return list->tail;
}

extern SLIST_ITERATOR
slist_next(SLIST_ITERATOR iterator) {
    assert(iterator != NULL);

    return iterator->next;
}

extern SLIST_ITERATOR
slist_previous(SLIST *list, SLIST_ITERATOR iterator) {
    assert(iterator != NULL);

    struct SListNode *node = list->head;
    struct SListNode *prev;

    while (node != NULL) {
        prev = node;
        node = node->next;

        if (node == iterator)
            return prev;
    }

    return NULL;
}

extern void*
slist_get(SLIST_ITERATOR iterator) {
    return iterator->element;
}

extern void
slist_for_each(SLIST *list, LIST_ITERATOR_FUNC iterator_func) {
    assert(iterator_func != NULL);

    struct SListNode *node = list->head;

    bool quit = false;

    while((node != NULL) && !quit) {
        quit = iterator_func(node->element);
        node = node->next;
    }
}

// TODO: get more assets and valid ptr check
