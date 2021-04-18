// 2020-12-14 created by Akson
// Code9.1 strlen.c 字符串长度

// 计算字符串参数的长度

#include <stddef.h>

size_t strlen(char const *string)
{
	int length;

	for(length = 0; *string++ != '\0';)
	{
		length++;
	}

	return length;
}