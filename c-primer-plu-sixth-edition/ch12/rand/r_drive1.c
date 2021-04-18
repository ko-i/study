// 2020-11-11 created by Akson
// Code12.10 r_drive.c

#include <stdio.h>
#include <stdlib.h>

extern void srand1(unsigned int x);
extern int rand1(void);

int main(void)
{
	int count;
	unsigned seed;

	printf("Please enter your choice for seed.\n");
	while(scanf("%u", &seed) == 1)
	{
		srand1(seed);
		for(count = 0; count < 5; count++)
		{
			printf("%d\n", rand1());
		}
		printf("Please enter next seed (q to quit):\n");
	}

	printf("Done!\n");

	return 0;
}