// 2020-12-16 created by Akson
// Code11.2 sort.c 排序一列整形值

// 读取、排序和打印一列整形值
#include <stdlib.h>
#include <stdio.h>

// 这个函数由qsort()调用
int compare_integers(const void* a, const void* b);

int main(int argc, char const *argv[])
{
	int n_values;

	// 观察有多少个值
	printf("How many values are there? ");
	if(scanf("%d", &n_values) != 1 || n_values <= 0)
	{
		printf("Illegal number of values.\n");
		exit(EXIT_FAILURE);
	}

	// 分配内存，用于存储这些值。
	int* array = (int*)malloc(n_values * sizeof(int));
	if(array == NULL)
	{
		printf("Can't get memory for that many values.\n");
		exit(EXIT_FAILURE);
	}

	// 读取这些值
	for(int i = 0; i < n_values; i++)
	{
		printf("? ");
		if(scanf("%d", array + i) != 1)
		{
			printf("Erroy reading value #%d\n", i);
			free(array);
			exit(EXIT_FAILURE);
		}
	}

	// 对这些值排序
	qsort(array, n_values, sizeof(int), compare_integers);

	// 打印这些值
	for(int i = 0; i < n_values; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\nBye!\n");

	// 释放内存并退出
	free(array);

	return EXIT_SUCCESS;
}

int compare_integers(const void* a, const void* b)
{
	register const int* pa = a;
	register const int* pb = b;

	return *pa > *pb ? 1 : *pa < *pb ? -1 : 0;
}