// 2020-11-06 created by Akson

#include <stdio.h>

int main(void)
{
	double money = 1000000.0;
	int year = 0;

	do
	{
		money += money * 0.08;
		money -= 100000.0;
		year++;
	} while(money > 0.0);

	printf("After %d years, his money disappear.\n", year);

	return 0;
}