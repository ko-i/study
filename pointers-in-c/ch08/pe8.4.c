// 2020-12-13 created by Akson
// pe8.4

#include <stdio.h>
#include <stdbool.h>

#define MATSIZE 10

bool identity_matrix(int* nums, int len);

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

	if(identity_matrix(&nums[0][0], MATSIZE))
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

bool identity_matrix(int* nums, int len)
{
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < len; j++)
		{
			if(j == i)
			{
				if(*nums != 1)
				{
					return false;
				}
				nums++;
				continue;
			}

			if(*nums != 0)
			{
				return false;
			}
			nums++;
		}
	}

	return true;
}