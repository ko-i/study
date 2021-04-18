// 2020-11-08 created by Akson

#include <stdio.h>
#include <ctype.h>

void printInfo(char ch);

int main(void)
{
	printf("Enter a sentence.\n");

	int ch;

	while((ch = getchar()) != EOF)
	{
		printInfo(ch);
	}

	return 0;
}

void printInfo(char ch)
{
	if(isalpha(ch))
	{
		int index1 = ch - 'a' + 1;
		int index2 = ch - 'A' + 1;
		printf("%d\n", (index1 > index2) ? index2 : index1);
	}
	else
	{
		printf("-1\n");
	}
}

