// 2020-11-09 created by Akson

#include <stdio.h>

void copy_arr(double target[], double source[], int n);
void copy_ptr(double *target, double source[], int n);
void copy_ptrs(double *target, double *start, double *end);

int main(void)
{
	double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[5];
	double target2[5];
	double target3[5];

	copy_arr(target1, source, 5);
	copy_ptr(target2, source, 5);
	copy_ptrs(target3, source, source + 5);

	printf("Source: %.2lf %.2lf %.2lf %.2lf %.2lf\n", source[0], source[1], source[2], source[3], source[4]);
	printf("Target1: %.2lf %.2lf %.2lf %.2lf %.2lf\n", target1[0], target1[1], target1[2], target1[3], target1[4]);
	printf("Target2: %.2lf %.2lf %.2lf %.2lf %.2lf\n", target2[0], target2[1], target2[2], target2[3], target2[4]);
	printf("Target3: %.2lf %.2lf %.2lf %.2lf %.2lf\n", target3[0], target3[1], target3[2], target3[3], target3[4]);

	return 0;
}

void copy_arr(double target[], double source[], int n)
{
	for(int i = 0; i < n; i++)
	{
		target[i] = source[i];
	}
}

void copy_ptr(double *target, double *source, int n)
{
	for(int i = 0; i < n; i++)
	{
		*target = *source;
		target++;
		source++;
	}
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