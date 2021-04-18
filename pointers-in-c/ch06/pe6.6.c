// 2020-12-08 created by Akson
// pe6.6

#include <stdio.h>

#define MAXSIZE 100000

int is_prime(int num);

int main(int argc, char const *argv[])
{
	char nums[MAXSIZE];

	// 2是质数，所以删除所有的偶数，数组index对应数字为2 * (index + 1) + 1

	// 初始化设置所有的值为真
	for(int i = 0; i < MAXSIZE; i++)
	{

		nums[i] = 1;
	}

	// 开始埃氏筛法
	for(int i = 0; i < MAXSIZE; i++)
	{
		if(nums[i] == 0)
		{
			continue;
		}

		if(!is_prime(2 * (i + 1) + 1))
		{
			nums[i] = 0;
		}

		for(int j = i + 1; j < MAXSIZE; j++)
		{
			if(nums[j] != 0 && ((2 * (j + 1) + 1) % (2 * (i + 1) + 1) == 0))
			{
				nums[j] = 0;
			}
		}
	}

	// printf("The prime numbers between 1 and %d:\n", 2 * (MAXSIZE + 1) + 1);
	// printf("2 ");
	int count[MAXSIZE / 1000] = {0};
	for(int i = 0; i < MAXSIZE; i++)
	{
		if(nums[i] != 0)
		{
			// printf("%d ", 2 * (i + 1) + 1);
			count[(2 * (i + 1) + 1) / 1000]++;
		}
	}

	for(int i = 0; i < MAXSIZE / 1000; i++)
	{
		printf("The prime count between %d and %d: %d\n", i * 1000, (i + 1) * 1000, count[i]);
	}

	printf("\nBye!\n");

	return 0;
}

int is_prime(int num)
{
	for(int i = 2; i <= num / 2 + 1; i++)
	{
		if(num % i == 0)
		{
			return 0;
		}
	}

	return 1;
}