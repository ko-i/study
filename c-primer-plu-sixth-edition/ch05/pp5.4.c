// 2020-11-06 created by Akson

#include <stdio.h>

#define CM_PER_IN 2.54
#define IN_PER_FE 12.0

int main(void)
{
	float height;
	printf("Enter a height in centimeters (<=0 to quit): ");
	scanf("%f", &height);

	while(height > 0.0)
	{
		float inches = height / CM_PER_IN;
		int feet = inches / IN_PER_FE;
		float last_inches = inches - feet * IN_PER_FE;
		printf("%.1f cm = %d feet, %.1f inches\n", height, feet, last_inches);
		scanf("%f", &height);
	}

	printf("bye\n");

	return 0;
}