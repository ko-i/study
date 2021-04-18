// 2020-11-05 created by Akson

#include <stdio.h>

int main(void)
{
	char fn[20];
	char ln[20];
	int fn_num;
	int ln_num;

	printf("Please input your first name:");
	scanf("%s", fn);
	printf("Please input your last name:");
	scanf("%s", ln);

	fn_num = printf("%s", fn);
	printf(" ");
	ln_num = printf("%s", ln);
	printf("\n");

	printf("%*d", fn_num, fn_num);
	printf(" ");
	printf("%*d", ln_num, ln_num);
	printf("\n");

	return 0;
}