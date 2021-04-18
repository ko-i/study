// 2020-12-22 created by Akson
// Code17.4 l_stack.c 用链表实现堆栈

// 一个用链表实现的堆栈，这个堆栈没有长度限制

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

#define FALSE 0
#define TRUE 1

// 定义一个结构以存储堆栈元素，其中link字段将指向堆栈的下一个元素
typedef struct STACK_NODE
{
	STACK_TYPE value;
	struct STACK_NODE* link;
} StackNode;

// 指向堆栈第一个节点的指针
static StackNode* stack;

// create stack
void create_stack(size_t size)
{

}

// destroy stack
void destroy_stack(void)
{
	while(!is_empty())
	{
		pop();
	}
}

// push
void push(STACK_TYPE value)
{
	StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
	assert(new_node != NULL);
	new_node -> value = value;
	new_node -> link = stack;
	stack = new_node;
}

// pop
void pop(void)
{
	assert(!is_empty());

	StackNode* first_node = stack;
	stack = first_node -> link;
	free(first_node);
}

// top
STACK_TYPE top(void)
{
	assert(!is_empty());

	return stack -> value;
}

// is_empty
int is_empty(void)
{
	return stack == NULL;
}

// is_full
int is_full(void)
{
	return FALSE;
}