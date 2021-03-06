#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include "sqstack.h"
#include "linkqueue.h"
#pragma warning(disable:4996)

static void visitGivenLevel(BiTree T, int level, Visit visit);
static int height(BiTree T);

BiTNode* CreateNewNode(TElemType value)
{
    BiTNode* treePtr = (BiTNode*)malloc(sizeof(BiTNode));
	if (!treePtr) return NULL;
	treePtr->value = value;
	treePtr->lchild = NULL;
	treePtr->rchild = NULL;

	return treePtr;
}

void InsertTreeChild(BiTree T, BiTNode *pNode, int LR, BiTree newTree)
{

}

int BiTreeDepth(BiTree T)
{
    return height(T);
}


//����
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


// ����
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


// ����
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


// ����
bool LevelOrderTraverse(BiTree T, Visit visit, void *pUserData)
{
    int h = height(T);
    int i;
    for (i = 1; i <= h; i++)
        visitGivenLevel(T, i, visit);
	return true;
}

/* Print nodes at a given level */
void visitGivenLevel(BiTree T, int level, Visit visit)
{
    if (T == NULL)
        return;
    if (level == 1)
        visit(T);
    else if (level > 1) {
        visitGivenLevel(T->lchild, level - 1, visit);
        visitGivenLevel(T->rchild, level - 1, visit);
    }
}

/* Compute the "height" of a tree -- the number of
nodes along the longest path from the root node
down to the farthest leaf node.*/
int height(BiTree T)
{
    if (T == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(T->lchild);
        int rheight = height(T->rchild);

        /* use the larger one */
        if (lheight > rheight)
            return(lheight + 1);
        else return(rheight + 1);
    }
}


//////////////////////////////////////////////////////////////////
// �ǵݹ�
#if !USE_MY_STACK
#include <stdlib.h> 
#include <stdio.h> 
#include <iostream> 
#include <stack> 
#include <queue>

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
        printf("%d ", node->value); // output, it's can use callback to improve
        tmpStack.pop();
    }
}

void PostOrderIterative2(BiTree root)
{
    // Check for empty tree 
    if (root == NULL)
        return;

    BiTNode *p = root;
    std::stack<BiTree> nodeStack;
    do {
        // Move to leftmost node 
        while (p != NULL) {
            // Push root's right child and then root to stack. 
            if (p->rchild) nodeStack.push(p->rchild);
            nodeStack.push(p);

            // Set root as root's left child   
            p = p->lchild;
        } // after while, p == NULL

        // Pop an item from stack and set it as root     
        p = nodeStack.top();
        nodeStack.pop();

        // If the popped item has a right child and the right child is not 
        // processed yet, then make sure right child is processed before root 
        if (p->rchild && (!nodeStack.empty() && nodeStack.top() == p->rchild)) {
            nodeStack.pop();  // remove right child from stack 
            nodeStack.push(p);  // push root back to stack 
            p = p->rchild; // change root so that the right  
                           // child is processed next 
        }
        else { // Else print root's data and set root as NULL 
            printf("%d ", p->value); // output, it's can use callback to improve
            p = NULL;
        }
    } while (!nodeStack.empty());
}

void InOrderIterative(BiTree root)
{
    if (root == NULL)
        return;
    std::stack<BiTree> nodeStack;
    BiTNode *curr = root;

    while(curr != NULL || nodeStack.empty() == false){
        while (curr != NULL) {
            nodeStack.push(curr);
            curr = curr->lchild;
        }

        curr = nodeStack.top();
        nodeStack.pop();
        printf("%d ", curr->value); // output, it's can use callback to improve
        curr = curr->rchild;

    } /* end of while */
}

void InOrderIterative2(BiTree root)
{
    if (root == NULL)
        return;
    BiTNode *p = root;
    std::stack<BiTree> nodeStack;
    while (p != NULL) {
        while (p != NULL) {
            if (p->rchild) nodeStack.push(p->rchild);
            nodeStack.push(p);
            p = p->lchild;
        }  // after while, p == NULL

        p = nodeStack.top();
        nodeStack.pop();
        while (!nodeStack.empty() && p->rchild == NULL) {
            printf("%d ", p->value);   // output, it's can use callback to improve
            p = nodeStack.top();
            nodeStack.pop();
        }
        printf("%d ", p->value);   // output, it's can use callback to improve

        if (!nodeStack.empty()) {
            p = nodeStack.top();
            nodeStack.pop();
        }
        else
            p = NULL;
    }
}

void LevelOrderIterative(BiTree root)
{
    if (root == NULL)
        return;
    std::queue<BiTree> nodeQueue;
    nodeQueue.push(root);
    while (!nodeQueue.empty()) {
        BiTNode *node = nodeQueue.front();
        nodeQueue.pop();
        
        printf("%d ", node->value); // output, it's can use callback to improve
        if (node->lchild) nodeQueue.push(node->lchild);
        if (node->rchild) nodeQueue.push(node->rchild);
    }
}

#else

void PostOrderIterative(BiTNode *root, SqStack *nodeStack, Visit visit)
{
    if (root == NULL)
        return;
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

void PostOrderIterative2(BiTNode *root, SqStack *nodeStack, Visit visit)
{
    // Check for empty tree 
    if (root == NULL)
        return;

    BiTNode *p = root;
    do {
        // Move to leftmost node 
        while (p != NULL) {
            // Push root's right child and then root to stack. 
            if (p->rchild) Push(nodeStack, p->rchild);
            Push(nodeStack, p);

            // Set root as root's left child   
            p = p->lchild;
        }

        // Pop an item from stack and set it as root     
        GetTop(*nodeStack, &p);
        Pop(nodeStack);

        // If the popped item has a right child and the right child is not 
        // processed yet, then make sure right child is processed before root 
        BiTNode *tmp = NULL;
        if (GetTop(*nodeStack, &tmp), p->rchild && tmp == p->rchild){
            Pop(nodeStack);  // remove right child from stack 
            Push(nodeStack, p);  // push root back to stack 
            p = p->rchild; // change root so that the right  
                                // child is processed next 
        }
        else { // Else print root's data and set root as NULL 
            visit(p);  // output, it's can use callback to improve
            p = NULL;
        }
    } while (!isStackEmpty(*nodeStack));
}

void PreOrderIterative(BiTNode *root, SqStack *nodeStack, Visit visit)
{
    if (root == NULL)
        return;
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

void InOrderIterative(BiTNode *root, SqStack *nodeStack, Visit visit)
{
    if (root == NULL)
        return;
    BiTNode *node = root;
    while (node != NULL || !isStackEmpty(*nodeStack)){
        /* Reach the left most Node of the curr Node */
        while (node != NULL){
            /* place pointer to a tree node on the stack before traversing
               the node's left subtree */
            Push(nodeStack, node);
            node = node->lchild;
        }

        // `assert(node == NULL);`
        /* at here, current node must be NULL, 
           then used GetTop to get the stack top to `node` and visit it */

        GetTop(*nodeStack, &node);  // the top node without left child
        Pop(nodeStack);
        visit(node);

        /* we have visited the node and its left subtree.  
           Now, it's right subtree's turn, it's maybe NULL */
        node = node->rchild;

    } /* end of while */
}

void InOrderIterative2(BiTNode *root, SqStack *nodeStack, Visit visit)
{
    if (root == NULL)
        return;
    BiTNode *p = root;
    while (p != NULL) {
        while (p != NULL) {
            if (p->rchild) Push(nodeStack, p->rchild);
            Push(nodeStack, p);
            p = p->lchild;
        }  // after while, p == NULL

        GetTop(*nodeStack, &p);
        Pop(nodeStack);
        while (!isStackEmpty(*nodeStack) && p->rchild == NULL) {
            visit(p);
            GetTop(*nodeStack, &p);
            Pop(nodeStack);
        }
        visit(p);

        if (!isStackEmpty(*nodeStack)) {
            GetTop(*nodeStack, &p);
            Pop(nodeStack);
        }
        else 
            p = NULL;
    }
}

void LevelOrderIterative(BiTNode *root, LinkQueue *nodeQueue, Visit visit)
{
    if (root == NULL)
        return;
    EnQueue(nodeQueue, root);
    while (!isQueueEmpty(*nodeQueue)) {
        BiTNode *node;
        DeQueue(nodeQueue, &node);
        visit(node);
        if (node->lchild) EnQueue(nodeQueue, node->lchild);
        if (node->rchild) EnQueue(nodeQueue, node->rchild);
    }
}

// Inorder traverse without using recursive and no stack
void MorrisInorder(BiTNode *root, Visit visit)
{
    BiTNode *p = root, *tmp;
    while (p != NULL) {
        if (p->lchild == NULL) {
            visit(p);
            p = p->rchild;
        }
        else {
            tmp = p->lchild;
            while (tmp->rchild != NULL && tmp->rchild != p) {
                tmp = tmp->rchild;
            }
            if (tmp->rchild == NULL) {
                tmp->rchild = p;
                p = p->lchild;
            }
            else {
                visit(p);
                tmp->rchild = NULL;
                p = p->rchild;
            }
        }
    }
}
#endif