#pragma once

#include <stddef.h>

typedef struct Stack STACK;

STACK* new_stack(size_t element_size, size_t elements);
void delete_stack(STACK *stack);
void push_stack(STACK *stack, void *element);
void *pop_stack(STACK *stack);
void *top_stack(STACK *stack);
int is_stack_empty(STACK *stack);
