// 2020-12-17 created by Akson
// ssl_node.c 对于单链表功能的实现
// code12.1 code12.2 code12.3
// insert1.c insert2.c insert3.c

#include <stdlib.h>
#include <stdio.h>
#include "sll_node.h"

#define FALSE 0
#define TRUE 1

// Code12.1 insert1.c 插入到一个有序的单链表：第1次尝试
// 插入到一个有序的单链表。函数的参数是一个指向链表第1个节点的指针以及需要额外的插入的值。
int sll_insert1(Node* current, int new_value)
{
	Node* previous;

	// 寻找正确的插入位置，方法是按顺序访问链表，知道到达其值大于或等于新插入值的节点。
	while(current -> value < new_value)
	{
		previous = current;
		current = current -> link;
	}

	// 为新节点分配内存，并把新值存储到新节点中，如果内存分配失败，函数返回FALSE
	Node* new = (Node*)malloc(sizeof(Node));
	if(new == NULL)
	{
		return FALSE;
	}
	new -> value = new_value;

	// 把新节点插入到链表中，并返回TRUE。
	new -> link = current;
	previous -> link = new;

	return TRUE;
}

// Code12.2 insert2.c 插入到一个有序的单链表：第2次尝试
// 插入到一个有序的单链表。函数的参数是一个指向链表的根指针的指针以及需要额外的插入的值。
int sll_insert2(Node** rootp, int new_value)
{
	// 得到指向第一个节点的指针
	Node* current = *rootp;
	Node* previous = NULL;

	// 寻找正确的插入位置，方法是按序访问链表，直到到达一个其值大于或等于新值的节点。
	while(current != NULL && current -> value < new_value)
	{
		previous = current;
		current = current -> link;
	}

	// 为新节点分配内存，并把新值存储到，如果内存分配失败，函数返回FALSE。
	Node* new = (Node*)malloc(sizeof(Node));
	if(new == NULL)
	{
		return FALSE;
	}

	new -> value = new_value;

	// 把新节点插入到链表中，并返回TRUE
	new -> link = current;
	if(previous == NULL)
	{
		*rootp = new;
	}
	else
	{
		previous -> link = new;
	}

	return TRUE;
}

// Code12.3 insert3.c 插入到一个有序的单链表：最终版本
// 插入到一个有序的单链表。函数的参数是一个指向链表的第一个节点的指针以及需要额外的插入的值。
int sll_insert3(Node** linkp, int new_value)
{
	Node* current;

	// 寻找正确的插入位置，方法是按序访问链表，知道到达一个其值大于或等于新值的节点。
	while((current = *linkp) != NULL && current -> value < new_value)
	{
		linkp = &current -> link;
	}

	// 为新节点分配内存，并把新值存储到新节点中，如果内存分配失败，函数返回FALSE
	Node* new = (Node*)malloc(sizeof(Node));
	if(new == NULL)
	{
		return FALSE;
	}
	new -> value = new_value;

	// 在链表中插入新节点，并返回TRUE
	new -> link = current;
	*linkp = new;

	return TRUE;
}

// p12.1 对sll_insert3进行改写，尝试去掉current
int sll_insert4(Node** linkp, int new_value)
{
	// 寻找正确的插入位置，方法是按序访问链表，知道到达一个其值大于或等于新值的节点。
	while(*linkp != NULL && (*linkp) -> value < new_value)
	{
		linkp = &(*linkp) -> link;
	}

	// 为新节点分配内存，并把新值存储到新节点中，如果内存分配失败，函数返回FALSE
	Node* new = (Node*)malloc(sizeof(Node));
	if(new == NULL)
	{
		return FALSE;
	}
	new -> value = new_value;

	// 在链表中插入新节点，并返回TRUE
	new -> link = *linkp;
	*linkp = new;

	return TRUE;
}

// pe12.4
Node* sll_reverse(Node* first)
{
	Node* p = first;
	Node* temp_before = NULL;
	Node* temp_after = NULL;
	
	while(p != NULL)
	{
		temp_after = p -> link;
		p -> link = temp_before;
		temp_before = p;
		p = temp_after;
	}

	return temp_before;
}

// pe12.5
int sll_remove(Node** rootp, Node* node)
{
	Node* p = *rootp;
	
	while(p != NULL && p != node)
	{
		rootp = &p -> link;
		p = *rootp;
	}

	if(p == NULL)
	{
		return FALSE;
	}

	*rootp = p -> link;
	free(p);

	return TRUE;
}