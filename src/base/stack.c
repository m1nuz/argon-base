#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifdef USE_MEMTRACK
#include <memtrack.h>
#endif

#include "base/stack.h"

#define ONE_MEM_ALLOC

struct Stack {
    void        *elements;
    size_t      element_size;
    size_t      elements_count;
    int         top;
};

extern STACK*
new_stack(size_t element_size, size_t elements) {
    assert(element_size > 0);
    assert(elements > 0);

#ifdef ONE_MEM_ALLOC
    struct Stack *stack = malloc(sizeof(struct Stack) + element_size * elements);
    stack->elements = (char*)stack + sizeof(struct Stack);
#else
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->elements = malloc(element_size * elements);
#endif
    stack->element_size = element_size;
    stack->elements_count = elements;
    stack->top = -1;

    return stack;
}

extern void
delete_stack(STACK *stack) {
#ifndef ONE_MEM_ALLOC
    free(stack->elements);
#endif
    free(stack);
}

extern void
push_stack(STACK *stack, void *element) {
    assert(stack != NULL);

    stack->top++;

    memcpy((char*)stack->elements + stack->top * stack->element_size, element, stack->element_size);
}

extern void*
pop_stack(STACK *stack) {
    assert(stack != NULL);

    if (stack->top == -1)
        return NULL;

    void *element = (char*)stack->elements + stack->top * stack->element_size;

    stack->top--;

    return element;
}

extern void*
top_stack(STACK *stack) {
    assert(stack != NULL);

    if (stack->top == -1)
        return NULL;

    return (char*)stack->elements + stack->top * stack->element_size;
}

extern int
is_stack_empty(STACK *stack) {
    assert(stack != NULL);

    if (stack->top == -1)
        return 1;

    return 0;
}
