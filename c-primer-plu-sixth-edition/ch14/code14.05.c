// 2020-11-12 created by Akson
// Code14.5 funds1.c

#include <stdio.h>

#define FUNDLEN 50

struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(double, double);

int main(void)
{
	struct funds stan = {
		"Garlic-Melon Bank",
		4032.27,
		"Lucky's Savings and Loan",
		8543.94
	};

	printf("Stan has a total of $%.2f.\n", sum(stan.bankfund, stan.savefund));

	return 0;
}

double sum(double x, double y)
{
	return (x + y);
}