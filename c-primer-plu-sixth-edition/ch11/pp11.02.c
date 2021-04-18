// 2020-11-10 created by Akson

#include <stdio.h>
#include <ctype.h>

#define MAX 10

void get_n(char * str, int n);

int main(void)
{
	char str[20];
	printf("I can only get %d words.\n", MAX - 1);

	get_n(str, MAX);

	printf("This is my get:\n");
	puts(str);

	return 0;
}

void get_n(char * str, int n)
{
	int count = 0;
	while(!isspace(*str = getchar()) && count < n - 1)
	{
		str++;
		count++;
	}

	*str = '\0';
}