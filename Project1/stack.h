#ifndef __STACK_H__
#define __STACK_H__
/* declaration */
typedef int STACK_TYPE;

void create_stack(size_t size);
void destroy_stack(void);

void push(STACK_TYPE value);
void pop(void);
STACK_TYPE top(void);

int is_stack_empty(void);
int is_stack_full(void);

#define USE_STATIC_VER (1 << 0)
#define USE_LINK_VER (1 << 1)
#define USE_DYNAMIC_VER (1 << 2)

#define SELECT_MACK (1 << 2)

#if USE_STATIC_VER & SELECT_MACK
#define _STATIC_STACK_
#elif USE_LINK_VER & SELECT_MACK
#define _LINK_STACK_
#elif USE_DYNAMIC_VER & SELECT_MACK
#define _DYNAMIC_STACK_
#endif

#endif
