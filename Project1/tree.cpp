#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

BiTree CreateNewNode(TElemType value)
{
	BiTree treePtr = (BiTree)malloc(sizeof(BiTNode));
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
		if (visit(T->value))
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
			if (visit(T->value))
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
				if (visit(T->value))
					return true;
		return false;
	}
	else
		return true;
}


// ≤„–Ú
bool LevelOrderTraverse(BiTree T, Visit visit, void *pUserData)
{
	return true;
}