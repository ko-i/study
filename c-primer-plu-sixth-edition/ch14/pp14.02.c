// 2020-11-13 created by Akson

#include <stdio.h>
#include <string.h>

struct month
{
	char name[20];
	char short_name[4];
	int day_number;
	int count;
};

int check_month(char * str, struct month * year_info);
int count_days(int year, int month, int day, int t_year, int t_month, int t_day, struct month * year_info);

int main(void)
{
	struct month year_info[12] = 
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

	int year, month, day;
	int t_year, t_month, t_day;
	char name[20];

	printf("Enter a year: ");
	scanf("%d", &year);
	printf("Enter a month: ");
	scanf("%s", name);
	month = check_month(name, year_info);
	printf("Enter a day: ");
	scanf("%d", &day);

	printf("Enter another year: ");
	scanf("%d", &t_year);
	printf("Enter another month: ");
	scanf("%s", name);
	t_month = check_month(name, year_info);
	printf("Enter another day: ");
	scanf("%d", &t_day);

	int days_number = count_days(year, month, day, t_year, t_month, t_day, year_info);
	printf("There have %d days between %d-%d-%d to %d-%d-%d!\n", days_number, year, month, day, t_year, t_month, t_day);

	return 0;
}

int check_month(char * str, struct month * year_info)
{
	for(int i = 0; i < 12; i++)
	{
		if(strlen(str) == 1)
		{
			if(str[0] == year_info[i].count + 48)
			{
				return year_info[i].count;
			}
		}

		if(strlen(str) == 2)
		{
			if(strcmp(str, "10") == 0)
			{
				return 10;
			}
			if(strcmp(str, "11") == 0)
			{
				return 11;
			}
			if(strcmp(str, "12") == 0)
			{
				return 12;
			}
		}
		else
		{
			if(strcmp(str, year_info[i].name) == 0 || strcmp(str, year_info[i].short_name) == 0)
			{
				return year_info[i].count;
			}
		}
	}

	return 0;
}

int count_days(int year, int month, int day, int t_year, int t_month, int t_day, struct month * year_info)
{
	int temp;
	if(year > t_year)
	{
		temp = year;
		year = t_year;
		t_year = temp;

		temp = month;
		month = t_month;
		t_month = temp;

		temp = day;
		day = t_day;
		t_day = temp;
	}

	if(year == t_year)
	{
		if(month > t_month)
		{
			temp = month;
			month = t_month;
			t_month = temp;

			temp = day;
			day = t_day;
			t_day = temp;
		}

		if(month == t_month)
		{
			if(day > t_day)
			{
				temp = day;
				day = t_day;
				t_day = temp;
			}
		}
	}

	int sum = 0;

	while(year != t_year || month != t_month || day != t_day)
	{
		sum++;
		day++;
		if(day > year_info[month - 1].day_number)
		{
			day = 1;
			month++;
		}
		if(month > 12)
		{
			month = 1;
			year++;
		}
	}

	return sum;
}
