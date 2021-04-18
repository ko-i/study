// 2020-12-23 created by Akson
// pe17.2 d_queue.c 用动态数组实现队列

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

// 用于存储队列元素的数组和指向对列头和尾的指针。
static QUEUE_TYPE* queue;
static size_t queue_size;
static size_t front = 0;
static size_t rear = -1;

// create
void create_queue(size_t size)
{
    assert(queue_size == 0);

	queue_size = size;
	queue = (QUEUE_TYPE*)malloc(queue_size * sizeof(QUEUE_TYPE));

	assert(queue != NULL);
}

// insert
void insert(QUEUE_TYPE value)
{
	assert(!is_full());
	rear = (rear + 1) % queue_size;
	queue[rear] = value;
}

// delete
void delete_queue(void)
{
	assert(!is_empty());
	front = (front + 1) % queue_size;
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
	return (rear + 1) % queue_size == front;
}

// if full
int is_full(void)
{
	return (rear + 2) % queue_size == front;
}

// pe17.2
void resize_queue(size_t size)
{
	queue = (QUEUE_TYPE*)realloc(queue, size * sizeof(QUEUE_TYPE));

	assert(queue != NULL);
}
