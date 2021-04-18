// 2020-11-16 created by Akson

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

char menu(void);
void addword(Tree * pt);
void showwords(const Tree * pt);
void findword(const Tree * pt);
void printitem(Item item);
char * s_gets(char * st, int n);

int main(void)
{
	Tree words;
	char choice;

	InitializeTree(&words);
	addword(&words);
	while((choice = menu()) != 'q')
	{
		switch(choice)
		{
			case 'l': showwords(&words); break;
			case 'f': findword(&words); break;
			default: puts("Switching error");
		}
	}

	DeleteAll(&words);
	puts("Bye.");

	return 0;
}


char menu(void)
{
	int ch;

	printf("Akson Words\n");
	printf("Enter the letter corresponding to your choice:\n");
	printf("f) find word        l) show list of words\n");
	printf("q) quit\n");

	while((ch = getchar()) != EOF)
	{
		while(getchar() != '\n')
		{
			continue;
		}
		ch = tolower(ch);
		if(strchr("lfq", ch) == NULL)
		{
			printf("Please enter an l, f or q\n");
		}
		else
		{
			break;
		}
	}

	if(ch == EOF)
	{
		ch = 'q';
	}

	return ch;
}

void addword(Tree * pt)
{
	Item temp;

	FILE * fp;
	fp = fopen("words", "r");

	char str[SLEN];
	while(fscanf(fp, "%s", str) != EOF)
	{
		if(TreeIsFull(pt))
		{
			printf("No space!\n");
			break;
		}
		strcpy(temp.words, str);

		AddItem(&temp, pt);
	}

	fclose(fp);
}

void showwords(const Tree * pt)
{
	if(TreeIsEmpty(pt))
	{
		printf("No words!\n");
	}
	else
	{
		Traverse(pt, printitem);
	}
}

void findword(const Tree * pt)
{
	Item temp;

	if(TreeIsEmpty(pt))
	{
		printf("No words!\n");
		return;
	}
	
	printf("Please enter word you wish to find: ");
	s_gets(temp.words, SLEN);

	printf("%s the %d ", temp.words, temp.num);
	if(InTree(&temp, pt))
	{
		printf("is a member.\n");
	}
	else
	{
		printf("is not a member.\n");
	}
}

void printitem(Item item)
{
	printf("Word: %s count: %d\n", item.words, item.num);
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