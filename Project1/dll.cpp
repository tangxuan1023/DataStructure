#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct tag_Node {
	struct tag_Node *fwd;
	struct tag_Node *bwd;
	int value;
}Node;

/* 初始版本 */
int dll_insert(Node *rootp, int value)
{
	Node *current;
	Node *next;
	Node *newnode;

	for (current = rootp; (next = current->fwd) != NULL; current = next) {
		if (next->value == value) {
			return 0;
		}
		if (next->value > value) {
			break;
		}
	}

	newnode = (Node*)malloc(sizeof(Node) * 1);
	if (newnode == NULL){
		return -1;
	}
	newnode->value = value;

	if (next != NULL) {
		if (current != rootp) {
			newnode->fwd = next;
			current->fwd = newnode;
			newnode->bwd = current;
			next->bwd = newnode;
		}
		else {
			newnode->fwd = next;
			rootp->fwd = newnode;
			newnode->bwd = NULL;
			next->bwd = newnode;
		}
	}
	else {
		if (current != rootp) {
			newnode->fwd = NULL;
			current->fwd = newnode;
			newnode->bwd = current;
			rootp->bwd = newnode;
		}
		else {
			newnode->fwd = NULL;
			rootp->fwd = newnode;
			newnode->bwd = NULL;
			rootp->bwd = newnode;
		}
	}
	return 1;  //success
}

/* 简化版本 */
int dll_insert1(Node *rootp, int value)
{
	Node *current;
	Node *next;
	Node *newnode;

	for (current = rootp; (next = current->fwd) != NULL; current = next) {
		if (next->value == value) {
			return 0;
		}
		if (next->value > value) {
			break;
		}
	}

	newnode = (Node*)malloc(sizeof(Node) * 1);
	if (newnode == NULL){
		return -1;
	}
	newnode->value = value;

	newnode->fwd = next;
	current->fwd = newnode;
	if (current != rootp) {
		//newnode->fwd = next;
		//current->fwd = newnode;
		newnode->bwd = current;
		//next->bwd = newnode;
	}
	else {
		//newnode->fwd = next;
		//rootp->fwd = newnode;
		newnode->bwd = NULL;
		//next->bwd = newnode;
	}

	if (next != NULL) {
		//newnode->fwd = next;
		//current->fwd = newnode;
		//if (current != rootp) {
		//	//newnode->fwd = next;
		//	//current->fwd = newnode;
		//	newnode->bwd = current;
		//	//next->bwd = newnode;
		//}
		//else {
		//	//newnode->fwd = next;
		//	//rootp->fwd = newnode;
		//	newnode->bwd = NULL;
		//	//next->bwd = newnode;
		//}
		next->bwd = newnode;
	}
	else {
		//newnode->fwd = NULL;
		//newnode->fwd = next;
		//current->fwd = newnode;
		//if (current != rootp) {
		//	//newnode->fwd = NULL;
		//	//current->fwd = newnode;
		//	newnode->bwd = current;
		//	//rootp->bwd = newnode;
		//}
		//else {
		//	//newnode->fwd = NULL;
		//	//rootp->fwd = newnode;
		//	newnode->bwd = NULL;
		//	//rootp->bwd = newnode;
		//}
		rootp->bwd = newnode;
	}
	return 1;  //success
}