#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"
#include "sqstack.h"
#include "linkqueue.h"

#pragma warning(disable:4996)

void testq()
{
	LinkQueue Q;
	InitQueue(&Q);
	QElemType p = 0;
	printf("len = %d\n", QueueLength(Q));
	EnQueue(&Q, 12);
	printf("len = %d\n", QueueLength(Q));
	EnQueue(&Q, 10);
	GetHead(Q, &p);
	printf("p = %d\n", p);
	printf("len = %d\n", QueueLength(Q));
	DeQueue(&Q, &p);
	printf("pOut = %d\n", p);
	GetHead(Q, &p);
	printf("p = %d\n", p);
	printf("len = %d\n", QueueLength(Q));
	DestroyQueue(&Q);
}

void tests()
{
	SqStack S;
	InitStack(&S);
	SElemType value = 0;
	printf("len= %d\n", StackLength(S));
	Push(&S, 13);
	printf("len= %d\n", StackLength(S));
	Push(&S, 14);
	Push(&S, 15);
	printf("len= %d\n", StackLength(S));
	Pop(&S);
	printf("len= %d\n", StackLength(S));
	Pop(&S);
	Pop(&S);
	printf("pop= %d\n", Pop(&S));
	printf("len= %d\n", StackLength(S));
}


int PrintElement(char e)
{
	printf(" %c ", e);
	return true;
}

BiTree insert(BiTree T, int value)
{
	// if the tree is empty, return a new, single node 
	if (!T) {
		return(CreateNewNode(value));
	}
	else {
		// otherwise, recur down the tree 
		if (value <= T->value) 
			T->lchild = insert(T->lchild, value);
		else 
			T->rchild = insert(T->rchild, value);

		return(T); // return the (unchanged) node pointer 
	}
}

size_t SizeOfBiTree(BiTree T)
{
	if (!T) return 0;
	return (SizeOfBiTree(T->lchild) + SizeOfBiTree(T->rchild) + 1);
}

size_t maxBiTreeDepth(BiTree T)
{
	if (!T) return 0;
	size_t ldepth = maxBiTreeDepth(T->lchild);
	size_t rdepth = maxBiTreeDepth(T->rchild);
	return (ldepth > rdepth ? ldepth : rdepth) + 1;
}

void mirrorOfBiTree(BiTree T)
{
	if (!T) return;
	mirrorOfBiTree(T->lchild);
	mirrorOfBiTree(T->rchild);
	BiTree tmp = T->lchild;
	T->lchild = T->rchild;
	T->rchild = tmp;
}

void test_tree1()
{
	/*BiTree tree = CreateNewNode('4');
	BiTree pl, pr;
	tree->lchild = CreateNewNode('2');
	tree->rchild = CreateNewNode('5');
	tree->lchild->lchild = CreateNewNode('1');
	tree->lchild->rchild = CreateNewNode('3');*/

	// use insert
	BiTree tree = NULL;
	tree = insert(tree, 'A');
	tree = insert(tree, 'B');
	tree = insert(tree, 'C');

	InOrderTraverse(tree, &PrintElement, NULL);
	mirrorOfBiTree(tree);
	printf("\n");
	InOrderTraverse(tree, &PrintElement, NULL);
	printf("\nmaxDepth = %u\n", maxBiTreeDepth(tree));
}

int test_tree()
{
    /* Constructed binary tree is
        10
       /   \
      8	     2
     / \    /
    3   5  2
    */
    BiTNode*root = CreateNewNode(10);
    root->lchild = CreateNewNode(8);
    root->rchild = CreateNewNode(2);
    root->lchild->lchild = CreateNewNode(3);
    root->lchild->rchild = CreateNewNode(5);
    root->rchild->lchild = CreateNewNode(2);
    PreOrderIterative(root);
    return 0;
}

int main()
{
    test_tree();
	getchar();
	return 0;
}