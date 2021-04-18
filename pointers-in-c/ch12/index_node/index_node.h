// 2020-12-17 created by Akson
// pe12.7

#ifndef _INDEX_NODE_H_
#define _INDEX_NODE_H_

typedef struct WORDNODE
{
	char* word;
	struct WORDNODE* next;
} WordNode;

typedef struct INDEXNODE
{
	char letter;
	struct WORDNODE* first_word;
	struct INDEXNODE* next;
} IndexNode;

IndexNode* indexNodeInit();
int word_insert(IndexNode* pIndex, char* word);

#endif