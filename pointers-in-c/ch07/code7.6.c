// 2020-12-08 created by Akson
// Code7.6 btoa.c 将二进制整数转换为字符

// 接受一个整形值（无符号），把它转换为字符并打印它，前导0被删除

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
}