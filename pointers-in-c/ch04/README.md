# 第4章 语句

---
### 问题

#### 1. 下面的表达式是否合法？如果合法，它执行了什么任务？
``` c
3 * x * x - 4 * x + 6;
```
* 合法，它首先计算`3 * x * x - 4 * x + 6`的值然后将它丢弃。

---
#### 2. 赋值语句的语法是怎样的？
* `left_value = right_value;`
* 其中`left_value`一般情况下是可以被赋值的变量，而`right_value`是一种可以计算出结果的表达式。

---
#### 3. 用下面这种方法使用代码块是否合法？如果合法，你是否曾经想这样使用？
```
...
statement
{
    statement
    statement
}
statement
```
* 这样是合法的，大括号生成了一个子作用域。我曾经没想过这样使用。

---
#### 4. 当你编写if语句时，如果在then字句中没有语句，但在else字句中有语句，你该如何编写？你还能改用其他形式来达到同样的目的吗？
* 这样编写：
``` c
if(judge_statement)
{

}
else
{
    statement
}
```
* 还可以这样写：
``` c
if(!(judge_statement))
{
    statement
}
```

---
#### 5. 下面的循环将产生什么样的输出？
``` c
int i;
...
for(i = 0; i < 10; i += 1)
{
    printf("%d\n", i);
}
```
* 输出内容如下：
> 0  
> 1  
> 2  
> 3  
> 4  
> 5  
> 6  
> 7  
> 8  
> 9  

---
#### 6. 什么时候使用while语句比使用for语句更加合适？
* 当循环条件不依赖计数的时候。

---
#### 7. 下面的代码片段用于把标准输入复制到标准输出，并计算字符的检验和（checksum），它有什么错误吗？
``` c
while((ch = getchar()) != EOF)
{
    checksum += ch;
    putchar(ch);
}

printf("Checksum = %d\n", checksum);
```
* 我没看出来有啥错误，这就啥错误啊。

---
#### 8. 什么时候使用do语句比使用while语句更加合适？
* 循环体最少也要执行一次的时候。

---
#### 9. 下面的代码片段将产生什么样的输出？注意：位于做操作数和右操作数之间的%操作符用于产生两者相除的余数。
``` c
for(i = 1; i <= 4; i += 1>)
{
    switch(i % 2)
    {
        case 0: printf("even\n");
        case 1: printf("odd\n");
    }
}
```
* 以下是打印结果：
> odd  
> even  
> odd  
> odd  
> even  
> odd  

---
#### 10. 编写一些语句，从标准输入读取一个整形值，然后打印一些空白行，空白行的数量由这个值指定。
* 代码如下：
``` c
#include <stdio.h>

int main(void)
{
    int line_count = 0;
    scanf("%d", &line_count);

    for(int i = 0; i < line_count; i++)
    {
        printf("\n");
    }

    return 0;
}
```

---
#### 11. 编写一些语句，用于对一些已经读入的值进行检验和报告。如果x小于y，打印单词WRONG。同样，如果a大于或等于b，也打印WRONG。在其它情况下，打印RIGHT。注意：||操作符表示逻辑或，你可能要用到它。
* 代码如下：
``` c
#include <stdio.h>

int main(void)
{
    int x, y, a, b;
    scanf("%d %d %d %d", &x, &y, &a, &b);

    if(x < y || a >= b)
    {
        printf("WRONG\n");
    }
    else
    {
        printf("RIGHT\n");
    }

    return 0;
}
```

---
#### 12. 能够被4整除的年份是闰年，但其中能够被100整除的年份却不是闰年，除非它同时能够被400整除。请编写一些语句，判断`year`这个年份是否为闰年，如果它是闰年，把变量`leap_year`设置为1，如果不是，把`leap_year`设置为0。
* 代码如下：
``` c
#include <stdio.h>

int main(void)
{
    int year, leap_year;

    scanf("%d", &year);

    if(year % 4 == 0)
    {
        if(year % 100 == 0 && year % 400 != 0)
        {
            leap_year = 0;
        }
        else
        {
            leap_year = 1;
        }
    }
    else
    {
        leap_year = 0;
    }

    return 0;
}
```

---
#### 13. 新闻记者都受过训练，善于提问谁？什么？何时？何地？为什么？还有赛跑。请编写一些语句，如果变量`which_word`的值是1，就打印`who`，如果值为2，打印`what`，一次类推。如果变量的值不在1到5范围内，就打印`don't know`。
* 代码如下：
``` c
#include <stdio.h>

int main(void)
{
    int which_word;

    scanf("%d", &which_word);

    switch(which_word)
    {
        case 1: printf("who\n");break;
        case 2: printf("what\n");break;
        case 3: printf("when\n");break;
        case 4: printf("where\n");break;
        case 5: printf("why\n");break;
        default: printf("don't know\n");break;
    }

    return 0;
}
```

---
#### 14. 假定由一个“程序”来控制你，而且这个程序包含两个函数：`eat_hamberger()`用于让你吃汉堡包，`hungry()`函数根据你是否饥饿返回真值或假值。请编写一些语句，允许你在饥饿赶得到满足之前爱吃多少汉堡包就吃多少。
* 代码如下：
``` c
#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

void eat_hamberger();
int hungry();

int main(void)
{
    int is_hungry = hungry();

    while(is_hungry)
    {
        eat_hamberger();
        is_hungry = hungry();
    }

    return 0;
}

void eat_hamberger()
{
    printf("I eat hamberger.\n");
}

int hungry()
{
    if(rand() % 10 == 1)
    {
        return TRUE;
    }

    return FALSE;
}
```

---
#### 15. 修改你对问题14的答案，使它能够让你的祖母满意————就是你已经吃过一些东西了。也就是说，你至少必须吃一个汉堡包。
* 代码如下：
``` c
#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

void eat_hamberger();
int hungry();

int main(void)
{
    int is_hungry;

    do
    {
        eat_hamberger();
        is_hungry = hungry();
    } while(is_hungry)

    return 0;
}

void eat_hamberger()
{
    printf("I eat hamberger.\n");
}

int hungry()
{
    if(rand() % 10 == 1)
    {
        return TRUE;
    }

    return FALSE;
}
```

---
#### 16. 编写一些语句，根据变量`precipitating`和`temperature`的值打印当前天气的简单总结。
| 如果precipitating为... | 而且temperature是... | 那就打印 |
| :---- | :---- | :---- |
| true | < 32 | snowing |
|| >= 32 | raining |
| false | < 60 | cold |
|| >= 60 | warm |
* 代码如下：
``` c
#include <stdio.h>

int main(void)
{
    int precipitating, temperature;
    scanf("%d %d", &precipitating, &temperature);

    if(precipitating)
    {
        if(temperature < 32)
        {
            printf("snowing\n");
        }
        else
        {
            printf("raining\n");
        }
    }
    else
    {
        if(temperature < 60)
        {
            printf("cold\n");
        }
        else
        {
            printf("warm\n");
        }
    }

    return 0;
}
```

---

### 编程练习

#### 1. 
* pe4.1.c

#### 2. 
* pe4.2.c

#### 3. 
* pe4.3.c

#### 4. 
* pe4.4.c

#### 5. 
* pe4.5.c

#### 6. 
* pe4.6.c

#### 7. 
* pe4.7.c

---
