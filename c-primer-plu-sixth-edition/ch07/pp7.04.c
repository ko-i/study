// 2020-11-07 created by Akson

#include <stdio.h>

int main(void)
{
	int change_cnt = 0;
	char ch;

	printf("Please enter a sentence and end by #, i will change . and ! in it.\n");

	while((ch = getchar()) != '#')
	{
		if(ch == '.')
		{
			putchar('!');
			change_cnt++;
		}
		else if (ch == '!')
		{
			putchar('!');
			putchar('!');
			change_cnt++;
		}
		else
		{
			putchar(ch);
		}
	}

	printf("I changed %d times.\n", change_cnt);

	return 0;
}