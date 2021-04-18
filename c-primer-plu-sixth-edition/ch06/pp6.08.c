// 2020-11-06 created by Akson

#include <stdio.h>

int main(void)
{
	float fl1;
	float fl2;

	printf("Please input two float number(enter q to quit):\n");

	while(scanf("%f %f", &fl1, &fl2))
	{
		printf("%f\n", (fl1 - fl2) / (fl1 * fl2));
		printf("Please input two float number(enter q to quit):\n");
	}

	printf("Done!\n");

	return 0;
}