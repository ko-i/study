// 2020-11-06 created by Akson

#include <stdio.h>

int main(void)
{
	int nums[8];
	printf("Please enter eight integers.\n");
	for(int i = 0; i < 8; i++)
	{
		scanf("%d", &nums[i]);
	}

	printf("The integers you entered's reveres order are:\n");
	for(int i = 7; i >= 0; i--)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");

	return 0;
}