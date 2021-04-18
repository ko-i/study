// 2020-11-14 created by Akson
// Code16.12 predef.c

#include <stdio.h>

void why_me(void);

int main()
{
	printf("The FILE is %s.\n", __FILE__);
	printf("The DATE is %s.\n", __DATE__);
	printf("The TIME is %s.\n", __TIME__);
	printf("The STDC_VERSION is %ld.\n", __STDC_VERSION__);
	printf("The LINE is %d.\n", __LINE__);
	printf("The func is %s.\n", __func__);

	why_me();

	return 0;
}

void why_me(void)
{
	printf("The func is %s.\n", __func__);
	printf("The LINE is %d.\n", __LINE__);
}