#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "list.h"

typedef struct stack stack;

stack *stack_create(void);

void stack_delete(stack *);

void stack_push(stack *, int);

int stack_pop(stack *);

int stack_peek(stack *);

int stack_size(stack *);

int stack_empty(stack *);

#endif