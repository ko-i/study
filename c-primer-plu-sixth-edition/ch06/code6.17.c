// 2020-11-06 created by Akson
// Code6.17 rows1.c

#include <stdio.h>

#define ROWS 6
#define CHARS 10

int main(void)
{
	int row;
	char ch;

	for(row = 0; row < ROWS; row++)
	{
		for(ch = 'A'; ch < ('A' + CHARS); ch++)
		{
			printf("%c", ch);
		}
		printf("\n");
	}

	return 0;
}