// 2020-11-10 created by Akson
// Code12.4 global.c

#include <stdio.h>

int units = 0;

void critic(void);

int main(void)
{
	extern int units;

	printf("How many pounds to a firkin of butter?\n");
	scanf("%d", &units);

	while(units != 56)
		critic();

	printf("You must have look it up!\n");

	return 0;
}

void critic(void)
{
	printf("No luck, my friend. Try again.\n");

	scanf("%d", &units);
}