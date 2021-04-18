// 2020-11-06 created by Akson

#include <stdio.h>

int main(void)
{
	int days;

	printf("Please enter the number of days:\n");
	scanf("%d", &days);

	printf("%d days are %d weeks, %d days.\n", days, days / 7, days % 7);

	return 0;
}