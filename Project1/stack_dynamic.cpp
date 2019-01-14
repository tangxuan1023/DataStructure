#include <assert.h>
#include <stdlib.h>
#include "stack.h"

#ifdef _DYNAMIC_STACK_
/* implement */
static STACK_TYPE *stack;
static size_t stack_size;
static int top_element = -1;

void create_stack(size_t size)
{
	assert(stack_size == 0);
	stack_size = size;
	stack = (STACK_TYPE*)malloc(stack_size * sizeof(STACK_TYPE));
	assert(stack != NULL);
}

void destroy_stack(void)
{
	assert(stack_size > 0);
	stack_size = 0;
	free(stack);
	stack = NULL;
}

void push(STACK_TYPE value)
{
	assert(!is_stack_full());
	top_element += 1;
	stack[top_element] = value;
}

void pop(void)
{
	assert(!is_stack_empty());
	top_element -= 1;
}

STACK_TYPE top(void)
{
	assert(!is_stack_empty());
	return stack[top_element];
}

int is_stack_empty(void)
{
	assert(stack_size > 0);
	return top_element == -1;
}

int is_stack_full(void)
{
	assert(stack_size > 0);
	return top_element == stack_size - 1;
}
#endif