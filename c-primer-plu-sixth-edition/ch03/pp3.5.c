// 2020-11-05 created by Akson

#include <stdio.h>

int main(void)
{
	double age;
	printf("Please input your age:");
	scanf("%lf", &age);
	printf("your age is %.0lf, and you live %.0lf seconds.\n", age, age * 3.156e7);

	return 0;
}