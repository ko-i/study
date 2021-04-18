// 2020-12-22 created by Akson
// pe16.6

#include <stdio.h>
#include <math.h>

double payment(double amount, double interest, int years);

int main(int argc, char const *argv[])
{
	printf("Enter a money, interest, years\n");

	double amount;
	double interest;
	int years;

	scanf("%lf %lf %d", &amount, &interest, &years);
	printf("You will pay: %.2lf for every month.\n", payment(amount, interest, years));

	printf("Bye!\n");
	return 0;
}

double payment(double amount, double interest, int years)
{	
	interest /= 12;
	double result = (amount * interest) / (1 - pow((1 + interest), -(years * 12)));

	return result;
}