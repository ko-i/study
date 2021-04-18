// 2020-12-07 created by Akson
// code6.3 s_srch2.c

// 给定一个指向以NULL结尾的指针列表的指针，在列表中的字符串中查找一个特定的字符。这个函数将破坏这些指针，所以它只适用于这组字符串只使用一次的情况。

#include <stdio.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

int find_char(char **strings, int value)
{
	assert(strings != NULL);

	// 对于列表中的每个字符串...
	while(*strings != NULL)
	{
		// 观察字符串中的每个字符，看看他是否是我们查找的那个。
		while(**strings != '\0')
		{
			if(*(*strings)++ == value)
			{
				return TRUE;
			}
		}

		strings++;
	}

	return FALSE;
}