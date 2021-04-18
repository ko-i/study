// 2020-11-15 created by Akson
// Code17.12 petclub.c

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

char menu(void);
void addpet(Tree * pt);
void droppet(Tree * pt);
void showpets(const Tree * pt);
void findpet(const Tree * pt);
void printitem(Item item);
void uppercase(char * str);
char * s_gets(char * st, int n);

int main(void)
{
	Tree pets;
	char choice;

	InitializeTree(&pets);
	while((choice = menu()) != 'q')
	{
		switch(choice)
		{
			case 'a': addpet(&pets); break;
			case 'l': showpets(&pets); break;
			case 'f': findpet(&pets); break;
			case 'n': printf("%d pets in club.\n", TreeItemCount(&pets)); break;
			case 'd': droppet(&pets);
			default: puts("Switching error");
		}
	}

	DeleteAll(&pets);
	puts("Bye.");

	return 0;
}


char menu(void)
{
	int ch;

	printf("Akson Pet Club Membership Program\n");
	printf("Enter the letter corresponding to your choice:\n");
	printf("a) add a pet        l) show list of pets\n");
	printf("n) number of pets   f) find pets\n");
	printf("d) delete a pet     q) quit\n");

	while((ch = getchar()) != EOF)
	{
		while(getchar() != '\n')
		{
			continue;
		}
		ch = tolower(ch);
		if(strchr("alrfndq", ch) == NULL)
		{
			printf("Please enter an a, l, f, n, d, or q\n");
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

void addpet(Tree * pt)
{
	Item temp;

	if(TreeIsFull(pt))
	{
		printf("No room in the club!\n");
	}
	else
	{
		printf("Please enter name of pet: ");
		s_gets(temp.petname, SLEN);
		printf("Please enter kind of pet: ");
		s_gets(temp.petkind, SLEN);

		uppercase(temp.petname);
		uppercase(temp.petkind);

		AddItem(&temp, pt);
	}
}

void droppet(Tree * pt)
{
	Item temp;

	if(TreeIsEmpty(pt))
	{
		printf("No pets!\n");
		return;
	}

	printf("Please enter name of pet you wish to delete: ");
	s_gets(temp.petname, SLEN);
	printf("Please enter kind of pet: ");
	s_gets(temp.petkind, SLEN);

	uppercase(temp.petname);
	uppercase(temp.petkind);

	printf("%s the %s ", temp.petname, temp.petkind);
	if(DeleteItem(&temp, pt))
	{
		printf("is droped from the club.\n");
	}
	else
	{
		printf("is not a member.\n");
	}
}	


void showpets(const Tree * pt)
{
	if(TreeIsEmpty(pt))
	{
		printf("No pets!\n");
	}
	else
	{
		Traverse(pt, printitem);
	}
}

void findpet(const Tree * pt)
{
	Item temp;

	if(TreeIsEmpty(pt))
	{
		printf("No pets!\n");
		return;
	}
	
	printf("Please enter name of pet you wish to find: ");
	s_gets(temp.petname, SLEN);
	printf("Please enter pet kind: ");
	s_gets(temp.petkind, SLEN);

	uppercase(temp.petname);
	uppercase(temp.petkind);

	printf("%s the %s ", temp.petname, temp.petkind);
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
	printf("Pet: %-19s Kind: %-19s\n", item.petname, item.petkind);
}

void uppercase(char * str)
{
	while(*str)
	{
		*str = toupper(*str);
		str++;
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