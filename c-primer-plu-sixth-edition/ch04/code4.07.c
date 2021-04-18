// 2020-11-05 created by Akson
// Code4.7 width.c

#include <stdio.h>

#define PAGES 959

int main(void)
{
	printf("*%d*\n", PAGES);
	printf("*%2d*\n", PAGES);
	printf("*%10d*\n", PAGES);
	printf("*%-10d*\n", PAGES);

	return 0;
}