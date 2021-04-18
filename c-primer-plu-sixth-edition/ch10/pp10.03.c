// 2020-11-09 created by Akson

#include <stdio.h>

int my_max(int *arr, int n);

int main(void)
{
	int a[5] = {1, 2, 5, 3, 4};

	printf("The max number of a is: %d\n", my_max(a, 5));

	return 0;
}

int my_max(int *arr, int n)
{
	int max = arr[0];

	for(int i = 0; i < n; i++)
	{
		if(max < arr[i])
		{
			max = arr[i];
		}
	}

	return max;
}