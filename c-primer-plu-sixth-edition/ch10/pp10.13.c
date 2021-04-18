// 2020-11-09 created by Akson

#include <stdio.h>

#define ROWS 3
#define COLS 5

void input_data(double arr[][COLS], int rows);
double calcu_row_average(double arr[], int rows);
double calcu_average(double arr[][COLS], int rows);
double find_max(double arr[][COLS], int rows);
void print_result(double row_average[], double average, double max, int rows);

int main(void)
{
	double a[ROWS][COLS];
	input_data(a, ROWS);

	double row_average[ROWS];

	for(int i = 0; i < ROWS; i++)
	{
		row_average[i] = calcu_row_average(a[i], COLS);
	}

	double average = calcu_average(a, ROWS);
	double max = find_max(a, ROWS);
	print_result(row_average, average, max, ROWS);

	return 0;
}

void input_data(double arr[][COLS], int rows)
{
	printf("Please enter %d numbers(in %d rows and %d cols)\n", ROWS * COLS, ROWS, COLS);
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			scanf("%lf", &arr[i][j]);
		}
	}
}

double calcu_row_average(double arr[], int rows)
{
	double sum = 0;
	
	for(int i = 0; i < rows; i++)
	{
		sum += arr[i];
	}

	return sum / rows;
}

double calcu_average(double arr[][COLS], int rows)
{
	double sum = 0;
	double count = 0;
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			sum += arr[i][j];
			count++;
		}
	}

	return sum / count;
}

double find_max(double arr[][COLS], int rows)
{
	double max = arr[0][0];
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			if(max < arr[i][j])
			{
				max = arr[i][j];
			}
		}
	}

	return max;
}

void print_result(double row_average[], double average, double max, int rows)
{
	printf("The row average is:");
	for(int i = 0; i < rows; i++)
	{
		printf(" %.2lf", row_average[i]);
	}

	printf("\nThe average is: %.2lf\n", average);
	printf("The max number is: %.2lf\n", max);
}

