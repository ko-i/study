// 2020-12-21 created by Akson
// Code16.3 qsort.c 用qsort排序一个数组

// 使用qsort对一个元素为某种结构的数组进行排序

#include <stdlib.h>
#include <string.h>

typedef struct
{
	char key[10];
	int other_data;
} Record;

// 比较函数：之比较关键字的值。
int r_compare(const void* a, const void* b)
{
	return strcmp((Record*)a -> key, (Record*)b -> key);
}

int main(int argc, char const *argv[])
{
	Record array[50];

	// 用50个元素填充数组的代码

	qsort(array, 50, sizeof(Record), r_compare);

	// 现在，数组已经根据结构的关键字字段排序完毕

	return EXIT_SUCCESS;
}