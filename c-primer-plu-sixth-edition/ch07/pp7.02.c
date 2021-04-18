// 2020-11-07 created by Akson

#include <stdio.h>

int main(void)
{
	char ch;
	int count = 0;

	printf("Please a sentence and # for end.\n");
	while((ch = getchar()) != '#')
	{
		if(count == 8)
		{
			count = 0;
			printf("\n");
		}
		count++;
		putchar(ch);
	}

	return 0;
}