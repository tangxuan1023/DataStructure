#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <stdlib.h>

typedef int QUEUE_TYPE;

void create_queue(size_t size);
void destroy_queue(void);
void insert(QUEUE_TYPE value);
void delete_(void);
QUEUE_TYPE first(void);
int is_queue_empty(void);
int is_queue_full(void);


#define USE_STATIC_VER (1 << 0)
#define USE_LINK_VER (1 << 1)
#define USE_DYNAMIC_VER (1 << 2)

#define SELECT_MACK (1 << 1)

#if USE_STATIC_VER & SELECT_MACK
#define _STATIC_QUEUE_
#elif USE_LINK_VER & SELECT_MACK
#define _LINK_QUEUE_
#elif USE_DYNAMIC_VER & SELECT_MACK
#define _DYNAMIC_QUEUE_
#endif

#endif