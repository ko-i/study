// 2020-11-06 created by Akson

#include <stdio.h>

int main(void)
{
	char ch = 'A';

	for(int i = 1; i < 7; i++)
	{
		for(int j = 0; j < i; j++)
		{
			printf("%c", ch);
			ch++;
		}
		printf("\n");
	}

	return 0;
}