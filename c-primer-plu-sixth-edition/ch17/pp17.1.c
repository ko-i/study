// 2020-11-16 created by Akson

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45

struct film
{
	char title[TSIZE];
	int rating;
	struct film * next;
};

void printListReverse(struct film * pf);
char * s_gets(char *st, int n);

int main(void)
{
	struct film * head = NULL;
	struct film * prev;
	struct film * current;
	char input[TSIZE];

	printf("Enter first movie title: ");
	while(s_gets(input, TSIZE) != NULL && input[0] != '\0')
	{
		current = (struct film *)malloc(sizeof(struct film));

		if(head == NULL)
		{
			head = current;
		}
		else
		{
			prev -> next = current;
		}

		current -> next = NULL;
		strcpy(current -> title, input);

		printf("Enter your rating<0-10>: ");
		scanf("%d", &current -> rating);
		while(getchar() != '\n')
		{
			continue;
		}

		printf("Enter next movie title(empty line to stop): ");
		prev = current;
	}

	if(head != NULL)
	{
		printf("Here is the movie list:\n");
		current = head;
		while(current != NULL)
		{
			printf("Movie: %s  Rating: %d\n", current -> title, current -> rating);
			current = current -> next;
		}

		current = head;
		printf("Here is the movie list reverse:\n");
		printListReverse(current);
	}
	else
	{
		
		printf("No data entered. ");
	}

	current = head;
	while(current != NULL)
	{
		head = current -> next;
		free(current);
		current = head;
	}

	printf("Bye.\n");

	return 0;
}

void printListReverse(struct film * pf)
{
	if(pf != NULL)
	{
		printListReverse(pf -> next);
		printf("Movie: %s  Rating: %d\n", pf -> title, pf -> rating);
	}
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		find = strchr(st, '\n');
		if(find)
		{
			*find = '\0';
		}
		else
		{
			while(getchar() != '\n')
			{
				continue;
			}
		}
	}

	return ret_val;
}