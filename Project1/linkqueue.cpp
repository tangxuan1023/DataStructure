#include "linkqueue.h"
#include <stdio.h>

int InitQueue(LinkQueue *pQ)
{
	pQ->front = pQ->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!pQ->front) return -1;
	pQ->front->next = NULL;
	return 0;
}

int DestroyQueue(LinkQueue *pQ)
{
	while (pQ->front) {
		pQ->rear = pQ->front->next;
		free(pQ->front);
		pQ->front = pQ->rear;
	}
	return 0;
}

bool isQueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear) return true;
	return false;
}

size_t QueueLength(LinkQueue Q)
{
	size_t len = 0;
	if (isQueueEmpty(Q)) return 0;
	QueuePtr p = Q.front->next;
	do { 
		len++; 
		p = p->next;
	} while (p != NULL); 
	return len;
}

int GetHead(LinkQueue Q, QElemType *head)
{
	if (isQueueEmpty(Q)) return -1;
	QueuePtr p = Q.front->next;
	*head = p->data;
	return 0;
}

int EnQueue(LinkQueue *pQ, QElemType value)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) return -1;
	p->data = value;
	p->next = NULL;

	pQ->rear->next = p;
	pQ->rear = p;
	return 0;
}

int DeQueue(LinkQueue *pQ, QElemType *pValue)
{
	if (isQueueEmpty(*pQ)) return -1;
	QueuePtr p = pQ->front->next;
	*pValue = p->data;
	pQ->front->next = p->next;
	if (pQ->rear == p) pQ->rear = pQ->front;
	free(p);
	return 0;
}