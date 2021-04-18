// 2020-11-05 created by Akson
// Code4.2 praisel

#include <stdio.h>

#define PARISE "You are an extraordinary being."

int main(void)
{
	char name[40];

	printf("What is your name? ");
	scanf("%s", name);
	printf("Hello, %s. %s\n", name, PARISE);

	return 0;
}