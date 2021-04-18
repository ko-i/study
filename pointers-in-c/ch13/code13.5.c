// 2020-12-18 created by Akson
// Code13.5 btoa.c 把一个二进制转换为字符

// 接受一个整形值（无符号）把它转换为字符，并打印出来。前导零被去除

#include <stdio.h>

void binary_to_ascii(unsigned int value)
{
	unsigned int quotient;

	quotient = value / 10;
	if(quotient != 0)
	{
		binary_to_ascii(quotient);
	}

	putchar(value % 10 + '0');
	// putchar("0123456789"[value % 10]);
}