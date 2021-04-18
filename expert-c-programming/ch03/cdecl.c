// 2020-12-26 created by Akson
// 把一个C语言声明转化为人类语言

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTOKENS 100
#define MAXTOKENLEN 64

enum type_teg {IDENTIFIER, QUALIFIER, TYPE};

struct token
{
	char type;
	char string[MAXTOKENLEN];
};

int top = -1;
struct token stack[MAXTOKENS];
struct token this;

#define pop stack[top--]
#define push(s) stack[++top] = s

// 推断标识符的类型
enum type_tag classify_string(void);
// 读取下一个标记到this
void gettoken(void);
// 理解所有分析过程的代码段
void read_to_first_identifer(void);
void deal_with_arrays(void);
void deal_with_function_args(void);
void deal_with_pointers(void);
void deal_with_declarator(void);

int main(int argc, char const *argv[])
{
	// 将标记压入堆栈中，直到遇见标识符。
	read_to_first_identifer();
	deal_with_declarator();

	printf("\n");

	return 0;
}

// 推断标识符的类型
enum type_tag classify_string(void)
{
	char* s = this.string;
	if(!strcmp(s, "const"))
	{
		strcpy(s, "read-only");
		return QUALIFIER;
	}

	if(!strcmp(s, "volatile")) return QUALIFIER;
	if(!strcmp(s, "void")) return TYPE;
	if(!strcmp(s, "char")) return TYPE;
	if(!strcmp(s, "signed")) return TYPE;
	if(!strcmp(s, "unsigned")) return TYPE;
	if(!strcmp(s, "short")) return TYPE;
	if(!strcmp(s, "int")) return TYPE;
	if(!strcmp(s, "long")) return TYPE;
	if(!strcmp(s, "float")) return TYPE;
	if(!strcmp(s, "double")) return TYPE;
	if(!strcmp(s, "struct")) return TYPE;
	if(!strcmp(s, "union")) return TYPE;
	if(!strcmp(s, "enum")) return TYPE;

	return IDENTIFIER;
}

// 读取下一个标记到this
void gettoken(void)
{
	char* p = this.string;

	// 略过空包字符
	while((*p = getchar()) == ' ');

	// 读入标识符以A-Z或0-9开头
	if(isalnum(*p))
	{
		while(isalnum(*++p = getchar()));
		ungetc(*p, stdin);

		*p = '\0';

		this.type = classify_string();

		return;
	}

	// 
	if(*p == '*')
	{
		strcpy(this.string, "pointer to");
		this.type = *p;

		return;
	}

	this.string[1] = '\0';
	this.type = *p;

	return;
}
// 理解所有分析过程的代码段
void read_to_first_identifer(void)
{
	gettoken();
	while(this.type != IDENTIFIER)
	{
		push(this);
		gettoken();
	}

	printf("%s is ", this.string);

	gettoken();
}

void deal_with_arrays(void)
{
	while(this.type == '[')
	{
		printf("array ");
		gettoken();  // 数字或']'
		if(isdigit(this.string[0]))
		{
			printf("0..%d ", atoi(this.string) - 1);
			gettoken(); // 读取']'
		}
	}

	gettoken(); // 读取']'之后的再一个标记
	printf("of ");
}

void deal_with_function_args(void)
{
	while(this.type != ')')
	{
		gettoken();
	}

	gettoken();

	printf("function returning ");
}

void deal_with_pointers(void)
{
	while(stack[top].type == '*')
	{
		printf("%s ", pop.string);
	}
}

void deal_with_declarator(void)
{
	// 处理标识符后可能存在的数组/函数
	switch(this.type)
	{
		case '[': deal_with_arrays(); break;
		case '(': deal_with_function_args(); break;
	}

	deal_with_pointers();

	// 处理在读入到标识符之前压入到堆栈中的符号
	while(top >= 0)
	{
		if(stack[top].type == '(')
		{
			pop;
			gettoken();  // 读取‘）’之后的符号
			deal_with_declarator();
		}
		else
		{
			printf("%s \n", pop.string);
		}
	}
}