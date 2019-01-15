#ifndef __BITREE_H__
#define __BITREE_H__
#include <stdio.h>
typedef char TElemType;
typedef struct BiTNode {
	TElemType value;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTNode* CreateNewNode(TElemType value);
BiTree CreateBiTree();
void InitBiTree(BiTree &T);
void DestroyBiTree(BiTree &T);
void CreateBiTree(BiTree &T, int def);
void ClearBiTree(BiTree &T);
bool isBiTreeEmpty(BiTree T);
int BiTreeDepth(BiTree T);

void getNodeValue(BiTree T, BiTNode *pNode);
void setNodeValue(BiTree T, BiTNode *pNode, BiTNode newNode);

BiTNode getRoot(BiTree T);
BiTNode getNodeParent(BiTree T, BiTNode node);
BiTNode getNodeLeftChild(BiTree T, BiTNode node);
BiTNode getNodeRightChild(BiTree T, BiTNode node);

void InsertTreeChild(BiTree T, BiTNode *pNode, int LR, BiTree newTree);
void DeleteTreeChild(BiTree T, BiTNode *pNode, int LR);

typedef int(*Visit)(BiTNode *node);
bool PreOrderTraverse(BiTree T, Visit visit, void *pUserData);
bool InOrderTraverse(BiTree T, Visit visit, void *pUserData);
bool PostOrderTraverse(BiTree T, Visit visit, void *pUserData);
bool LevelOrderTraverse(BiTree T, Visit visit, void *pUserData);

#define USE_MY_STACK 1
#define USE_MY_QUEUE 1

#if !USE_MY_STACK
void PreOrderIterative(BiTree root);
void InOrderIterative(BiTree root);
void PostOrderIterative(BiTree root);
void LevelOrderIterative(BiTree root);
#else
struct SqStack;
struct LinkQueue;
void PreOrderIterative(BiTNode *root, SqStack *nodeStack, Visit visit);
void InOrderIterative(BiTNode *root, SqStack *nodeStack, Visit visit);
void PostOrderIterative(BiTNode *root, SqStack *nodeStack, Visit visit);
void LevelOrderIterative(BiTNode *root, LinkQueue *nodeQueue, Visit visit);
#endif
#endif