# 第16章 C预处理器和C库

---
### 复习题：
---
##### 1. 
> 有效，将英里数换算成英尺数。
> 有效，可能得不到想要的结果。
> 无效，预处理语句不加等号。
> 都有效，但有可能得不到想要的结果。
---
##### 2. 修改复习题1中的定义，使其更可靠。
> #define NEW(X) ((X) + 5)
---
##### 3. 定义一个宏函数，返回两者的较小值。
> #define LOWER(X, Y) ((X) < (Y) ? (X) : (Y))
---
##### 4. 定义EVEN_GT(X, Y)宏，如果X为偶数且大于Y，该宏返回1。
> #define EVEN_GT(X, Y) (((X) > (Y) && ((X) % 2) == 0)) ? 1 : 0)
---
##### 5. 定义一个宏函数，打印两个表达式及其值。
> #define PR(X, Y) (printf(#X " is %d and " #Y " is %d\n", X, Y))
---
##### 6. 创建#define指令完成以下任务。
> #define NUMBER 25
> #define SPACE ' '
> #define PS() putchar(' ')
> #define PS(X) ((X) + 3)
> #define SUMSQ(X, Y) (((X) * (X)) + ((Y) * (Y)))
---
##### 7. 定义一个宏，以下面的格式打印名称、值和int类型变量的地址
> #define PR(X, Y, Z) print(#X ": %s; " #Y ": %d;" #Z ": %p", X, Y, Z)
---
##### 8. 假设在测试程序是要暂时跳过一块代码，如何在不移除这块代码的前提下完成这项任务。
> 加注释。
``` c
#define __skip__
#ifndef __skip__
/* code */
#endif
```
---
##### 9. 编写一段代码，如果定义了PR_DATE宏，则打印预处理的日期。
``` c
#ifdef PR_DATE
printf("Date = %s\n", __DATE__);
#endif
```
---
##### 10. 内联函数讨论了3中不同部分的square()函数，从行为上看，这三种版本的函数有何不同？
> 截断方式不同。
---
##### 11. 创建一个使用范型选择表达式的宏，如果宏参数是_Bool类型，对“boolean”求值，否则对“not boolean”求值。
``` c
#define BOOL(X) _Generic((X), _Bool: "boolean", default: "not boolean")
```
---
##### 12. 下面程序有什么错误？
> char * argv[]
> sqrt()函数需要引入math.h
> 需要将argv中的参数转换成数字类型再做计算
---
##### 13. 假设scores是内含1000个int类型元素的数组，要按降序排序该数组中的值，假设你使用qsort()和comp()比较函数。
> qsort((void *)scores, (size_t)1000, sizeof(int), comp)
``` c
int comp(const void * p1, const void * p2)
{
    const int * a1 = (const int *)p1;
    const int * a2 = (const int *)p2;

    if(*a1 > *a2)
    {
        return -1;
    }
    else if(*a1 == *a2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
```
---
##### 14. 
> memcpy(data1, data2, 100 * sizeof(double));
> memcpy(data1, data2 + 200, 100 * sizeof(double));
---
### 编程练习
---
##### 1. 
> 我不需要什么宏。
##### 2. 
> pp16.2.c
##### 3. 
> pp16.3.c
##### 4. 
> pp16.4.c
##### 5. 
> pp16.5.c
##### 6. 
> pp16.6.c
##### 7. 
> pp16.7.c