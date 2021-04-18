# 第11章 字符串和字符串数组

---
### 复习题：
---
##### 1. 下面字符串的声明有什么问题？
> 末尾没有包含空字符。
---
##### 2. 下面的程序会打印什么？
> See you at the snake bar.
> ee you at the snake bar.
> See you
> e you
---
##### 3. 下面的程序会打印什么？
> y
> my
> mmy
> ummy
> Yummy
---
##### 4. 下面的程序会打印什么？
> I read part of it all the way through.
---
##### 5. 下面的练习设计字符串、循环、指针和递增指针。首先，假设定义了下面的函数：
> * Ho Ho Ho!!oH oH oH
> * 指向char类型的指针
> * "Ho Ho Ho!"首字母H的地址
> * pc所指向地址减去1个char单位后的地址上的值，另一个是pc所指向的地址的值减去1后的值
> * Ho Ho Ho!'\0'!oH oH o
> * 来从头到尾后再从尾到头打印字符串。
> * 可能会发生指针越界
> * 做字符串是否为空的检查。
---
##### 6. 假如有如下声明：
> 1byte
> 1byte
> 2byte
---
##### 7. 下面的程序会打印什么？
> How are ya, sweetie? How are ya, sweetie? 
> Beat the clock.
> eat the clock.
> Beat the clock. Win a toy.
> Beat
> chat
> hat
> at
> t
> t
> at
>How are ya, sweetie? 
---
##### 8. 下面的程序会打印什么？
> faavrhee
> *le*on*sm
---
##### 9. 本章定义的s_gets()函数，用指针表示法代替数组表示法便可减少一个变量i。请改写该函数。
``` c
char * s_gets(char * st, int n)
{
	char * ret_val;

	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		while(*st != '\n' && *st != '\0')
		{
			st++;
		}
		if(*st == '\n')
		{
			*st = '\0';
		}
		else
		{
			while(getchar() != '\n')
			{
				continue;
			}
		}
	}

	return ret_val;
}
```
---
##### 10. strlen()函数接受一个指向字符串的指针作为参数，并返回该字符串的长度。请编写一个这样的函数。
``` c
int strlen(char * str)
{
    int count = 0;
    while(*str != '\0')
    {
        count++;
        str++;
    }

    return count;
}
```
---
##### 11. 本章定义的s_gets()函数，可以用strchr()函数代替其中的while来查找换行符。请改写该函数。
``` c
char * s_gets(char * st, int n)
{
	char * ret_val;

	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		if(st = strchr(st, '\n'))
		{
			*st = '\0';
		}
		else
		{
			while(getchar() != '\n')
			{
				continue;
			}
		}
	}

	return ret_val;
}
```
---
##### 12. 设计一个函数，接受一个指向字符串的指针，返回指向改字符串第一个空格字符的指针，或如果没有找到空格字符，则返回空指针。
``` c
char * find_space(char * str)
{
    char * space = NULL;
    while(*str)
    {
        if(*str == ' ')
        {
            space = str;
        }
        str++;
    }

    return space;
}
```
---
##### 13. 重写程序清单11.21，使用ctype.h头文件中的函数，以便无论用户选择大写还是小写，该程序都能正确识别答案。
> hw11.13.c
---
### 编程练习
---
##### 1. 
> pp11.01.c
##### 2. 
> pp11.02.c
##### 3. 
> pp11.03.c
##### 4. 
> pp11.04.c
##### 5. 
> pp11.05.c
##### 6. 
> pp11.06.c
##### 7. 
> pp11.07.c
##### 8. 
> pp11.08.c
##### 9. 
> pp11.09.c
##### 10. 
> pp11.10.c
##### 11. 
> pp11.11.c
##### 12. 
> pp11.12.c
##### 13. 
> pp11.13.c
##### 14. 
> pp11.14.c
##### 15. 
> pp11.15.c
##### 16. 
> pp11.16.c
