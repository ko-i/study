// 2020-11-10 created by Akson

#include <stdio.h>

#define SIZE 80

char * my_find(char ch, char * st);

int main(void)
{
	char ch;
	char st[SIZE];
	char * index;

	puts("Enter a string and a char, I will find it.");
	printf("Enter a string: ");
	scanf("%s", st);
	getchar();
	printf("Enter a char: ");
	scanf("%c", &ch);

	index = my_find(ch, st);
	if(index)
	{
		puts("Find It!");
	}
	else
	{
		puts("No");
	}

	return 0;
}

char * my_find(char ch, char * st)
{
	char * result = NULL;
	while(*st)
	{
		if(ch == *st)
		{
			result = st;
			break;
		}
		st++;
	}

	return result;
}