// 2020-12-06 created by Akson
// Code5.3 bad_exp.c

// 一个证明表达式的求值顺序只是部分由操作符的优先级决定的程序

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i = 10;

	i = i-- - --i * (i *= 3) * i++ + ++i;
	printf("i = %d\n", i);

	return 0;
}