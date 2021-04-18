// 2020-11-06 created by Akson

#include <stdio.h>

int main(void)
{
	double Da = 100.0;
	double Da_sum = 100.0;
	double De_sum = 100.0;
	int year = 0;

	do
	{
		Da_sum += Da * 0.1;
		De_sum += De_sum * 0.05;
		year++;
	} while(Da_sum >= De_sum);

	printf("After %d year, Deirdre richer than Daphne.\n", year);
	printf("Deirdre has %.2lf, Daohne has %.2lf\n", De_sum, Da_sum);

	return 0;
}