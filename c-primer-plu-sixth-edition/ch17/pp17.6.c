// 2020-11-16 created by Akson

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define MAXLEN 1000000

void seq_query(int * nums, int target, int n);
void bin_query(int * nums, int target, int n);

int main(void)
{
	int nums[MAXLEN];
	int target = MAXLEN - 2;

	for(int i = 0; i < MAXLEN; i++)
	{
		nums[i] = i;
	}

	seq_query(nums, target, MAXLEN);
	bin_query(nums, target, MAXLEN);

	return 0;
}

void seq_query(int * nums, int target, int n)
{
	clock_t start = clock();
	int index = -1;
	
	for(int i = 0; i < n; i++)
	{
		if(nums[i] > target)
		{
			break;
		}

		if(nums[i] == target)
		{
			index = i;
			break;
		}
	}

	clock_t end = clock();
	double total = (double)(end - start) / CLOCKS_PER_SEC;

	if(index != -1)
	{
		printf("I find %d, at %d\n", target, index);
	}
	else
	{
		printf("I don't find it\n");
	}
	printf("I use %.2lf seconds\n", total);
}

void bin_query(int * nums, int target, int n)
{
	clock_t start = clock();
	int index = -1;

	int left = 0;
	int right = n - 1;
	int mid = MAXLEN / 2;
	while(right - left > 1)
	{
		if(nums[mid] == target)
		{
			index = mid;
			break;
		}
		else if (nums[mid] > target)
		{
			right = mid;
			mid = (left + right) / 2;
		}
		else
		{
			left = mid;
			mid = (left + right) / 2;
		}
	}

	clock_t end = clock();
	double total = (double)(end - start) / CLOCKS_PER_SEC;

	if(index != -1)
	{
		printf("I find %d, at %d\n", target, index);
	}
	else
	{
		printf("I don't find it\n");
	}
	printf("I use %.2lf seconds\n", total);

	
}