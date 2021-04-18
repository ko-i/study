// 2020-12-22 created by Akson
// Code17.8 a_tree.c 用静态数组实现二叉搜索树

// 一个使用静态数组实现的二叉搜索树。数组的长度只能通过修改typedef的定义并对模块进行重新编译来实现

#include <stdio.h>
#include <assert.h>
#include "tree.h"

#define TREE_SIZE 100
#define ARRAY_SIZE (TREE_SIZE + 1)

// 用于存储树的所有节点的数组
static TREE_TYPE tree[ARRAY_SIZE];

// 计算一个节点左孩子的下标
static int left_child(int current)
{
	return current * 2;
}

// 计算一个节点右孩子的下标
static int right_child(int current)
{
	return current * 2 + 1;
}

// insert
void insert(TREE_TYPE value)
{
	int current;

	// 确保值为非0，因为零用于提示一个未使用的节点。
	assert(value != 0);

	// 从根节点开始
	current = 1;

	// 从合适的子树开始，知道到达一个叶节点。
	while(tree[current] != 0)
	{
		// 根据情况，进入夜间点或右子树（却新闻i出现重复的值）
		if(value < tree[current])
		{
			current = left_child(current);
		}
		else
		{
			assert(value != tree[current]);
			current = right_child(current);
		}

		assert(current < ARRAY_SIZE);
	}

	tree[current] = value;
}

// find
TREE_TYPE* find(TREE_TYPE value)
{
	int current;

	// 从根节点开始。知道找到那个值，进入合适的子树
	current = 1;

	while(current < ARRAY_SIZE && tree[current] != value)
	{
		// 根据情况，进入左子树还是右子树
		if(value < tree[current])
		{
			current = left_child(current);
		}
		else
		{
			current = right_child(current);
		}
	}

	if(current < ARRAY_SIZE)
	{
		return tree + current;
	}

	return 0;
}

// 执行一层前序遍历，这个帮主函数用于保存我们当前正在处理的节点的信息，他并不是用户接口的一部分。
static void do_pre_order_traverse(int current, void (*callback)(TREE_TYPE value))
{
	if(current < ARRAY_SIZE && tree[current] != 0)
	{
		callback(tree[current]);
		do_pre_order_traverse(left_child(current), callback);
		do_pre_order_traverse(right_child(current), callback);
	}
}

// pre_order_traverse
void pre_order_traverse(void (*callback)(TREE_TYPE value))
{
	do_pre_order_traverse(1, callback);
}

// pe17.5
int count_node(void)
{
	int count = 0;
	for(int i = 0; i < ARRAY_SIZE; i++)
	{
		if(tree[i] != 0)
		{
			count++;
		}
	}

	return count;
}

// pe17.6
static void do_level_order_traverse(int current, void (*callback)(TREE_TYPE value))
{
	for(int i = current; i < ARRAY_SIZE; i++)
	{
		if(tree[i] != 0)
		{
			callback(tree[i]);
		}
	}
}

// pe17.6
void level_order_traverse(void (*callback)(TREE_TYPE value))
{
	do_level_order_traverse(1, callback);
}

void delete_node(TREE_TYPE value)
{
	// 留给有缘人。	
}