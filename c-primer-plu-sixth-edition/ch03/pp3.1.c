// 2020-11-05 created by Akson

#include <stdio.h>

int main(void)
{
	int int_min = -2147483648;
	int int_max = 2147483647;

	double double_min = -1.79769e+308;
	double double_max = 1.79769e+308;

	printf("int_min = %d\n", int_min);
	printf("int_min - 1 = %d\n", int_min - 1);
	printf("int_max = %d\n", int_max);
	printf("int_max + 1 = %d\n", int_max + 1);

	printf("double_min = %lf\n", double_min);
	printf("double_min - 1 = %lf\n", double_min - 1);
	printf("double_max = %lf\n", double_max);
	printf("double_max + 1 = %lf\n", double_max + 1);

	return 0;
}