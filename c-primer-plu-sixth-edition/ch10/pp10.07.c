// 2020-11-09 created by Akson

#include <stdio.h>

void copy_arr(double target[], double source[], int n);

int main(void)
{
	double source[5][5];
	double target[5][5];
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			source[i][j] = i + j;
		}
	}

	printf("Source:\n");
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			
			printf("%.2lf ", source[i][j]);
		}
		printf("\n");
	}

	printf("Target before copy:\n");
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			
			printf("%.2lf ", target[i][j]);
		}
		printf("\n");
	}

	for(int i = 0; i < 5; i++)
	{
		copy_arr(target[i], source[i], 5);
	}

	printf("Target After copy:\n");
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			
			printf("%.2lf ", target[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void copy_arr(double target[], double source[], int n)
{
	for(int i = 0; i < n; i++)
	{
		target[i] = source[i];
	}
}