// 2020-11-06 created by Akson

#include <stdio.h>

int main(void)
{
	char letters[26];

	for(int i = 0; i < 26; i++)
	{
		letters[i] = 'A' + i;
		printf("%c", letters[i]);
	}

	printf("\n");

	return 0;
}