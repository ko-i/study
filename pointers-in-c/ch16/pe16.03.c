// 2020-12-22 created by Akson
// pe16.3

#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	time_t this_time = time(NULL);

	struct tm* this_tm = gmtime(&this_time);

	printf("The hour pointer on: %d\n", this_tm -> tm_hour);
	printf("The minute pointer on: %d\n", this_tm -> tm_min);

	printf("Done! Bye!\n");
	return 0;
}