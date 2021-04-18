// 2020-12-16 created by Akson
// pe11.4

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int val;
	struct ListNode* next;
} ListNode;

int main(int argc, char const *argv[])
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	ListNode* pl = head;
	for(int i = 1; i <= 2; i++)
	{
		pl -> val = 5 * i;
		pl -> next = (ListNode*)malloc(sizeof(ListNode));
		pl = pl -> next;
	}
	
	pl -> val = 15;
	pl -> next = NULL;

	pl = head;
	printf("Node val:");
	while(pl != NULL)
	{
		printf(" %d", pl -> val);
		pl = pl -> next;
	}

	printf("\nBye!\n");

	return 0;
}