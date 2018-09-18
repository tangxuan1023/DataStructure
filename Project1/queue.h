#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <stdlib.h>

typedef int QUEUE_TYPE;

void create_queue(size_t size);
void destroy_queue(void);
void insert(QUEUE_TYPE value);
void delete_(void);
QUEUE_TYPE first(void);
int is_empty(void);
int is_full(void);

#endif