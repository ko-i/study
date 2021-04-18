// 2020-12-22 created by Akson
// Code17.2 a_stack.c 用静态数组实现堆栈

// 用一个静态数组实现的堆栈。数组的长度只能通过修改typedef定义，并对模块重新编译来实现。

#include <assert.h>
#include "stack.h"

#define STACK_SIZE 100  // 堆栈容量限制

// 出堆栈中值的数组和一个指向堆栈顶部元素的指针
static STACK_TYPE stack[STACK_SIZE];
static int top_element = -1;

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
	return top_element == -1;
}

// is_full
int is_full(void)
{
	return top_element == STACK_SIZE - 1;
}