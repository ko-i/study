// 2020-12-23 created by Akson
// pe17.3 队列的链表实现

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "queue.h"

#define FALSE 0
#define TRUE 1

typedef struct QUEUE_NODE
{
    QUEUE_TYPE value;
    struct QUEUE_NODE* link;
} QueueNode;

static QueueNode* queue;
static QueueNode* rear;

// 创建一个队列，参数指定队列可以存储的元素的最大数量。注意：这个函数只适用于使用动态分配数组的队列。
void create_queue()
{
    queue = NULL;
    rear = NULL;
}

// 销毁一个队列。注意：这个函数只适用于使用动态分配数组的队列。
void destroy_queue(void)
{
    while(!is_empty())
    {
        delete_queue();
    }
}

// 向队列添加一个新元素，参数就是需要添加的元素。
void insert(QUEUE_TYPE value)
{
    QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
    assert(new_node != NULL);

    new_node -> value = value;
    new_node -> link = NULL;

    rear -> link = new_node;
    rear = new_node;
}

// 从队列中一出一个元素并将其丢弃。
void delete_queue(void)
{
    assert(!is_empty());

    QueueNode* first_node = queue;
    queue = queue -> link;
    free(first_node);
}

// 返回队列中第一个元素的值，但不修改队列本身。
QUEUE_TYPE first(void)
{
    assert(!is_empty());

	return queue -> value;
}

// 如果队列为空，返回TRUE，否则返回FALSE。
int is_empty(void)
{
    if(queue == NULL)
    {
        return TRUE;
    }

    return FALSE;
}

// 如果队列已满，返回TRUE，否则返回FALSE。
int is_full(void)
{
    return FALSE;
}
