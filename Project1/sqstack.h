#ifndef __STACK_H__
#define __STACK_H__

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

typedef int SElemType;

typedef struct SqStack {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

int InitStack(SqStack *pS);
//int InitStack(SqStack &S);

int GetTop(SqStack S, SElemType *top);
int Push(SqStack *pS, SElemType value);
int Pop(SqStack *pS/*, SElemType *pValue*/);
bool isStackEmpty(SqStack S);
int DestroyStack(SqStack *pS);
size_t StackLength(SqStack S);


#endif // __STACK_H__