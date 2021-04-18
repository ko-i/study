// 2020-11-06 created by Akson

#include <stdio.h>

int main(void)
{
	for(int i = 1; i <= 6; i++)
	{
		char ch = 'F';
		for(int j = 0; j < i; j++)
		{
			printf("%c", ch--);
		}
		printf("\n");
	}

	return 0;
}