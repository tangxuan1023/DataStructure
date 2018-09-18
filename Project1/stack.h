#ifndef __STACK_H__
#define __STACK_H__
/* declaration */
typedef int STACK_TYPE;

void create_stack(size_t size);
void destroy_stack(void);

void push(STACK_TYPE value);
void pop(void);
STACK_TYPE top(void);

int is_empty(void);
int is_full(void);
#endif
