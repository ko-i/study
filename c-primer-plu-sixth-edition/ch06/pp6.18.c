// 2020-11-06 created by Akson

#include <stdio.h>

int main(void)
{
	int friends = 5;
	int week = 1;

	do
	{
		friends -= week;
		friends *= 2;
		week++;
	} while(friends < 150);

	printf("After %d weeks, he has been famous.\n", week);

	return 0;

}