// 2020-11-05 created by Akson

#include <stdio.h>

int main(void)
{
	float lenth;
	char name[20];
	printf("Please input your lenth in cm and name: ");
	scanf("%f %s", &lenth, name);

	printf("%s, you are %.3f meters tall\n", name, lenth / 100.0);

	return 0;
}