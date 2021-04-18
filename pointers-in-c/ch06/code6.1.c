// 2020-12-07 created by Akson
// code6.1 str_len.c

// 计算一个字符串的长度

#include <stdlib.h>

size_t str_len(char* string)
{
	int length = 0;

	// 依次访问字符串的内容，计数字符串，直到遇见NUL终止符
	while(*string++ != '\0')
	{
		length++;
	}

	return length;
}