// Example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

// 未考虑 malloc 的分配效率，待优化

struct Node {
	int value;
	struct Node *p_next;
}*Root;  // 全局根指针，方便调试，需要优化

int create()
{
	Root = (struct Node *)malloc(sizeof(struct Node));
	if (!Root) {
		return -1;
	}
	Root->p_next = NULL;
	Root->value = -99;
	return 0;
}

// 未考虑头部插入
int sll_insert(struct Node *&p_root, int value)
{
	struct Node *p = p_root;
	struct Node *p_node = (struct Node *)malloc(sizeof(struct Node));
	if (!p_node) {
		return -1;
	}

	p_node->value = value;
	while (p->p_next && p->p_next->value <= value) {
		p = p->p_next;
	}
	p_node->p_next = p->p_next;
	p->p_next = p_node;

	return 0;
}


int print(struct Node *p_root)
{
	struct Node *p = p_root;
	while (p != NULL) {
		printf("x=%d\n", p->value);
		p = p->p_next;
	}
	return 0;
}

// 以下 sll_delete 均未考虑空间释放问题，即有内存泄漏

// 未考虑头部删除
int sll_delete(struct Node **p_root, int value)
{
	struct Node *current = (*p_root)->p_next;
	struct Node *previous = *p_root;

	while (current != NULL && current->value != value) { // 仅删除首个匹配的元素
		//if (current->value != value) {
		previous = current;
		//}
		//else {
		//	previous->p_next = current->p_next;
		//}
		current = current->p_next;
	}
	//if (previous == NULL) {
	//	*p_root = (*p_root)->p_next;
	//}
	//else {
	if(current) {
		previous->p_next = current->p_next;
	}

	return 0;
}

int sll_insert2(struct Node **linkp, int new_value)
{
	struct Node *current;

	struct Node *new_node;
	new_node = (struct Node*)malloc(sizeof(struct Node));
	if (new_node == NULL) {
		return -1;
	}
	new_node->value = new_value;

	while ((current = *linkp) != NULL && current->value < new_value) {
		linkp = &current->p_next;
	}

	new_node->p_next = current;
	*linkp = new_node;

	return 0;
}

// 还有问题，若要删除的目标不存在，bug
int sll_delete2(struct Node **p_link, int value)
{
	struct Node *current;
	while ((current = *p_link) != NULL && current->value != value) { // 仅删除首个匹配的元素
		p_link = &current->p_next;
	}

	if(current)  //修正bug
	*p_link = current->p_next;
	return 0;
}


int destory(struct Node *p_root)
{
	struct Node *p = p_root;
	while (p != NULL) {
		struct Node *temp = p;
		p = p->p_next;
		free(temp);
	}
	return 0;
}

int main_1()
{
	int ret = -1;
	create();
	int test_case = 1;

	printf("\n*******Insert*******\n");
	switch (test_case) {
	case 0:
		sll_insert(Root, 4);
		sll_insert(Root, 3);
		sll_insert(Root, 2);
		sll_insert(Root, 1);
		sll_insert(Root, 0);
		print(Root);
		break;
	case 1:
		sll_insert2(&Root, 4);
		sll_insert2(&Root, 3);
		sll_insert2(&Root, 2);
		sll_insert2(&Root, 1);
		sll_insert2(&Root, 0);
		print(Root);
		break;
	}

	//sll_delete(&Root, 1);
	//sll_delete(&Root, 4);
	sll_delete(&Root, 5);
	printf("\n*******Delete*******\n");
	print(Root);

	destory(Root);
	getchar();
	return 0;
}