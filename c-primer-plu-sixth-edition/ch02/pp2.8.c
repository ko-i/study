// 2020-11-05 created by Akson

#include <stdio.h>

void one_three();
void two();

int main(void)
{
	printf("starting now:\n");
	one_three();
	printf("done!\n");
}

void one_three()
{
	printf("one\n");
	two();
	printf("three\n");
}

void two()
{
	printf("two\n");
}