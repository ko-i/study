# 第14章 预处理器

---
### 问题

#### 1. 预处理器定义了5个符号，给出了进行编译的文件名，文件的当前行号，当前的日期和时间及编译器是否为ANSI C编译器。为每个符号举出一种可能的用途。
* 给出当前文件名可以用于条件编译，类似于那个python中的`if __name__ == '__main__'`
* 文件的当前行号可以用于调试。
* 当前的日期和时间，可以用来保存编译时间戳，作为版本控制。
* 是否为ANSI C编译器可以对代码中有可能出现的非ANSIC方法进行条件编译。

---
#### 2. 说出两个使用`#define`定义名字代替字面值常量的优点。
* 优点就是好维护，这是显而易见的。
* 甚至有人叫嚣在源代码中就不应该出现字面值常量。

---
#### 3. 编写一个用于调试的宏，打印出任意的表达式。它被调用时应该接受两个参数。第1个是`printf`格式码，第2个是需要打印的表达式。
* 如下：
``` c
#define PRINT(format, expression) printf("format\n", (expression)) 
```

---
#### 4. 下面的程序将打印出什么？在展开#define内容时必须非常小心！
``` c
#define MAX(a,b) (a)>(b)?(a):(b)
#define SQUARE(x) x*x
#define DOUBLE(x) x+x

main()
{
    int x, y, z;
    y = 2;
    z = 3;
    x = MAX(y,z);
    // a
    printf("%d %d %d\n", x, y, z);

    y = 2;
    z = 3;
    x = MAX(++y, ++z);
    // b
    printf("%d %d %d\n", x, y, z);

    x = 2;
    y = SQUARE(x);
    z = SQUARE(x+6);
    // c
    printf("%d %d %d\n", x, y, z);

    x = 2;
    y = 3;
    z = MAX((5*DOUBLE(x), ++y);
    // d
    printf("%d %d %d\n", x, y, z);
}
```
* 我求您少喝点酒。
* 输出如下：
> 3 2 3  
> 5 3 5  
> 2 4 20  
> 2 4 12  

---
#### 5. putchar函数定义于文件stdio.h中，尽管它的内容比较长，但它是作为一个宏实现。你认为他为什么以这种方式定义？
* 为了提高运行时的效率，不至于每次读一个字节还要调用函数开销。

---
#### 6. 下列代码是否有错？如果有错在何处？
``` c
// Process all the values in the array
result = 0;
i = 0;
while(i < SIZE)
{
    result += process(value[ i++ ]);
}
```
* 我觉得没什么问题。

---
#### 7. 下列代码是否有错？如果有错在何处？
``` c
#define SUM( value )  ( ( value ) + ( value ) )
int array[SIZE]
...
// Sum all the values in the array.
sum = 0;
i = 0;
while( i < SIZE )
    sum += SUM( array[ i++ ] );
```
* 修改如下：
``` c
#define SUM(value)  ((value)+(value))
int array[SIZE]
...
// Sum all the values in the array.
int sum = 0;
int i = 0;
while( i < SIZE )
{
    sum += SUM(array[i]);
    i++;
} 
```
---
#### 8. 下列代码是否有错？如果有错在何处？
``` c
// header1.h
#ifndef _HEADER1_H
#define _HEADER1_H

#include "header2.h"
    // 其它声明
#endif
```
``` c
// header2.h
#ifndef _HEADER2_H
#define _HEADER2_H

#include "header1.h"
    // 其它声明
#endif
```
* 我觉得没什么问题。

---
#### 9. 再一次提高程序可读性的尝试中，以为程序员编写了下面的声明。
``` c
#if sizeof( int ) == 2
    typedef long int32;
#else
    typedef int int32;
#endif
```
#### 这段代码是否有错，如果有，错在何处？
* 我觉得不能用int32重写，因为int32是已经内置的标识符。

---

### 编程练习

#### 1. 
* pe14.1.c

#### 2. 
* cpu_type/

---
