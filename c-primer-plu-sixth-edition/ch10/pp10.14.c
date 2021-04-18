// 2020-11-09 created by Akson

#include <stdio.h>

#define ROWS 3
#define COLS 5

void input_data(int rows, int cols, double arr[rows][cols]);
double calcu_row_average(int cols, double arr[cols]);
double calcu_average(int rows, int cols, double arr[rows][cols]);
double find_max(int rows, int cols, double arr[rows][cols]);
void print_result(int rows, double row_average[rows], double average, double max);

int main(void)
{
	double a[ROWS][COLS];
	input_data(ROWS, COLS, a);

	double row_average[ROWS];

	for(int i = 0; i < ROWS; i++)
	{
		row_average[i] = calcu_row_average(COLS, a[i]);
	}

	double average = calcu_average(ROWS, COLS, a);
	double max = find_max(ROWS, COLS, a);
	print_result(ROWS, row_average, average, max);

	return 0;
}

void input_data(int rows, int cols, double arr[rows][cols])
{
	printf("Please enter %d numbers(in %d rows and %d cols)\n", ROWS * COLS, ROWS, COLS);
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			scanf("%lf", &arr[i][j]);
		}
	}
}

double calcu_row_average(int cols, double arr[cols])
{
	double sum = 0;
	
	for(int i = 0; i < cols; i++)
	{
		sum += arr[i];
	}

	return sum / cols;
}

double calcu_average(int rows, int cols, double arr[rows][cols])
{
	double sum = 0;
	double count = 0;
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			sum += arr[i][j];
			count++;
		}
	}

	return sum / count;
}

double find_max(int rows, int cols, double arr[rows][cols])
{
	double max = arr[0][0];
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			if(max < arr[i][j])
			{
				max = arr[i][j];
			}
		}
	}

	return max;
}

void print_result(int rows, double row_average[rows], double average, double max)
{
	printf("The row average is:");
	for(int i = 0; i < rows; i++)
	{
		printf(" %.2lf", row_average[i]);
	}

	printf("\nThe average is: %.2lf\n", average);
	printf("The max number is: %.2lf\n", max);
}

