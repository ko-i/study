// 2020-12-18 created by Akson
// Code13.4 mystery.c 神秘函数

// 神秘函数
// 参数是一个0-100的整数

#include <stdio.h>

void mystery(int n)
{
	n += 5;
	n /= 10;
	printf("%s\n", "**********" + 10 - n);
}