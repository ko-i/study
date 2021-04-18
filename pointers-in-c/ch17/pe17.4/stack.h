// 2020-12-22 created by Akson
// Code17.1 stack.h 堆栈接口

// 一个堆栈模块的接口

#ifndef _STACK_H
#define _STACK_H

#include <stdlib.h>

// 堆栈所存储的值的类型
typedef int STACK_TYPE;

// 创建堆栈。参数指定堆栈可以保存多少个元素，注意：这个函数并不用于静态数组版本的堆栈
void create_stack(size_t size, int stack_index);

// 小会堆栈。它释放堆栈所使用的内存。注意：这个函数也不用于静态数组版本的堆栈。
void destroy_stack(int stack_index);

// 把一个新值压入到堆栈中。它的参数是需要被压入的值。
void push(STACK_TYPE value, int stack_index);

// 从堆栈弹出一个值，并将其丢弃
void pop(int stack_index);

// 返回堆栈顶部元素的值，但不对堆栈进行修改。
STACK_TYPE top(int stack_index);

// 如果堆栈为空，返回TRUE，否则返回FALSE。
int is_empty(int stack_index);

// 如果堆栈已满，返回TRUE，否则返回FALSE。
int is_full(int stack_index);

#endif