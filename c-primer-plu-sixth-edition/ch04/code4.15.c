// 2020-11-05 created by Akson
// Code4.15 input.c

#include <stdio.h>

int main(void)
{
	int age;
	float assets;
	char pet[30];

	printf("Enter your age, assets, and favourate pet.\n");

	scanf("%d %f", &age, &assets);
	scanf("%s", pet);

	printf("%d $%.2f %s\n", age, assets, pet);

	return 0;
}