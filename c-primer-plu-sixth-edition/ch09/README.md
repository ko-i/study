# 第9章 函数

---
### 复习题：
---
##### 1. 实际参数和形式参数有什么区别？
> 实际参数是值，形式参数就是个名儿。
---
##### 2. 根据下面个函数的描述，分别编写他们的ANSIC函数头。注意，只需写出函数头，不用写出函数体。
> * void donut(int n);
> * int gear(int a, int b);
> * int guess(void);
> * void stuff_it(double a, double * b);
---
##### 3. 根据下面个函数的描述，分别编写他们的ANSIC函数头。注意，只需写出函数头，不用写出函数体。
> * char n_to_char(int a);
> * int digit(double a, int b);
> * double* which(double * a, double * b);
> * int random(void);
---
##### 4. 设计一个函数，返回两个整数之和。
``` c
int sum(int a, int b)
{
    return a + b;
}
```
---
##### 5. 如果把复习题4改成返回两个double类型的值之和，应该如何修改？
``` c
double sum(double a, double b)
{
    return a + b;
}
```
---
##### 6. 设计一个名为alter()的函数，接受两个int类型的变量x和y，把他们的值分别改成两个变量之和与两个变量之差。
``` c
void alter(int * x, int * y)
{
    int tempX = *x;
    int tempY = *y;

    *x = tempX + tempY;
    *y = tempX - tempY;
}
```
---
##### 7. 下面的函数定义是否正确。
> 不正确，num没类型。
---
##### 8. 编写一个函数，返回三个整数参数中的最大值。
``` c
int max(int a, int b, int c)
{
    if(b > a)
    {
        a = b;
    }

    return (a > c) ? a : c;
}
```
---
##### 9. 给定下面输出...
> hw9.09.c
---
### 编程练习
---
##### 1. 
> pp9.01.c
##### 2. 
> pp9.02.c
##### 3. 
> pp9.03.c
##### 4. 
> pp9.04.c
##### 5. 
> pp9.05.c
##### 6. 
> pp9.06.c
##### 7. 
> pp9.07.c
##### 8. 
> pp9.08.c
##### 9. 
> pp9.09.c
##### 10. 
> pp9.10.c
##### 11. 
> pp9.11.c
