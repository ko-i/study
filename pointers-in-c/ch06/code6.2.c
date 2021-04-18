// 2020-12-07 created by Akson
// code6.2 s_srch1.c

// 给定一个指向以NULL结尾的指针，在列表中的字符串中查找一个特定的字符。

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int find_char(char** strings, char value)
{
	char* string;

	// 对列表中的每个字符串...
	while((string = *strings++) != NULL)
	{
		// 观察字符串中的每个字符，看看它是不是我们需要查找的那个。
		while(*string != '\0')
		{
			if(*string++ == value)
			{
				return TRUE;
			}
		}
	}

	return FALSE;
}