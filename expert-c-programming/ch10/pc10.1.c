// 2020-12-28 created by Akson
// pc10.2

#include <stdio.h>

void my_func_1(int fruit[2][3][5]);
void my_func_2(int fruit[][3][5]);
void my_func_3(int (*fruit)[3][5]);

int main(int argc, char const *argv[])
{
	int apricot[2][3][5];

	my_func_1(apricot);
	my_func_2(apricot);
	my_func_3(apricot);

	int (*p)[3][5] = apricot;

	my_func_1(p);
	my_func_2(p);
	my_func_3(p);

	int (*p)[2][3][5] = &apricot;

	my_func_1(*p);
	my_func_2(*p);
	my_func_3(*p);

	return 0;
}

void my_func_1(int fruit[2][3][5])
{
	;
}

void my_func_2(int fruit[][3][5])
{
	;
}

void my_func_3(int (*fruit)[3][5])
{
	;
}