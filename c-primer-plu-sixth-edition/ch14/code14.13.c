// 2020-11-12 created by Akson
// Code14.13 funds4.c

#include <stdio.h>

#define FUNDLEN 50
#define N 2

struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char sace[FUNDLEN];
	double savefund;
};

double sum(const struct funds money[], int n);

int main(void)
{
	struct funds jones[N] = 
	{
		{
			"Garlic-Melon Bank",
			4032.27,
			"Lucky's Saving and loan",
			8543.94
		},
		{
			"Honest Jack's Bank",
			3620.88,
			"Party Time Savings",
			3802.91
		}
	};

	printf("The Joneses have a total of $%.2lf.\n", sum(jones, N));

	return 0;
}

double sum(const struct funds money[], int n)
{
	double total = 0;
	int i;

	for(i = 0; i < n; i++)
	{
		total += money[i].bankfund + money[i].savefund;
	}

	return total;
}

