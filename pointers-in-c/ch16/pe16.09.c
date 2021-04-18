// 2020-12-22 created by Akson
// pe16.9

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define STU_SIZE 30
#define YEAR_SIZE 365
#define EPOCH_SIZE 10000

double same_birthday(int student_number);

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	double result;
	for(int i = 1; i < 10000; i++)
	{
		result = same_birthday(i);
		if(result >= 0.5)
		{
			printf("For 50%% have same day born, we must have at least %d students.\n", i);
			break;
		}
	}

	return 0;
}

double same_birthday(int student_number)
{
	int same_count = 0;

	for(int i = 0; i < EPOCH_SIZE; i++)
	{
		int day_count[YEAR_SIZE] = {0};
		for(int j = 0; j < student_number; j++)
		{
			int temp = rand() % 365;
			if(++day_count[temp] == 2)
			{
				same_count++;
				break;
			}
		}
	}

	double result = (double)same_count / EPOCH_SIZE;
	printf("For %d student. All count: %d, Same count: %d, same persent: %.2f\n", student_number, EPOCH_SIZE, result);

	return result;
}