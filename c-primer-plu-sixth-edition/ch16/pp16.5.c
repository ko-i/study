// 2020-11-15 created by Akson

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void select(int * nums, int numsSize, int n);

int main(void)
{
	int nums[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int numsSize = 10;
	int n = 5;

	select(nums, numsSize, n);

	return 0;
}

void select(int * nums, int numsSize, int n)
{
	int * flag = (int *)malloc(numsSize * sizeof(int));
	for(int i = 0; i < numsSize; i++)
	{
		flag[i] = 0;
	}

	int selectIndex = 0;
	time_t t;
	srand(time(&t));

	printf("Select numbers:");
	for(int i = 0; i < n; i++)
	{
		selectIndex = (rand() % 10);
		while(flag[selectIndex] != 0)
		{
			selectIndex = (rand() % 10);
		}

		flag[selectIndex] = 1;
		
		printf(" %d", nums[selectIndex]);
	}

	printf("\nDone!\n");
}