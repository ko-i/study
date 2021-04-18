// 2020-12-22 created by Akson
// pe16.3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	if(argc != 4)
	{
		printf("Invalid parameter. Please enter: \"%s month(1-12) day(1-31) year(0-?)\"\n", argv[0]);
	}

	int year = atoi(argv[3]);
	int month = atoi(argv[1]);
	int day = atoi(argv[2]);

	time_t this_time = time(NULL);

	struct tm* this_tm = gmtime(&this_time);

	this_tm -> tm_year = (year - 1900);
	this_tm -> tm_mon = month - 1;
	this_tm -> tm_mday = day - 1;

	char weekday[20];
	strftime(weekday, 20, "%A", this_tm);

	printf("Today is %s\n", weekday);

	printf("Done! Bye!\n");
	return 0;
}