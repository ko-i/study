// 2020-11-06 created by Akson

#include <stdio.h>

int main(void)
{
	char chs[255];
	int count = 0;

	printf("Please enten a string.\n");
	scanf("%c", &chs[count]);
	while(chs[count] != '\n')
	{
		count++;
		scanf("%c", &chs[count]);
	}

	for(int i = count; i >= 0; i--)
	{
		printf("%c", chs[i]);
	}

	printf("\n");

	return 0;
}