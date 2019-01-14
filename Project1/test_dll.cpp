#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DNode {
	int value;
	struct DNode *p_fwd;
	struct DNode *p_bwd;
} *Root;


int dll_create() 
{
	Root = (struct DNode*)malloc(sizeof(struct DNode));
	if (!Root) {
		return -1;
	}
	Root->p_fwd = NULL;
	Root->p_bwd = NULL;
	Root->value = -99;
	return 0;
}

int dll_insert(struct DNode *p_root, int value)
{
	struct DNode *p_node = (struct DNode*)malloc(sizeof(struct DNode));
	if (!p_node) {
		return -1;
	}
	p_node->value = value;


	struct DNode *previous = p_root;
	struct DNode *current = previous->p_fwd;
	while (current != NULL && current->value < value) {
		previous = current;
		current = previous->p_fwd;
	}

	if (current == NULL) {
		if (previous == p_root) {
			p_node->p_fwd = NULL;
			previous->p_fwd = p_node;

			p_node->p_bwd = NULL;
			previous->p_bwd = p_node;
		}
		if (previous != p_root) {
			p_node->p_fwd = NULL;
			previous->p_fwd = p_node;

			p_node->p_bwd = previous;
			p_root->p_bwd = p_node;

		}
	}

	if (current != NULL) {
		if (previous == p_root) {
			p_node->p_fwd = current;
			p_root->p_fwd = p_node;

			p_node->p_bwd = NULL;
			current->p_bwd = p_node;
		}

		if (previous != p_root) {
			p_node->p_fwd = current;
			previous->p_fwd = p_node;

			p_node->p_bwd = previous;
			current->p_bwd = p_node;
		}
	}
	

	return 0;
}

int dll_insert2(struct DNode *p_root, int value)
{
	struct DNode *p_node = (struct DNode*)malloc(sizeof(struct DNode));
	if (!p_node) {
		return -1;
	}
	p_node->value = value;

	struct DNode *previous = p_root;
	struct DNode *current = previous->p_fwd;
	while ((current = previous->p_fwd) != NULL && current->value < value) {
		previous = current;
		//current = previous->p_fwd;
	}

	p_node->p_fwd = current;
	previous->p_fwd = p_node;

	if (previous != p_root) {
		p_node->p_bwd = previous;
	}
	else {
		p_node->p_bwd = NULL;
	}

	if (current != NULL) {
		current->p_bwd = p_node;
	}
	else {
		p_root->p_bwd = p_node;
	}

	return 0;
}

int dll_delete(struct DNode *p_root, int value)
{
	struct DNode *previous = p_root;
	struct DNode *current = previous->p_fwd;

	while (current != NULL && current->value != value) {
		previous = current;
		current = previous->p_fwd;
	}

	// TODO(tangxuan): 
	if (current->p_fwd != NULL) {
		if (previous != p_root) {
			previous->p_fwd = current->p_fwd;
			current->p_fwd->p_bwd = current->p_bwd;
			
		}
		else { // previous == p_root
			p_root->p_fwd = current->p_fwd;
			current->p_fwd->p_bwd = NULL;
		}
	}

	else {  // current->p_fwd == NULL 
		if (previous != p_root) {
			previous->p_fwd = NULL;
			p_root = current->p_bwd;
		}
		else {
			p_root->p_fwd = NULL;
			p_root->p_bwd = NULL;
		}
		return -1;
	}

	return 0;
}

int dll_print(struct DNode *p_root, int dest)
{
	struct DNode *p = p_root;
	while (p != NULL) {
		printf("%d\n", p->value);
		switch (dest) {
		case 0:
			p = p->p_fwd;
			break;
		case 1:
			p = p->p_bwd;
			break;
		}
	}
	return 0;
}

int main_dll()
{
	int ret = -1;
	dll_create();
	int test_case = 0;

	printf("\n*******Insert*******\n");
	switch (test_case) {
	case 0:
		dll_insert(Root, 1);
		dll_insert(Root, 3);
		dll_insert(Root, 5);
		dll_insert(Root, -2);
		dll_insert(Root, 4);
		dll_print(Root, 0);
		printf("\n*******Delete*******\n");
		dll_delete(Root, 3);
		dll_print(Root, 0);
		break;
	case 1:
		
		break;
	}

	getchar();
	return 0;
}