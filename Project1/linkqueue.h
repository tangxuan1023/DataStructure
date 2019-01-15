#ifndef __LINK_QUEUE_H__
#define __LINK_QUEUE_H__
#include <stdlib.h>

#define TREE_USED_QUEUE

#ifdef TREE_USED_QUEUE
struct BiTNode;
typedef BiTNode* QElemType;
#else
typedef int QElemType;
#endif

typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct LinkQueue {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

int InitQueue(LinkQueue *pQ);
int DestroyQueue(LinkQueue *pQ);
bool isQueueEmpty(LinkQueue Q);
size_t QueueLength(LinkQueue Q);
int GetHead(LinkQueue Q, QElemType *head);
int EnQueue(LinkQueue *pQ, QElemType value);
int DeQueue(LinkQueue *pQ, QElemType *pValue);

#endif // __LINK_QUEUE_H__
