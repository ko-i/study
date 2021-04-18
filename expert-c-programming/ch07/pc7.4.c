// 2020-12-27 created by Akson
// pc7.4

#include <setjmp.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

jmp_buf buf;

void handler(int s);

int main(int argc, char const *argv[])
{
	signal(SIGINT, handler);
	if(setjmp(buf))
	{
		printf("back in main\n");
		return 0;
	}
	else
	{
		printf("First time through\n");
	}

loop:
	goto loop;

	return 0;
}

void handler(int s)
{
	if(s == SIGINT)
	{
		printf(" now got a SIGINT signal\n");
	}

	longjmp(buf, 1);
}