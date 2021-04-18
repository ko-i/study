// 2020-12-18 created by Akson
// Code13.1 search.c  类型无关的链表查找

// 在一个单链表中查找一个指定值的函数。它的参数是一个指向链表第一个节点的指针，一个指向我们需要查找的值的指针和一个函数指针，它所指向的函数用于比较存储于链表中的类型的值。

#include <stdio.h>

typedef struct NODE
{
	int value;
	struct NODE* link;
} Node;

int compare_ints(const void* a, const void* b)
{
	if(*(int*)a == *(int*)b)
	{
		return 0;
	}

	return 1;
}

Node* search_list(Node* node, const void* value, int (*compare)(const void*, const void*))
{
	while(node != NULL)
	{
		if(compare(&node -> value, value) == 0)
		{
			break
		}

		node = node -> link;
	}

	return node;
}