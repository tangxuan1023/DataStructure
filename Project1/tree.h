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

typedef int(*Visit)(TElemType value);
bool PreOrderTraverse(BiTree T, Visit visit, void *pUserData);
bool InOrderTraverse(BiTree T, Visit visit, void *pUserData);
bool PostOrderTraverse(BiTree T, Visit visit, void *pUserData);
bool LevelOrderTraverse(BiTree T, Visit visit, void *pUserData);

void PreOrderIterative(BiTree root);
#endif