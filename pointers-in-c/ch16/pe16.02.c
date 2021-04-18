// 2020-12-22 created by Akson
// pe16.2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random_game(void);

int main(int argc, char const *argv[])
{
	int count = 1;
	srand(time(0));

	for(count = 1; count <= 10; count++)
	{
		printf("Epoch #%02d:", count);
		random_game();
	}

	printf("Done!\n");

	return 0;
}

void random_game(void)
{
	for(int i = 0; i < 6; i++)
	{
		printf(" %d", rand() % 6 + 1);
	}
	
	printf("\n");
}