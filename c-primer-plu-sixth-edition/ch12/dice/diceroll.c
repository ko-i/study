// 2020-11-11 created by Akson
// Code12.11 diceroll.c

#include "diceroll.h"
#include <stdio.h>
#include <stdlib.h>

int roll_count = 0;

static int rollem(int sides)
{
	int roll;

	roll = rand() % sides + 1;
	++roll_count;

	return roll;
}

int roll_n_dice(int dice, int sides, int* dice_num)
{
	int d;
	int total = 0;

	if(sides < 2)
	{
		printf("Need at least 2 sides.\n");

		return -2;
	}

	if(dice < 1)
	{
		printf("Need at lease 1 die.\n");
		return -1;
	}

	for(d = 0; d < dice; d++)
	{
		int num = rollem(sides);
		dice_num[d] = num;
		total += num;
	}

	return total;
}