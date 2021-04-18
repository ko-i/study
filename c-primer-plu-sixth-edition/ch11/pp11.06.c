// 2020-11-10 created by Akson

#include <stdio.h>
#include <stdbool.h>

#define SIZE 80

bool * my_find(char ch, char * st);

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

	if(my_find(ch, st))
	{
		puts("Find It!");
	}
	else
	{
		puts("No");
	}

	return 0;
}

bool * my_find(char ch, char * st)
{
	while(*st)
	{
		if(ch == *st)
		{
			return true;
		}
		st++;
	}

	return false;
}