// 2020-11-06 created by Akson

#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[40];
	printf("Please enter a vocab\n");
	scanf("%s", str);

	for(int i = strlen(str) - 1; i >= 0; i--)
	{
		printf("%c", str[i]);
	}

	printf("\n");

	return 0;
}