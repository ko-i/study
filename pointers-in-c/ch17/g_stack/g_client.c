// 2020-12-23 created by Akson
// Code17.10b g_client.c 使用泛型数组堆栈

// 一个使用泛型数组对战模块创建两个容纳不同类型数据的堆栈的用户程序

#include <stdlib.h>
#include <stdio.h>
#include "g_stack.h"

// 创建两个堆栈，一个用于容纳整数，另一个用于容纳浮点数。
GENERIC_STACK(int, _int, 10)
GENERIC_STACK(float, _float, 5)

int main(int argc, char const *argv[])
{
	// 往每个堆栈压入几个值。
	push_int(5);
	push_int(22);
	push_int(15);

	push_float(25.3);
	push_float(-40.5);

	// 清空整数堆栈并打印这些值
	while(!is_empty_int())
	{
		printf("Popping %d\n", top_int());
		pop_int();
	}

	// 清空浮点数堆栈并打印这些值
	while(!is_empty_float())
	{
		printf("Popping %f\n", top_float());
		pop_float();
	}

	return EXIT_SUCCESS;
}