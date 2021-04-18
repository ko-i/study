// 2020-11-06 created by Akson

#include <stdio.h>

int main(void)
{
	char ch;
	printf("Please input a letter: ");
	scanf("%c", &ch);

	for(int i = 1; i <= 5; i++)
	{
		// print ' '
		for(int j = 0; j < 5 - i; j++)
		{
			printf(" ");
		}

		// increase
		for(int j = 0; j < i; j++)
		{
			printf("%c", ch - 4 + j);
		}

		// decrease
		for(int j = 1; j < i; j++)
		{
			printf("%c", ch - 5 + i - j);
		}

		printf("\n");
	}

	return 0;
}