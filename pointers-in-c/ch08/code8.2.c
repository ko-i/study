// 2020-12-11 created by Akson
// Code8.2 keyword.c 关键字查找

// 判断参数是否与一个关键字列表的任何单词匹配，并返回匹配的索引值。如果未找到匹配，函数返回-1

#include <string.h>

int lookup_keyword(char const * const desired_word, char const *keyword_table[], int const size)
{
	char const ** kwp;

	// 对于表中的每个单词...
	for(kwp = keyword_table; kwp < keyword_table + size; kwp++)
	{
		// 如果这个单词与我们所查找的单词匹配，返回他在表中的位置
		if(strcmp(desired_word, **kwp) == 0)
		{
			return kwp - keyword_table;
		}
	}

	return -1;
}