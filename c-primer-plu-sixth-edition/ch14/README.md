# 第14章 结构和其它数据形式

---
### 复习题：
---
##### 1. 下面的结构模板有什么问题？
> 末尾没有加分号，并且没有函数名。
---
##### 2. 下面是程序的一部分，输出是什么？
> 6 1
> 22 Spiffo Road
> S p
---
##### 3. 设计一个结构模板储存一个月份名，该月份名的3个字母缩写、该月的天数以及月份号。
``` c
struct month
{
    char monthname[20];
    char monthlessname[4];
    int days;
    int count;
}
```
---
##### 4. 定义一个数组，内含12个结构（第三题的结构类型）并初始化为一个年份（非闰年）。
``` c
struct month year[12] = 
{
    {
        "January",
        "Jan",
        31,
        1
    },
    ...
}
```
---
##### 5. 编写一个函数，用户提供月份号，该函数就返回一年中到该月为止（包括该月）的总天数。假设在所有函数的外部声明了第3题的结构模板和一个该类型的结构数组。
``` c
int alldays(int month, struct year * my_year)
{
    int nday = 0;
    for(int i = 0; i < month; i++)
    {
        nday += my_year[i].days;
    }

    return nday;
}
```
---
##### 6. 
``` c
include <string.h>

LENS lenses[10];
lenses[2].foclen = 500;
lenses[2].fstop = 2.0;
strcpy(lenses[2].brand, "Remarkata)";
```
``` c
LENS lenses[10] = {
    [2] = {500, 2.0, "Remarkata"},
}
```
---
##### 7. 考虑下面程序片段。
> 6
> Arcturan
> cturan
> deb.title.lase pb -> title.lase
``` c
void my_print(struct bem * mybem)
{
    printf("%s %s is a %d-limbed %s\n", mybem -> title.first, mybem -> title.lase, mybem -> limbs, mybem -> type);
}
```
---
##### 8. 考虑下面声明：
> willie.born
> pt -> born
> scanf("%d", &willie.born);
> scanf("%d", &pt -> born);
> scanf("%s", willie.name.lname);
> scanf("%s", pt -> name.lname);
> willie.name.fname[2];
> strlen(willie.name.fname) + strlen(willie.name.lname);
---
##### 9. 定义一个结构模板：
``` c
struct car
{
    char name[50];
    int power;
    char epa_level;
    int distance;
    int created_yesr;
}
```
---
##### 10. 
``` c
float func1(struct gas mygas)
{
    return mygas.distance / mygas.gals;
}
```
``` c
void func2(struct gas * pg)
{
    pg -> float = pg -> distance / pg -> gals;
}
```
---
##### 11. 声明一个标记为choices的枚举，把枚举常量no、yes、和maybe设置为0，1，2。 
``` c
enum choices {no = 0, yes = 1, maybe = 2};
```
---
##### 12. 声明一个指向函数的指针，该函数返回指向char的指针，接受一个指向char的指针和一个char类型的值。
``` c
char* (*pt) (char *, char);
```
---
##### 13. 
``` c
double func1(double num1, double num2);
double func2(double num1, double num2);
double func3(double num1, double num2);
double func4(double num1, double num2);

double (*pf[4])(double, double) =  {func1, func2, func3, func4};

(*pf[1])(10.0, 2.5);
pf[1](10.0, 2.5);
```
---
### 编程练习
---
##### 1. 
> pp14.01.c
##### 2. 
> pp14.02.c
##### 3. 
> pp14.03.c
##### 4. 
> pp14.04.c
##### 5. 
> pp14.05.c
##### 6. 
> pp14.06.c
##### 7. 
> pp14.07.c
##### 8. 
> pp14.08.c
##### 9. 
> pp14.08.c
##### 10. 
> pp14.10.c
##### 11. 
> pp14.11.c