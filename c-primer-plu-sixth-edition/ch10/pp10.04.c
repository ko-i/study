// 2020-11-09 created by Akson

#include <stdio.h>

int max_index(double *arr, int n);

int main(void)
{
	double a[5] = {1.0, 2.0, 5.0, 6.0, 2.3};

	printf("The max number index in a is: %d\n", max_index(a, 5));

	return 0;
}

int max_index(double *arr, int n)
{
	int index = 0;
	double max = arr[0];

	for(int i = 0; i < n; i++)
	{
		if(max < arr[i])
		{
			index = i;
			max = arr[i];
		}
	}

	return index;
}