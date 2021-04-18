// 2020-11-09 created by Akson

#include <stdio.h>

void copy_ptrs(double *target, double *start, double *end);

int main(void)
{
	double source[7] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
	double target[3];

	copy_ptrs(target, &source[2], &source[2] + 3);

	for(int i = 0; i < 3; i++)
	{
		printf("%.2lf\n", target[i]);
	}

	return 0;
}

void copy_ptrs(double *target, double *start, double *end)
{
	while(start != end)
	{
		*target = *start;
		target++;
		start++;
	}
}