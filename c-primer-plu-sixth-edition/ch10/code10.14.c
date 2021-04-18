// 2020-11-09 created by Akson
// Code10.14 arf.c

#include <stdio.h>

#define SIZE 5

void show_array(const double arr[], int n);
void mult_array(double arr[], int n, double mult);

int main(void)
{
	double dip[SIZE] = {20.0, 17.66, 8.2, 15.3, 22.22};

	printf("The original dip array:\n");
	show_array(dip, SIZE);
	mult_array(dip, SIZE, 2.5);

	printf("The dip after calling mult_array():\n");
	show_array(dip, SIZE);

	return 0;
}

void show_array(const double arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%8.3lf\n", arr[i]);
	}

	putchar('\n');
}

void mult_array(double arr[], int n, double mult)
{
	for(int i = 0; i < n; i++)
	{
		arr[i] *= mult;
	}
}