// 2020-12-22 created by Akson
// pe17.3 d_stack.c 用动态数组实现堆栈

// 一个用动态分配数组实现的堆栈，对战的长度在创建堆栈的函数被调用时给出，该函数必须在任何其他操作对战的函数被调用之前调用

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

// 用于存储堆栈元素的数组和指向堆栈顶部的指针
static STACK_TYPE* stack;
static size_t stack_size;
static int top_element = -1;

// create stack
void create_stack(size_t size)
{
	assert(stack_size == 0);

	stack_size = size;
	stack = (STACK_TYPE*)malloc(stack_size * sizeof(STACK_TYPE));

	assert(stack != NULL);
}

// destroy stack
void destroy_stack(void)
{
	assert(stack_size > 0);

	stack_size = 0;
	free(stack);
	stack = NULL;
}

// push
void push(STACK_TYPE value)
{
	assert(!is_full());

	top_element++;
	stack[top_element] = value;
}

// pop
void pop(void)
{
	assert(!is_empty());
	top_element--;
}

// top
STACK_TYPE top(void)
{
	assert(!is_empty());

	return stack[top_element];
}

// is_empty
int is_empty(void)
{
	assert(stack_size > 0);

	return top_element == -1;
}

// is_full
int is_full(void)
{
	assert(stack_size > 0);
	
	return top_element == stack_size - 1;
}

// pe17.1
void resize_stack(size_t size)
{
	stack = (STACK_TYPE*)realloc(stack, size * sizeof(STACK_TYPE));

	assert(stack != NULL);
}
