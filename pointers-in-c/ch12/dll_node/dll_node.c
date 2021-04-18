// 2020-12-17 created by Akson
// ssl_node.c 对于双链表功能的实现
// code12.4 code12.5 code12.6 code12.7 code12.8
// dll_ins1.c dll_ins2.c dll_ins3.c dll_ins4.c dll_ins5.c

#include <stdlib.h>
#include <stdio.h>
#include "dll_node.h"


// 把一个值插入到一个双链表，rootp是一个指向根节点的指针，value是一个预插入的新值。
// 返回值：如果预插入的值原先已存在于链表中，函数返回0；
// 如果内存不足导致无法插入，函数返回-1；如果插入成功，函数返回1。
int dll_insert1(Node* rootp, int value)
{
	// 查看value是否存在于链表中，如果是就返回，否则，为新值创建一个新节点（“newnode”将指向它）。
	// “this”指针指向应该在新节点之前的那个节点。
	// “next”指针指向应该在新节点之后的那个节点。
	Node* this;
	Node* next;
	for(this = rootp; (next = this -> fwd) != NULL; this = next)
	{
		if(next -> value == value)
		{
			return 0;
		}

		if(next -> value > value)
		{
			break;
		}
	}

	Node* newnode = (Node*)malloc(sizeof(Node));
	if(newnode == NULL)
	{
		return -1;
	}

	newnode -> value = value;

	// 把新值添加到链表中。
	if(next != NULL)
	{
		// 情况1或2：并非位于链表尾部
		if(this != rootp)
		{
			// 情况1：并非位于链表起始位置
			newnode -> fwd = next;
			this -> fwd = newnode;
			newnode -> bwd = this;
			next -> bwd = newnode;
		}
		else
		{
			// 情况2：位于链表起始位置
			newnode -> fwd = next;
			rootp -> fwd = newnode;
			newnode -> bwd = NULL;
			next -> bwd = newnode;
		}
	}
	else
	{
		// 情况3或4：位于链表尾部
		if(this != rootp)
		{
			// 情况3：并非位于链表起始位置
			newnode -> fwd = NULL;
			this -> fwd = newnode;
			newnode -> bwd = this;
			rootp -> bwd = newnode;
		}
		else
		{
			// 情况4：位于链表的起始位置
			newnode -> fwd = NULL;
			rootp -> fwd = newnode;
			newnode -> bwd = NULL;
			rootp -> bwd = newnode;
		}
	}

	return 1;
}

// 针对dll_insert1的优化
int dll_insert2(Node* rootp, int value)
{
	// 查看value是否存在于链表中，如果是就返回，否则，为新值创建一个新节点（“newnode”将指向它）。
	// “this”指针指向应该在新节点之前的那个节点。
	// “next”指针指向应该在新节点之后的那个节点。
	Node* this;
	Node* next;
	for(this = rootp; (next = this -> fwd) != NULL; this = next)
	{
		if(next -> value == value)
		{
			return 0;
		}

		if(next -> value > value)
		{
			break;
		}
	}

	Node* newnode = (Node*)malloc(sizeof(Node));
	if(newnode == NULL)
	{
		return -1;
	}

	newnode -> value = value;

	// 把新值添加到链表中。
	if(next != NULL)
	{
		newnode -> fwd = next;
		// 情况1或2：并非位于链表尾部
		if(this != rootp)
		{
			// 情况1：并非位于链表起始位置
			this -> fwd = newnode;
			newnode -> bwd = this;
		}
		else
		{
			// 情况2：位于链表起始位置
			rootp -> fwd = newnode;
			newnode -> bwd = NULL;
		}
		next -> bwd = newnode;
	}
	else
	{
		newnode -> fwd = NULL;
		// 情况3或4：位于链表尾部
		if(this != rootp)
		{
			// 情况3：并非位于链表起始位置
			this -> fwd = newnode;
			newnode -> bwd = this;
		}
		else
		{
			// 情况4：位于链表的起始位置
			rootp -> fwd = newnode;
			newnode -> bwd = NULL;
		}

		rootp -> bwd = newnode;
	}

	return 1;
}

// 针对dll_insert2的优化
int dll_insert3(Node* rootp, int value)
{
	// 查看value是否存在于链表中，如果是就返回，否则，为新值创建一个新节点（“newnode”将指向它）。
	// “this”指针指向应该在新节点之前的那个节点。
	// “next”指针指向应该在新节点之后的那个节点。
	Node* this;
	Node* next;
	for(this = rootp; (next = this -> fwd) != NULL; this = next)
	{
		if(next -> value == value)
		{
			return 0;
		}

		if(next -> value > value)
		{
			break;
		}
	}

	Node* newnode = (Node*)malloc(sizeof(Node));
	if(newnode == NULL)
	{
		return -1;
	}

	newnode -> value = value;

	// 把新值添加到链表中。
	newnode -> fwd = next;
	this -> fwd = newnode;

	if(this != rootp)
	{
		newnode -> bwd = this;
	}
	else
	{
		newnode -> bwd = NULL;
	}

	if(next != NULL)
	{
		next -> bwd = newnode;
	}
	else
	{
		rootp -> bwd = newnode;
	}
	
	return 1;
}

// 针对dll_insert3的优化
int dll_insert4(Node* rootp, int value)
{
	// 查看value是否存在于链表中，如果是就返回，否则，为新值创建一个新节点（“newnode”将指向它）。
	// “this”指针指向应该在新节点之前的那个节点。
	// “next”指针指向应该在新节点之后的那个节点。
	Node* this;
	Node* next;
	for(this = rootp; (next = this -> fwd) != NULL; this = next)
	{
		if(next -> value == value)
		{
			return 0;
		}

		if(next -> value > value)
		{
			break;
		}
	}

	Node* newnode = (Node*)malloc(sizeof(Node));
	if(newnode == NULL)
	{
		return -1;
	}

	newnode -> value = value;

	// 把新值添加到链表中。
	newnode -> fwd = next;
	this -> fwd = newnode;

	newnode -> bwd = (this != rootp ? this : NULL);
	// (next != NULL ? next : rootp) = newnode;
	
	return 1;
}

// pe12.3
int dll_insert5(Node** h_fwd, Node** h_bwd, int value)
{
	// 查看value是否存在于链表中，如果是就返回，否则，为新值创建一个新节点（“newnode”将指向它）。
	// “this”指针指向应该在新节点之前的那个节点。
	// “next”指针指向应该在新节点之后的那个节点。
	Node* this = NULL;
	Node* next = *h_fwd;
	while(next != NULL)
	{
		if(next -> value == value)
		{
			return 0;
		}

		if(next -> value > value)
		{
			break;
		}

		this = next;
		next = next -> fwd;
	}

	Node* newnode = (Node*)malloc(sizeof(Node));
	if(newnode == NULL)
	{
		return -1;
	}

	newnode -> value = value;

	// 把新值添加到链表中。
	newnode -> fwd = next;
	newnode -> bwd = this;

	if(this != NULL)
	{
		this -> fwd = newnode;
	}
	else
	{
		*h_fwd = newnode;
	}
	
	if(next != NULL)
	{
		next -> bwd = newnode;
	}
	else
	{
		*h_bwd = newnode;
	}
	
	return 1;
}

// pe12.6
int dll_remove(Node** rootp, Node* node)
{
	// 这个是不存在有效节点
	if(*rootp == NULL || (*rootp) -> bwd == NULL)
	{
		return 0;
	}
	Node* p = (*rootp) -> bwd;

	while(p != node)
	{
		p = p -> bwd;

		// 这个是如果找了一圈也没找到
		if(p == (*rootp) -> bwd)
		{
			return 0;
		}
	}

	if(p -> fwd != NULL && p -> bwd != NULL)
	{
		// 这个是p两边都有节点的情况
		p -> fwd -> bwd = p -> bwd;
		p -> bwd -> fwd = p -> fwd;
	}
	else if(p -> fwd == NULL && p -> bwd == NULL)
	{
		// 这个是p恰好是唯一节点的情况
		(*rootp) -> fwd = NULL;
		(*rootp) -> bwd = NULL;
	}
	else if(p -> fwd != NULL && p -> bwd == NULL)
	{
		// 这个是p是首节点的情况
		(*rootp) -> fwd = p -> fwd;
		p -> fwd -> bwd = NULL;
	}
	else if(p -> fwd == NULL && p -> bwd != NULL)
	{
		// 这个是p是尾结点的情况
		(*rootp) -> bwd = p -> bwd;
		p -> bwd -> fwd = NULL;
	}

	free(p);

	return 1;
	
}