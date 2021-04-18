// 2020-11-05 created by Akson

#include <stdio.h>

int main(void)
{
	double kuato;
	printf("Please input the kuato:");
	scanf("%lf", &kuato);
	printf("You have %.0lf kuatos water and it have %.0lf water molecue.\n", kuato, kuato * 960.0 / 3.0e-23);

	return 0;
}