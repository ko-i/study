// 2020-11-06 created by Akson

#include <stdio.h>

#define MIN_PER_H 60

int main(void)
{
	int min;

	printf("Please enter the minute number(<= 0 for end)\n");
	scanf("%d", &min);

	while(min > 0)
	{
		printf("hour: %d, min: %d.\n", min / 60, min % 60);
		scanf("%d", &min);
	}

	printf("Done!\n");

	return 0;
}