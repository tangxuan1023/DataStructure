#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include "sqstack.h"
#pragma warning(disable:4996)

BiTNode* CreateNewNode(TElemType value)
{
    BiTNode* treePtr = (BiTNode*)malloc(sizeof(BiTNode));
	if (!treePtr) return NULL;
	treePtr->value = value;
	treePtr->lchild = NULL;
	treePtr->rchild = NULL;

	return treePtr;
}


BiTree CreateBiTree()
{
	TElemType elem;
	BiTree T;
	scanf("%c", &elem);
	if (elem == '#') T = NULL;
	else {
		T = (BiTree)malloc(sizeof(BiTNode));
		T->value = elem;
		T->lchild = CreateBiTree();
		T->rchild = CreateBiTree();
	}
	return T;
}


void InsertTreeChild(BiTree T, BiTNode *pNode, int LR, BiTree newTree)
{

}


//œ»–Ú
bool PreOrderTraverse(BiTree T, Visit visit, void *pUserData)
{
	if (T)
	{
		if (visit(T))
			if (PreOrderTraverse((BiTree)T->lchild, visit, pUserData))
				if (PreOrderTraverse((BiTree)T->rchild, visit, pUserData))
					return true;
		return false;
	}
	else
		return true;
}


// ÷––Ú
bool InOrderTraverse(BiTree T, Visit visit, void *pUserData)
{
	if (T)
	{
		if (InOrderTraverse((BiTree)T->lchild, visit, pUserData))
			if (visit(T))
				if (InOrderTraverse((BiTree)T->rchild, visit, pUserData))
					return true;
		return false;
	}
	else
		return true;
}


// ∫Û–Ú
bool PostOrderTraverse(BiTree T, Visit visit, void *pUserData)
{
	if (T) {
		if (PostOrderTraverse((BiTree)T->lchild, visit, pUserData))
			if (PostOrderTraverse((BiTree)T->rchild, visit, pUserData))
				if (visit(T))
					return true;
		return false;
	}
	else
		return true;
}


// ≤„–Ú
bool LevelOrderTraverse(BiTree T, Visit visit, void *pUserData)
{
    // TODO: finish it
	return true;
}

// ∑«µ›πÈ
#if !USE_MY_STACK
#include <stdlib.h> 
#include <stdio.h> 
#include <iostream> 
#include <stack> 

using namespace std;
// An iterative process to print preorder traversal of Binary tree 
void PreOrderIterative(BiTree root)
{
    // Base Case 
    if (root == NULL)
        return;

    // Create an empty stack and push root to it 
    std::stack<BiTree> nodeStack;
    nodeStack.push(root);

    /* Pop all items one by one. Do following for every popped item
    a) print it
    b) push its right child
    c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (nodeStack.empty() == false)
    {
        // Pop the top item from stack and print it 
        BiTNode *node = nodeStack.top();
        printf("%d ", node->value);  // output, it's can use callback to improve
        nodeStack.pop();

        // Push right and left children of the popped node to stack 
        if (node->rchild)
            nodeStack.push(node->rchild);
        if (node->lchild)
            nodeStack.push(node->lchild);
    }
}

void PostOrderIterative(BiTree root)
{
    if (root == NULL)
        return;

    // Create an empty stack and push root to it 
    std::stack<BiTree> nodeStack;
    nodeStack.push(root);
    std::stack<BiTree> tmpStack;
    while (nodeStack.empty() == false) {
        /* Note that right child is pushed first so that left is processed first */
        BiTNode *node = nodeStack.top();
        nodeStack.pop();
        tmpStack.push(node);
        if (node->lchild) nodeStack.push(node->lchild);
        if (node->rchild) nodeStack.push(node->rchild);
    }

    while (tmpStack.empty() == false) {
        BiTNode *node = tmpStack.top();
        printf("%d ", node->value);
        tmpStack.pop();
    }
}
#else

void PostOrderIterative(BiTNode *root, SqStack *nodeStack, Visit visit)
{
    Push(nodeStack, root);
    SqStack tmpStack;
    int res = InitStack(&tmpStack);
    while (/*printf("%p %p\n", nodeStack->top, nodeStack->base) && */!isStackEmpty(*nodeStack)) {
        /* Note that right child is pushed first so that left is processed first */
        BiTNode *node;
        GetTop(*nodeStack, &node);
        Pop(nodeStack);
        Push(&tmpStack, node);
        if (node->lchild) Push(nodeStack, node->lchild);
        if (node->rchild) Push(nodeStack, node->rchild);
    }

    while (!isStackEmpty(tmpStack)) {
        BiTNode *node;
        GetTop(tmpStack, &node);
        Pop(&tmpStack);
        visit(node);
    }
    // free tmp stack
    res = DestroyStack(&tmpStack);
}

void PreOrderIterative(BiTNode *root, SqStack *nodeStack, Visit visit)
{
    Push(nodeStack, root);
    while (/*printf("%p %p\n", nodeStack->top, nodeStack->base) && */!isStackEmpty(*nodeStack)) {
        /* Note that right child is pushed first so that left is processed first */
        BiTNode *node;
        GetTop(*nodeStack, &node);
        Pop(nodeStack);
        visit(node);
        if (node->rchild) Push(nodeStack, node->rchild);
        if (node->lchild) Push(nodeStack, node->lchild);
    }
}
#endif