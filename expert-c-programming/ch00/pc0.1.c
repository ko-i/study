// 2020-12-25 created by Akson
// pc0.1.c

#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	time_t biggest = 0x7FFFFFFF;
	printf("biggest = %s \n", asctime(gmtime(&biggest)));
	
	return 0;
}