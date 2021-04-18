// 2020-12-21 created by Akson
// Code16.2 setjmp.c setjmp和longjmp实例

// 一个说明setjmp用法的程序

#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

typedef struct TRANS
{
	int val;
} Trans;

// 用于存储setjmp状态的状态信息变量
jmp_buf restart;

int main(int argc, char const *argv[])
{
	Trans* transaction;

	// 确立一个我们希望在longjmp的调用之后执行流恢复执行的地点。
	int value = setjmp(restart);

	// 从longjmp返回后判断下一步执行什么。
	switch(setjmp(restart))
	{
		default:
			// longjmp被调用 -- 致命错误
			fputs("Fatal error.\n", stderr);
			break;
		case 1:
			// longjmp被调用 -- 小错误
			fputs("Invalid transaction.\n", stderr);
			break;
		case 0:
		// 最初从setjmp返回的地点：执行正常的处理。
		while((transaction = get_trans()) != NULL)
		{
			process_trans(transaction);
		}
	}

	// 保存数据并退出程序
	write_data_to_file();

	return value == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}