// 2020-12-19 created by Akson
// Code15.1 open_cls.c 打开和关闭文件

// 处理每个文件名出现于命令行的文件

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int exit_status = EXIT_SUCCESS;
	FILE* input;

	// 当还有更多文件名时...
	while(*++argv != NULL)
	{
		input = fopen(*argv, "r");
		if(input == NULL)
		{
			perror(*argv);
			exit_status = EXIT_FAILURE;
			continue;
		}

		// 在这里处理这个文件...

		// 关闭文件（期望这里不会发生什么错误)
		if(fclose(input) != 0)
		{
			perror("fclose");
			exit(EXIT_FAILURE);
		}
	}

	return exit_status;
}