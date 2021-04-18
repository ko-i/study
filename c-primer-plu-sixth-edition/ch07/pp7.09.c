// 2020-11-07 created by Akson

#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n);

int main()
{
	int num;
	printf("Please enter a positive integer and I will print the prime smaller than it!\n");
	while(scanf("%d", &num) == 0 && num <= 0)
	{
		printf("Please enter a positive integer!\n");
	}

	for(int i = 2; i <= num; i++)
	{
		if(isPrime(i))
		{
			printf("%d ", i);
		}
	}

	printf("\n");

	return 0;
}

bool isPrime(int n)
{
	bool flag = true;

	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			flag = false;
			break;
		}
	}

	return flag;
}