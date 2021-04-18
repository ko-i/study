// 2020-11-05 created by Akson
// Code3.2

#include <stdio.h>

int main(void)
{
	int ten = 10;
	int two = 2;

	printf("Doing it right: ");
	printf("%d minus %d is %d\n", ten, two, ten - two);
	printf("Doing it wrong: ");
	printf("%d minus %d is %d\n", ten); // loss two params

	return 0;
}