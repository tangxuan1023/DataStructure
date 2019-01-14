#include <assert.h>
#include <stdlib.h>
#include "queue.h"
#ifdef _DYNAMIC_QUEUE_

static size_t queue_size;
static size_t array_size;

static QUEUE_TYPE *queue;
static size_t front = 1;
static size_t rear = 0;

void create_queue(size_t size)
{
	assert(queue_size == 0);
	queue_size = size;
	array_size = queue_size + 1;
	queue = (QUEUE_TYPE*)malloc(array_size * sizeof(QUEUE_TYPE));
	assert(queue != NULL);
}

void destroy_queue(void)
{
	assert(queue_size > 0);
	queue_size = 0;
	free(queue);
	queue = NULL;
}

void insert(QUEUE_TYPE value)
{
	assert(!is_queue_full());
	rear = (rear + 1) % array_size;
	queue[rear] = value;
}

void delete_(void)
{
	assert(!is_queue_empty());
	front = (front + 1) % array_size;
}

QUEUE_TYPE first(void)
{
	assert(!is_queue_empty());
	return queue[front];
}

int is_queue_empty(void)
{
	return (rear + 1) % array_size == front;
}

int is_queue_full(void)
{
	return (rear + 2) % array_size == front;
}

#endif