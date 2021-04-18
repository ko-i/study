// 2020-12-21 created by Akson
// Code16.4 b_search.c 用bsearch在数组中查找

// 用bsearch在一个元素类型为结构的数组中查找

#include <stdlib.h>
#include <string.h>

typedef struct
{
	char key[10];
	int other_data;
} Record;

// 比较函数：只比较关键字的值。
int r_compare(const void* a, const void* b)
{
	return strcmp((Record*)a -> key, (Record*)b -> key);
}

int main(int argc, char const *argv[])
{
	Record array[50];
	Record key;
	Record* ans;

	// 用50个元素填充数组的代码

	// 创建一个关键字结构（只用需要查找的值填充关键字字段，并在数组中查找。
	strcpy(key.key, "value");
	ans = bsearch(&key, array, 50, sizeof(Record), r_compare);

	// 现在ans指向关键字字段与值匹配的数据元素，如果无匹配，ans为NULL

	return EXIT_SUCCESS;
}