# 第16章 标准库函数

---
### 问题

#### 1. 下面的函数调用返回什么？
``` c
strtol("12345", NULL, -5);
```
* 0

---
#### 2. 如果说rand函数产生的“随机”不是真正的随机数，那么事实上他们能不能满足我们的需要呢？
* 能。

---
#### 3. 在你的系统上，下面的程序是什么结果？
``` c
#include <stdlib.h>

int main(void)
{
    for(int i = 0; i < 100; i++)
    {
        printf("%d\n", rand() % 2);
    }

    return 0;
}
```
* 随机的0和1。

---
#### 4. 你怎样编写一个程序，判断在你的系统中的clock函数衡量CPU时间用的是CPU使用时间还是总流逝时间？
* 测试代码如下：
``` c
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
	clock_t start = clock();
	printf("start: %lu\n", start);

	clock_t end = clock();
	printf("end: %lu\n", end);

    return 0;
}
```
* 输出如下：  
> start: 4531  
> end: 4575  
* 根据数量级可以看出，这里昌盛的应该是从程序开始运行时CPU的使用时间。

---
#### 5. 下面的代码段试图用军事格式（military format）打印当前时间。它有什么错误？
``` c
#include <time.h>
struct tm *tm;
time_t now;
...
now = time();
tm = localtime(now);
printf("%d:%02d:%02d %d/%02d/%02d\n", tm->tm_hour,tm->tm_min,tm->tm_sectm->tm_mon,tm->tm_day,tm->tm_year);
```
* 修改如下：（建议在酒醒的时候写代码）
``` c
#include <time.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	struct tm *tm;
	const time_t now = time(NULL);

	tm = localtime(&now);
	printf("%d:%02d:%02d %d/%02d/%02d\n", tm->tm_hour, tm->tm_min, tm->tm_sec, tm->tm_mon, tm->tm_mday, 1900 + tm->tm_year);

	return 0;
}
```
---
#### 6. 下面的程序有什么错误？当他在你的系统上执行时会发生什么？
``` c
#include <stdlib.h>
#include <setjmp.h>

jmp_buf jbuf;

void set_buffer()
{
    setjmp(jbuf);
}

int main(int ac, char** av)
{
	int a = atoi(av[1]);
	int b = atoi(av[2]);

	set_buffer();
	printf("%d plus %d equals %d\n", a, b, a + b);
	longjmp(jbuf, 1);
	printf("After longjmp\n");

	return EXIT_SUCCESS;
}

```
* 未引入stdio.h库编译都过不去，代码修改如下：
``` c
#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>

jmp_buf jbuf;

void set_buffer()
{
    setjmp(jbuf);
}

int main(int ac, char** av)
{
	int a = atoi(av[1]);
	int b = atoi(av[2]);

	set_buffer();
	printf("%d plus %d equals %d\n", a, b, a + b);
	longjmp(jbuf, 1);
	printf("After longjmp\n");

	return EXIT_SUCCESS;
}
```
* 然后输入两个数做测试：`./a.out 1 2`，输出结果如下：
> 1 plus 2 equals 3  
> zsh: segmentation fault  ./a.out 1 2  

---
#### 7. 编写一个程序，判断一个整数除以零或者一个浮点数除以零会不会产生SIGFPE信号。你如何解释这个结果？
* 测试代码：
``` c
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void my_handle(int num);

int main(int ac, char** av)
{
	signal(SIGFPE, &my_handle);

	int int_num = 1;
	float float_num = 1.0;
	int div = 0;

	// int result = int_num / div;
	int result = int_num / div;

	return 0;
}

void my_handle(int num)
{

	printf("Div 0! %d\n", num);

	exit(EXIT_FAILURE);
}
```
* 输出结果：
> Div 0! 8  
> Div 0! 8  
* 这很正常啊，产生了啊。倒是直接除以常量0的话连编译都过不去。

---
#### 8. qsort函数所使用的比较函数在第1个参数小于第2个参数的情况下应该返回一个负值，在第1个参数大于第2个参数的情况下应该返回一个正直。如果比较函数返回相反的值，对qsort的行为有没有什么影响？
* 反序排列。

---

### 编程练习

#### 1. 
* pe16.01.c

#### 2. 
* pe16.02.c

#### 3. 
* pe16.03.c

#### 4. 
* pe16.04.c

#### 5. 
* pe16.05.c

#### 6. 
* pe16.06.c

#### 7. 
* pe16.07.c

#### 8. 
* pe16.08.c

#### 9. 
* pe16.09.c

#### 10. 
* pe16.10.c

---
