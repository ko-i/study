// 2020-12-16 created by Akson
// pe11.2

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("Enter a list of numbers and I will store it.\n");
	printf("numbers enter(EOF to quit): ");

	int* numbers = (int*)malloc(sizeof(int));
	*numbers = 0;

	int number;
	while(scanf("%d", &number) == 1)
	{
		while(getchar() != '\n')
		{
			continue;
		}
		numbers[0]++;
		numbers = (int*)realloc(numbers, (numbers[0] + 1) * sizeof(int));
		numbers[numbers[0]] = number;
	}

	printf("This is the numbers i got:\n");
	for(int i = 1; i <= numbers[0]; i++)
	{
		printf("%d ", numbers[i]);
	}

	puts("\nBye!");

	return 0;
}