// 2020-12-22 created by Akson
// Code17.5 queue.h 队列接口

// 一个队列模块的接口

#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdlib.h>

typedef int QUEUE_TYPE;

// 创建一个队列，参数指定队列可以存储的元素的最大数量。注意：这个函数只适用于使用动态分配数组的队列。
void create_queue(size_t size);

// 销毁一个队列。注意：这个函数只适用于使用动态分配数组的队列。
void destroy_queue(void);

// 向队列添加一个新元素，参数就是需要添加的元素。
void insert(QUEUE_TYPE value);

// 从队列中一出一个元素并将其丢弃。
void delete_queue(void);

// 返回队列中第一个元素的值，但不修改队列本身。
QUEUE_TYPE first(void);

// 如果队列为空，返回TRUE，否则返回FALSE。
int is_empty(void);

// 如果队列已满，返回TRUE，否则返回FALSE。
int is_full(void);

void resize_queue(size_t size);

#endif