// 2020-11-06 created by Akson

#include <stdio.h>

float cal_func(float fl1, float fl2);

int main(void)
{
	float fl1;
	float fl2;

	printf("Please input two float number(enter q to quit):\n");

	while(scanf("%f %f", &fl1, &fl2))
	{
		printf("%f\n", cal_func(fl1, fl2));
		printf("Please input two float number(enter q to quit):\n");
	}

	printf("Done!\n");

	return 0;
}

float cal_func(float fl1, float fl2)
{
	return (fl1 - fl2) / (fl1 * fl2);
}