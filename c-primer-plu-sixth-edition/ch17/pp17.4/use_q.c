// 2020-11-15 created by Akson
// Code17.8 use_q.c

#include <stdio.h>
#include "queue.h"

int main(void)
{
	Queue line;
	Item temp;
	char ch;

	InitializeQueue(&line);
	printf("Testing the Queue interface.\n");
	printf("Type a to add a value.\n");
	printf("Type d to delete a value.\n");
	printf("Type q to quit.\n");

	while((ch = getchar()) != 'q')
	{
		if(ch != 'a' && ch != 'd')
		{
			continue;
		}

		if(ch == 'a')
		{
			printf("Integer to add: ");
			scanf("%d", &temp);
			if(!QueueIsFull(&line))
			{
				printf("Putting %d into queue.\n", temp);
				EnQueue(temp, &line);
			}
			else
			{
				printf("Queue is full.\n");
			}
		}
		else
		{
			if(QueueIsEmpty(&line))
			{
				printf("Nothing to delete.\n");
			}
			else
			{
				DeQueue(&temp, &line);
				printf("Removing %d from queue\n", temp);
			}
		}

		printf("%d items in queue.\n", QueueItemCount(&line));
		printf("Type a to add, d to delete, q to quit:\n");

	}
	EmptyTheQueue(&line);
	puts("Bye!");

	return 0;
}