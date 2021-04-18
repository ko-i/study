// 2020-12-18 created by Akson
// Code13.3 cmd_line.c  处理命令行参数

// 处理命令行参数

#include <stdio.h>

#define TRUE 1
#define FALSE 0

// 执行实际任务的函数的原型
void process_standard_input(void);
void process_file(char* file_name);

// 选项标志，缺省初始化为FALSE
int option_a, option_b;

int main(int argc, char const *argv[])
{
	// 处理选项参数：条到下一个参数，并检查它是否以一个横杆开头
	while(*++argv != NULL && **argv == '-')
	{
		// 检查横杠后面的字母
		switch(*++*argv)
		{
			case 'a': option_a = TRUE; break;
			case 'b': option_b = FALSE; break;
		}
	}

	// 处理文件名参数
	if(*argv == NULL)
	{
		process_standard_input();
	}
	else
	{
		do
		{
			process_file(*argv);
		} while(*++argv != NULL);
	}
	
	return 0;
}