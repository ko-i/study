// 2020-11-08 created by Akson

#include <stdio.h>

void print_choices(void);
int get_choice(int low, int up);

int main(void)
{
	int choice;

	while((choice = get_choice(1, 4)) != 4)
	{
		switch(choice)
		{
			case 1: printf("Copy success!\n"); break;
			case 2: printf("Move success!\n"); break;
			case 3: printf("Remove success!\n"); break;
			default: printf("Wrong!\n"); break;
		}
	}

	printf("Bye!\n");

	return 0;
}

void print_choices(void)
{
	printf("Please choose one of the following:\n");
	printf("1) copy files     2) move files\n");
	printf("3) remove files   4) quit\n");
}

int get_choice(int low, int up)
{
	int num;

	while(1)
	{
		print_choices();
		if(scanf("%d", &num) == 0)
		{
			num = 4;
			break;
		}

		if(num >= low && num <= up)
		{
			break;
		}

		printf("Please enter 1, 2, 3 or 4.\n");

		while(getchar() != '\n')
		{
			continue;
		}
	}

	return num;
}