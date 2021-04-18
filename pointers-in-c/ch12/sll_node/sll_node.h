// 2020-12-17 created by Akson
// sll_node.h

#ifndef _SLL_NODE_H_
#define _SLL_NODE_H_

typedef struct NODE
{
	int value;
	struct NODE* link;
} Node;

int sll_insert1(Node* current, int new_value);
int sll_insert2(Node** rootp, int new_value);
int sll_insert3(Node** linkp, int new_value);

#endif