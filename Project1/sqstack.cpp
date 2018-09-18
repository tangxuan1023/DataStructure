#include "sqstack.h"
#include <stdlib.h>
#include <stdio.h>

int InitStack(SqStack *pS)
{
	pS->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!pS->base) return -1;
	pS->top = pS->base;
	pS->stacksize = STACK_INIT_SIZE;
	return 0;
}

//int InitStack(SqStack &S)
//{
//	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
//	if (!S.base) return -1;
//	S.top = S.base;
//	S.stacksize = STACK_INIT_SIZE;
//	return 0;
//}

int GetTop(SqStack S, SElemType *top)
{
	//if (S.base == S.top) return -1;
	if (isStackEmpty(S)) return -1;
	*top = *(S.top - 1);
	return 0;
}

int Push(SqStack *pS, SElemType value)
{
	if (pS->top - pS->base >= pS->stacksize) {
		pS->base = (SElemType*)realloc(pS->base, (pS->stacksize + STACK_INCREMENT) * sizeof(SElemType));
		if (!pS->base) return -1;

		pS->top = pS->base + pS->stacksize;
		pS->stacksize += STACK_INCREMENT;
	}

	*pS->top++ = value;
	return 0;
}

int Pop(SqStack *pS, SElemType *pValue)
{
	//if (pS->base == pS->top) return -1;
	if (isStackEmpty(*pS)) return -1;
	*pValue = * --pS->top;
	return 0;
}

bool isStackEmpty(SqStack S)
{
	if (S.top == S.base) return true;
	return false;
}

int DestroyStack(SqStack *pS) 
{
	free(pS->base);
	return 0;
}

size_t StackLength(SqStack S)
{
	size_t len = 0;
	while (!isStackEmpty(S)) {
		len++;
		--S.top;
	}

	return len;
}