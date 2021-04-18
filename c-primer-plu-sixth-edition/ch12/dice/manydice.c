// 2020-11-11 created by Akson
// Code12.13 manydice.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"

int main(void)
{
	int dice, roll;
	int sides;
	int status;

	srand((unsigned int)time(0));
	printf("Enter the number of sides per die, 0 to stop: ");
	while(scanf("%d", &sides) == 1 && sides > 0)
	{
		printf("How many dice: ");
		if((status = scanf("%d", &dice)) != 1)
		{
			if(status == EOF)
			{
				break;
			}
			else
			{
				printf("You should have enter an integer.\n");
				printf("Let's begin again.\n");
				while(getchar() != '\n')
				{
					continue;
				}

				printf("How many sides? Enter 0 to stop: ");
				continue;
			}
		}

		int* dice_num = (int *)malloc(dice * sizeof(int));

		roll = roll_n_dice(dice, sides, dice_num);
		printf("You have rolled a %d using %d %d-side dice.\n", roll, dice, sides);

		for(int i = 0; i < dice; i++)
		{
			printf("%d ", dice_num[i]);
		}
		free(dice_num);

		printf("\nHow many sides? Enter 0 to stop: ");

	}

	printf("The rollem() function was called %d times.\n", roll_count);

	printf("GOOD FORTUNE FOR YOU!\n");

	return 0;
}