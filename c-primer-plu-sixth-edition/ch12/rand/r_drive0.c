// 2020-11-11 created by Akson
// Code12.8 r_drive0.c

#include <stdio.h>

extern unsigned int rand0(void);

int main(void)
{
	int count;

	for(count = 0; count < 5; count++)
	{
		printf("%d\n", rand0());
	}

	return 0;
}