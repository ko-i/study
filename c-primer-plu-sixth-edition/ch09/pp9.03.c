// 2020-11-08 created by Akson

#include <stdio.h>

void chline(char ch, int i, int j);

int main(void)
{
	char ch;
	int i;
	int j;

	printf("Enter a char and number i and j.\n");
	printf("I will print it i rows and j cols\n");

	printf("Enter the char: \n");
	scanf("%c", &ch);

	printf("Enter i:\n");
	scanf("%d", &i);
	printf("Enter j\n");
	scanf("%d", &j);

	chline(ch, i, j);

	return 0;
}

void chline(char ch, int i, int j)
{
	for(int row = 0; row < i; row++)
	{
		for(int col = 0; col < j; col++)
		{
			printf("%c", ch);
		}

		printf("\n");
	}
}