// 2020-11-14 created by Akson

#include <stdio.h>
#include <stdbool.h>

bool isOne(int num, int posi);

int main(void)
{
	int num;
	int posi;

	printf("Enter a number: ");
	while(scanf("%d", &num) == 1)
	{
		printf("Enter a position: ");
		scanf("%d", &posi);

		if(isOne(num, posi))
		{
			printf("%d's %dth number (right to left) is 1.\n", num, posi);
		}
		else
		{
			printf("%d's %dth number (right to left) is 0.\n", num, posi);
		}

		printf("Enter a number: ");
	}

	printf("Bye.\n");

	return 0;
}

bool isOne(int num, int position)
{
	bool flag = false;

	for(int i = 1; i < position; i++)
	{
		num /= 2;
	}

	if(num % 2 == 1)
	{
		flag = true;
	}

	return flag;
}