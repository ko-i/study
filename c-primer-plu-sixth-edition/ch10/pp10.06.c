// 2020-11-09 created by Akson

#include <stdio.h>

void de_order(double *arr, int n);

int main(void)
{
	double a[5] = {1.2, 9.3, 4.9, 3.4, 8.3};

	printf("Before oreder:");
	for(int i = 0; i < 5; i++)
	{
		printf(" %.2lf", a[i]);
	}

	de_order(a, 5);
	printf("\nAfter order:");
	for(int i = 0; i < 5; i++)
	{
		printf(" %.2lf", a[i]);
	}
	printf("\n");

	return 0;
}

void de_order(double *arr, int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(arr[i] < arr[j])
			{
				double temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}