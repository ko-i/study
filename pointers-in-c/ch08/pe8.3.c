// 2020-12-13 created by Akson
// pe8.3

#include <stdio.h>
#include <stdbool.h>

#define MATSIZE 10

bool identity_matrix(int nums[][MATSIZE]);

int main(int argc, char const *argv[])
{
	int nums[MATSIZE][MATSIZE];
	for(int i = 0; i < MATSIZE; i++)
	{
		for(int j = 0; j < MATSIZE; j++)
		{
			if(i == j)
			{
				nums[i][j] = 1;
				continue;
			}

			nums[i][j] = 0;
		}
	}

	if(identity_matrix(nums))
	{
		printf("Yes!\n");
	}
	else
	{
		printf("No!\n");
	}

	printf("Bye!\n");
	return 0;
}

bool identity_matrix(int nums[][MATSIZE])
{
	for(int i = 0; i < MATSIZE; i++)
	{
		for(int j = 0; j < MATSIZE; j++)
		{
			if(j == i)
			{
				if(nums[i][j] != 1)
				{
					return false;
				}
				continue;
			}

			if(nums[i][j] != 0)
			{
				return false;
			}
		}
	}

	return true;
}