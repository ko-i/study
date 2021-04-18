// 2020-11-08 created by Akson

#include <stdio.h>

int main(void)
{
	int ch;
	int count = 0;

	while((ch = getchar()) != EOF)
	{
		if(ch == '\n')
		{
			printf("\\n: ");
			printf("%d", '\n');
			printf("\n");
			count = 0;
			continue;
		}

		if (ch == '\t')
		{
			printf("\\t ");
			printf("%d ", ch);
			count++;
		}
		else if(ch >= 1 && ch <= 31)
		{
			printf("^%c: ", ch + 64);
			printf("%d ", ch);
			count++;
		}
		else
		{
			printf("%c: ", ch);
			printf("%d ", ch);
			count++;
		}

		if(count == 10)
		{
			printf("\n");
			count = 0;
		}
	}

	printf("\nDone!\n");

	return 0;
}