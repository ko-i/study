// 2020-12-17 created by Akson
// dll_node.h

#ifndef _DLL_NODE_H_
#define _DLL_NODE_H_

typedef struct NODE
{
	int value;
	struct NODE* fwd;
	struct NODE* bwd;
} Node;

int dll_insert1(Node* rootp, int value)
int dll_insert2(Node* rootp, int value)
int dll_insert3(Node* rootp, int value)
int dll_insert4(Node* rootp, int value)

#endif