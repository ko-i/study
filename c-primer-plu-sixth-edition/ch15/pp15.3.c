// 2020-11-14 created by Akson

#include <stdio.h>

int count_openbit(int num);

int main(void)
{
	int num;
	int openbit_num;

	printf("Enter a number: ");
	while(scanf("%d", &num) == 1)
	{
		openbit_num = count_openbit(num);

		printf("The openbit number of %d is %d.\n", num, openbit_num);
		printf("Enter a number: ");
	}

	printf("Bye!\n");

	return 0;
}

int count_openbit(int num)
{
	int count = 0;
	while(num != 0)
	{
		if(num % 2 == 1)
		{
			count++;
		}
		num /= 2;
	}

	return count;
}