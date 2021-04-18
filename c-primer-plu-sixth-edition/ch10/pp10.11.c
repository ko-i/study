// 2020-11-08 created by Akson

#include <stdio.h>

void two_times(int m, int n, double arr[m][n]);
void print_arr(int m, int n, double arr[m][n]);

int main(void)
{
	double a[3][5] = 
	{
		{1.0, 2.0, 3.0, 4.0, 5.0},
		{2.0, 3.0, 4.0, 5.0, 6.0},
		{3.0, 4.0, 5.0, 6.0, 7.0}
	};

	printf("a(befor change):\n");
	print_arr(3, 5, a);

	two_times(3, 5, a);

	printf("a(after change):\n");
	print_arr(3, 5, a);

	return 0;
}

void two_times(int m, int n, double arr[m][n])
{
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			arr[i][j] = arr[i][j] * 2.0;
		}
	}
}

void print_arr(int m, int n, double arr[m][n])
{
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%.2lf ", arr[i][j]);
		}
		printf("\n");
	}
}