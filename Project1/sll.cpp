#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

#define FALSE 0
#define TRUE  1

typedef struct tag_Node {
	struct tag_Node *link;
	int value;
}Node;

/* ����汾��δ����ͷ������ */
int sll_insert(Node *current, int new_value)
{
	Node *previous;
	Node *new_node;

	//while (current != NULL && current->value < new_value) {//����Ƿ񵽴�ĩβ��������������λ��
		previous = current;
		current = current->link;
	//}
	new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL) {
		return FALSE;
	}
	new_node->value = new_value;

	new_node->link = current;
	previous->link = new_node;
	return TRUE;
}

/* ��ȷ�汾 */
int sll_insert2(Node **rootp, int new_value)
{
	Node *previous;
	Node *current;
	Node *new_node;

	new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL) {
		return FALSE;
	}
	new_node->value = new_value;

	current = *rootp;
	previous = NULL;

	while (current != NULL && current->value < new_value) {
		previous = current;
		current = current->link;
	}

	new_node->link = current;
	if (previous == NULL) {
		*rootp = new_node;
	}
	else {
		previous->link = new_node;
	}

	return TRUE;
}

/* �Ż��汾 */
int sll_insert3(Node **linkp, int new_value)
{
	Node *current;

	Node *new_node;
	new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL) {
		return FALSE;
	}
	new_node->value = new_value;

	while ((current = *linkp) != NULL && current->value < new_value) {
		linkp = &current->link;
	}

	new_node->link = current;
	*linkp = new_node;
	
	return TRUE;
}

//int main()
//{
//	getchar();
//	return 0;
//}