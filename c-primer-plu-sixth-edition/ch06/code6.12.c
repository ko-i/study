// 2020-11-06 created by Akson
// Code6.11 for_cube.c

#include <stdio.h>

int main(void)
{
	int num;

	printf("    n   n cubed\n");
	for(num = 1; num <= 6; num++)
		printf("%5d %9d\n", num, num * num * num);

	return 0;
}