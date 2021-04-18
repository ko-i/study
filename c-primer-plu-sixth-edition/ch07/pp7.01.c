// 2020-11-07 created by Akson

#include <stdio.h>

int main(void)
{
	char ch;

	int space_num = 0;
	int return_num = 0;
	int other_num = 0;

	printf("Please enter some sentence, # for quit.\n");
	while((ch = getchar()) != '#')
	{
		if(ch == ' ')
		{
			space_num++;
		}
		else if(ch == '\n')
		{
			return_num++;
		}
		else
		{
			other_num++;
		}
	}

	printf("Space count: %d Return count: %d Other count: %d\n", space_num, return_num, other_num);

	return 0;
}