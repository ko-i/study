// 2020-11-07 created by Akson

#include <stdio.h>

int main(void)
{
	float income_limit[4] = {17850.0, 23900.0, 29750.0, 14875.0};
	int info;
	float income;

	printf("Please enter your info:\n");
	printf("1) singular. 2) host.  3) married.  4) divorced. 5) quit\n");
	while(scanf("%d", &info) && info >= 1 && info <= 4)
	{
		printf("Please enter your income: ");
		scanf("%f", &income);

		printf("You should pay %.2f for tax.\n", income > income_limit[info - 1]? income_limit[info - 1] * 0.15 + (income - income_limit[info - 1]) * 0.28 : income * 0.15);

		printf("Please enter your info:\n");
		printf("1) singular. 2) host.  3) married.  4) divorced. 5) quit\n");
	}

	printf("Done!\n");

	return 0;
}