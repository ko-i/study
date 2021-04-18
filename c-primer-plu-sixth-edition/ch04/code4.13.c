// 2020-11-05 created by Akson
// Code4.13 prntval.c

#include <stdio.h>

int main(void)
{
	int bph2o = 212;
	int rv;

	rv = printf("%d F is water's boiling point.\n", bph2o);
	printf("The printf() function printed %d characters.\n", rv);

	return 0;
}