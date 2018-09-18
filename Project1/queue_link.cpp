
/*
#include <stdlib.h>
#include <assert.h>

#include "queue.h"

typedef struct QUEUE_NODE {
	QUEUE_TYPE value;
	struct QUEUE_NODE  *next;
}QueueNode;

static size_t front = 1;
static size_t rear = 0;
static QueueNode *queue;

void create_queue(size_t size)
{

}

void destroy_queue(void)
{
	while (!is_empty()) {
		delete_();
	}
}
*/
//TODO: implement the details

/*
void insert(QUEUE_TYPE value)
{
	assert(!is_full());
	rear = (rear + 1) % array_size;
	queue[rear] = value;
}

void delete_(void)
{
	assert(!is_empty());
	front = (front + 1) % array_size;
}

QUEUE_TYPE first(void)
{
	assert(!is_empty());
	return queue[front];
}

int is_empty(void)
{
	return (rear + 1) % array_size == front;
}

int is_full(void)
{
	return (rear + 2) % array_size == front;
}
*/