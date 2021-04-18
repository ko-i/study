// 2020-12-22 created by Akson
// Code17.6 a_queue.c 用静态数组实现队列

// 一个用静态数组实现的队列。数组的长度只能通过修改typedef的定义并重新编译模块来调整

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

#define QUEUE_SIZE 100  // 队列中元素的最大数量
#define ARRAY_SIZE (QUEUE_SIZE + 1) // 数组的长度

// 用于存储队列元素的数组和指向对列头和尾的指针。
static QUEUE_TYPE queue[ARRAY_SIZE];
static size_t front = 1;
static size_t rear = 0;

// insert
void insert(QUEUE_TYPE value)
{
	assert(!is_full());
	rear = (rear + 1) % ARRAY_SIZE;
	queue[rear] = value;
}

// delete
void delete_queue(void)
{
	assert(!is_empty());
	front = (front + 1) % ARRAY_SIZE;
}

// first
QUEUE_TYPE first(void)
{
	assert(!is_empty());

	return queue[front];
}

// is empty
int is_empty(void)
{
	return (rear + 1) % ARRAY_SIZE == front;
}

// if full
int is_full(void)
{
	return (rear + 2) % ARRAY_SIZE == front;
}