// 2020-11-05 created by Akson

#include <stdio.h>

int main(void)
{
	char name[20];
	int name_len;

	printf("Please input your name:");
	scanf("%s", name);

	name_len = printf("\"%s\"\n", name);
	printf("\"%18s\"\n", name);
	printf("\"%-18s\"\n", name);
	printf("%*s\n", name_len, name);

	return 0;
}