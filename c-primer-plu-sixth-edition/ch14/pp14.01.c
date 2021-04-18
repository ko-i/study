// 2020-11-13 created by Akson

#include <stdio.h>
#include <string.h>

struct month
{
	char name[20];
	char short_name[4];
	int day;
	int count;
};

int count_days(char * str, struct month * year);

int main(void)
{
	struct month year[12] = 
	{
		{"January", "Jan.", 31, 1},
		{"Febreuary", "Feb.", 28, 2},
		{"March", "Mar.", 31, 3},
		{"April", "Apr.", 30, 4},
		{"May", "May.", 31, 5},
		{"June", "Jun.", 30, 6},
		{"July", "Jul.", 31, 7},
		{"August", "Aug.", 31, 8},
		{"September", "Sep.", 30, 9},
		{"October", "Oct.", 31, 10},
		{"November", "Nov.", 30, 11},
		{"December", "Dec.", 31, 12}
	};

	int days = 0;
	char name[20];
	printf("What month do you like: ");
	scanf("%s", name);

	days = count_days(name, year);

	printf("Days: %d\n", days);

	return 0;
}

int count_days(char * str, struct month * year)
{
	int sum = 0;
	for(int i = 0; i < 12; i++)
	{
		if(strcmp(str, year[i].name) == 0)
		{
			sum += year[i].day;
			break;
		}
		else
		{
			sum += year[i].day;
		}
	}

	return sum;
}