// 2020-11-09 created by Akson

#include <stdio.h>

// 2020-11-09 created by Akson

#include <stdio.h>

double max_sub_min(double *arr, int n);

int main(void)
{
	double a[5] = {1.0, 2.0, 5.0, 6.0, 2.3};

	printf("The max sub min in a is: %.2lf\n", max_sub_min(a, 5));

	return 0;
}

double max_sub_min(double *arr, int n)
{
	double max = arr[0];
	double min = arr[0];

	for(int i = 0; i < n; i++)
	{
		if(max < arr[i])
		{
			max = arr[i];
		}
		if(min > arr[i])
		{
			min = arr[i];
		}
	}

	return max - min;
}