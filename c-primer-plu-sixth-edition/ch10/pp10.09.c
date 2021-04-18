// 2020-11-09 created by Akson

#include <stdio.h>

void varr_copy(int m, int n, double target[m][n], double source[m][n]);
void print_arr(int m, int n, double arr[m][n]);

int main(void)
{
	double source[3][5] = 
	{
		{1, 2, 3, 4, 5},
		{2, 3, 4, 5, 6},
		{3, 4, 5, 6, 7}
	};

	double target[3][5];

	printf("Source:\n");
	print_arr(3, 5, source);
	printf("Target(befor copy):\n");
	print_arr(3, 5, target);

	varr_copy(3, 5, target, source);

	printf("Target(after copy):\n");
	print_arr(3, 5, target);

	return 0;
}

void varr_copy(int m, int n, double target[m][n], double source[m][n])
{
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			target[i][j] = source[i][j];
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