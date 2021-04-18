// 2020-12-27 created by Akson
// 

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void handler(int s);

int main(int argc, char const *argv[])
{
	int* p = NULL;

	signal(SIGBUS, handler);
	signal(SIGSEGV, handler);
	signal(SIGILL, handler);

	*p = 0;

	return 0;
}

void handler(int s)
{
	if(s == SIGBUS)
	{
		printf(" now got a bus error signal\n");
	}

	if(s == SIGSEGV)
	{
		printf(" now got a segemtation violation signal\n");
	}

	if(s == SIGILL)
	{
		printf(" now got an illegal instruction signal\n");
	}

	exit(EXIT_FAILURE);
}