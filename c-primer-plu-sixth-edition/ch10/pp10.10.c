// 2020-11-09 created by Akson

#include <stdio.h>

void add_arr(double arr1[], double arr2[], double arr[3], int n);
void print_arr(double arr, int n);

int main(void)
{
	int n = 5;
	double arr1[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
	double arr2[5] = {2.0, 3.0, 4.0, 5.0, 6.0};
	double arr3[5];

	printf("Array1:\n");
	print_arr(arr1, n);
	printf("Array2:\n");
	print_arr(arr2, n);

	add_arr(arr1, arr2, arr3, n);
	printf("Array1 + Array2:\n");
	print_arr(arr3, n);

	return 0;
}

void add_arr(double arr1[], double arr2[], double arr[3], int n);
void print_arr(double arr, int n);