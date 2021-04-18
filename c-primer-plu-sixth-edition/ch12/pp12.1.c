// 2020-11-11 created by Akson

#include <stdio.h>

int critic(void);

int main(void)
{
	int units;

	printf("How many pounds to a firkin of butter?\n");
	scanf("%d", &units);

	while(units != 56)
		units = critic();

	printf("You must have look it up!\n");

	return 0;
}

int critic(void)
{
	int units;
	printf("No luck, my friend. Try again.\n");

	scanf("%d", &units);

	return units;
}