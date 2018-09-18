#ifndef __LINK_QUEUE_H__
#define __LINK_QUEUE_H__
#include <stdlib.h>
typedef int QElemType;

typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
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
