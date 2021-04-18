// 2020-12-17 created by Akson
// pe12.7

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "index_node.h"

IndexNode* indexNodeInit()
{
	IndexNode* pIndexNode;
	IndexNode* phead = pIndexNode;

	for(int i = 'a'; i <= 'z' ; i++)
	{
		pIndexNode = (IndexNode*)malloc(sizeof(IndexNode));
		pIndexNode -> letter = i;
		pIndexNode -> first_word = NULL;
		pIndexNode -> next = NULL;
		pIndexNode = pIndexNode -> next;
	}

	return phead;
}

int word_insert(IndexNode* pIndex, char* word)
{
	// 如果传入单词的长度为0或者首字母不是以字母开头
	if(strlen(word) == 0 || !isalpha(*word))
	{
		return 0;
	}

	// 找到索引字母
	while(pIndex -> letter != tolower(*word))
	{
		pIndex = pIndex -> next;
	}

	// 寻找合适的位置插入
	WordNode* pWord = pIndex -> first_word;
	WordNode* pWordBefore = NULL;

	while(pWord != NULL && strcmp(pWord -> word, word) < 0)
	{
		pWordBefore = pWord;
		pWord = pWord -> next;
	}

	// 找到了相同的单词
	if(strcmp(pWord -> word, word) == 0)
	{
		return 0;
	}

	WordNode* newWord = (WordNode*)malloc(sizeof(WordNode));
	newWord -> word = (char*)malloc((strlen(word) + 1) * sizeof(char));
	strcpy(newWord -> word, word);
	newWord -> next = NULL;

	if(pWordBefore == NULL)
	{
		// 没有节点
		pIndex -> first_word = newWord;
	}
	else
	{
		newWord -> next = pWord;
		pWordBefore -> next = newWord;
	}

	return 1;
}
