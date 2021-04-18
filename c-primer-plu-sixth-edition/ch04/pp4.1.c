// 2020-11-05 created by Akson

#include <stdio.h>

int main(void)
{
	char firstname[20];
	char lastname[20];

	printf("Please input your firstname:");
	scanf("%s", firstname);
	printf("Please input your lastname:");
	scanf("%s", lastname);

	printf("%s,%s\n", firstname, lastname);

	return 0;
}