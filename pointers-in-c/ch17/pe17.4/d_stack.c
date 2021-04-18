// 2020-12-23 created by Akson
// pe17.4

// 一个用动态分配数组实现的堆栈，对战的长度在创建堆栈的函数被调用时给出，该函数必须在任何其他操作对战的函数被调用之前调用

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

// 用于存储堆栈元素的数组和指向堆栈顶部的指针
static STACK_TYPE* stack[10];
static size_t stack_size;
static int top_element[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

// create stack
void create_stack(size_t size, int index)
{
	assert(stack_size == 0);

	stack_size = size;
	stack[index - 1] = (STACK_TYPE*)malloc(stack_size * sizeof(STACK_TYPE));

	assert(stack[index - 1] != NULL);
}

// destroy stack
void destroy_stack(int index)
{
	assert(stack_size > 0);

	stack_size = 0;
	free(stack);
	stack[index - 1] = NULL;
}

// push
void push(STACK_TYPE value, int index)
{
	assert(!is_full(index));

	top_element[index - 1]++;
	top_element[index - 1] = value;
}

// pop
void pop(int index)
{
	assert(!is_empty(index));
	top_element[index - 1]--;
}

// top
STACK_TYPE top(int index)
{
	assert(!is_empty(index));

	return stack[index - 1][top_element[index - 1]];
}

// is_empty
int is_empty(int index)
{
	assert(stack_size > 0);

	return top_element[index - 1] == -1;
}

// is_full
int is_full(int index)
{
	assert(stack_size > 0);
	
	return top_element[index - 1] == stack_size - 1;
}

// pe17.1
void resize_stack(size_t size, int index)
{
	stack[index - 1] = (STACK_TYPE*)realloc(stack[index - 1], size * sizeof(STACK_TYPE));

	assert(stack != NULL);
}
