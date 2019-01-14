#include <stdlib.h>
#include <assert.h>
#include "queue.h"
#ifdef _STATIC_QUEUE_

#define QUEUE_SIZE 100
#define ARRAY_SIZE (QUEUE_SIZE + 1)

static QUEUE_TYPE queue[ARRAY_SIZE];
static size_t front = 1;
static size_t rear  = 0;

void create_queue(size_t size)
{

}

void destroy_queue(void)
{

}

void insert(QUEUE_TYPE value)
{
	assert(!is_queue_full());
	rear = (rear + 1) % ARRAY_SIZE;
	queue[rear] = value;
}

void delete_(void)
{
	assert(!is_queue_empty());
	front = (front + 1) % ARRAY_SIZE;
}

QUEUE_TYPE first(void)
{
	assert(!is_queue_empty());
	return queue[front];
}

int is_queue_empty(void)
{
	return (rear + 1) % ARRAY_SIZE == front;
}

int is_queue_full(void)
{
	return (rear + 2) % ARRAY_SIZE == front;
}
#endif