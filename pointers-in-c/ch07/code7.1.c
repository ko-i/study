// 2020-12-08 created by Akson
// Code7.1 find_int.c

// 在数组中寻找某个特定整形值的存储位置，并返回指向该位置的指针

#include <stdio.h>

int* find_int(int key, int array[], int array_len)
{
	// 对于数组中的每个位置...
	for(int i = 0; i < array_len; i++)
	{
		// 检查这个位置的值是否为需要查找的值。
		if(array[i] == key)
		{
			return &array[i];
		}
	}

	return NULL;
}