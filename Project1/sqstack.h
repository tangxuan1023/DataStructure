#ifndef __STACK_H__
#define __STACK_H__

#define TREE_USED_STACK

#ifdef TREE_USED_STACK
struct BiTNode;
typedef BiTNode* SElemType;
#else
typedef int SElemType;
#endif
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