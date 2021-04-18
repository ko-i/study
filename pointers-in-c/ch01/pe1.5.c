// 2020-12-02 created by Akson
// some change on rearrange.c

// 这个程序从标准输入中读取输入行并在标准输出中打印这些输入行
// 每个输入行的后面一行是该行内容的一部分
//
// 输入的第1行是一串列标号，串的最后以一个负数结尾
// 这些列标号成对出现，说明需要打印的输入行的列的范围
// 例如：0 3 10 12 -1 表示第0列到第3列，第10列到第12列的内容将被打印

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20     // 所能处理的最大列号
#define MAX_INPUT 1000  // 每个输入行的最大长度

int read_column_numbers(int columns[], int max);
void rearrange(char *output, char const *input, int n_columns, int const columns[]);
void sort_column_numbers(int columns[], int max);

int main(int argc, char const *argv[])
{
	int n_columns;
	int columns[MAX_COLS];
	char input[MAX_INPUT];
	char output[MAX_INPUT];

	// 读取该串列标号
	n_columns = read_column_numbers(columns, MAX_COLS);

	// 读取、处理和打印剩余的输入行
	while(gets(input) != NULL)
	{
		printf("Original input: %s\n", input);
		rearrange(output, input, n_columns, columns);
		printf("Rearrange line: %s\n", output);
	}

	return EXIT_SUCCESS;
}

// 读取列标号，如果超出规定范围则不予理会
int read_column_numbers(int columns[], int max)
{
	int num = 0;
	int ch;

	// 取得列标号，如果所读取的数小于0则停止
	while(num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0)
	{
		num += 1;
	}

	// 确认已经读取的标号为偶数个，因为它们是以成对的形式出现的
	if(num % 2 != 0)
	{
		puts("Last column number is not paired.");
		exit(EXIT_FAILURE);
	}

	// 给得到的数组内容排序
	sort_column_numbers(columns, num + 1);

	// 丢弃该行中包含最后一个数字的那部分内容
	while((ch = getchar()) != EOF && ch != '\n')
	{
		continue;
	}

	return num;
}

// 处理输入行，将指定列的字符连接在一起，输出行以NUL结尾
void rearrange(char *output, char const *input, int n_columns, int const columns[])
{
	int output_col = 0;
	int len = strlen(input);

	// 处理每对列标号
	for(int col = 0; col < n_columns; col += 2)
	{
		int nchars = columns[col + 1] - columns[col] + 1;

		// 如果输入行结束或者输出行数组已满，就结束任务
		if(columns[col] >= len || output_col == MAX_INPUT - 1)
		{
			break;
		}

		// 如果输出行数据空间不够，只复制可以容纳的数据
		if(output_col + nchars > MAX_INPUT - 1)
		{
			nchars = MAX_INPUT - output_col - 1;
		}

		// 复制相关数据
		strncpy(output + output_col, input + columns[col], nchars);
		output_col += nchars;
	}

	output[output_col] = '\0';
}

// 给得到的列范围从小到大排序
void sort_column_numbers(int columns[], int max)
{
	for(int i = 0; i < max - 1; i++)
	{
		for(int j = i + 1; j < max; j++)
		{
			if(columns[i] > columns[j])
			{
				int temp = columns[i];
				columns[i] = columns[j];
				columns[j] = temp;
			}
		}
	}
}