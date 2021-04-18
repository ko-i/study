// 2020-12-22 created by Akson
// pe16.1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	printf("Enter your age and I will cacul something.\n");

	int age;
	printf("Age(q to quit): ");
	while(scanf("%d", &age) == 1)
	{
		while(getchar() != '\n');

		for(int i = 2; i <= 36; i++)
		{
			char* unused;
			if(strtol("29", &unused, i) >= age)
			{
				printf("Your base: %d.\n", i);
				break;
			}
		}

		printf("Next age(q to quit): ");
	}

	printf("Bye!\n");

	return 0;
}