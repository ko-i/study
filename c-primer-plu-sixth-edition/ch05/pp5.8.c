// 2020-11-06 created by Akson

#include <stdio.h>

int main(void)
{
	int second_oper;
	int first_oper;

	printf("This program computes moduli.\n");
	printf("Enter an integer to serve as the second operand: ");
	scanf("%d", &second_oper);

	printf("Now enter the first operand (<= 0 to quit): ");
	scanf("%d", &first_oper);

	while(first_oper > 0)
	{
		printf("%d %% %d is %d\n", first_oper, second_oper, first_oper % second_oper);
		printf("Now enter the first operand (<= 0 to quit): ");
		scanf("%d", &first_oper);
	}

	printf("Done!\n");

	return 0;
}