# 第5章 库函数

### 练习

---
#### 1. 当一个程序异常终止时，程序输出的最后几行常常会丢失，原因是什么？我们能够采取怎样的措施来解决这个问题？
* 原因是输出采用了缓冲的方式，如果异常终止时缓冲中还有未刷新的内容，这些内容就会丢失。
* 可以采用不缓冲的方式。

---
#### 2. 下面程序的作用是把它的输入复制到输出：
``` c
#include <stdio.h>

main()
{
    register int c;

    while((c = getchar()) != EOF)
        putchar(c);
}
```
#### 从这个程序中去掉#include语句，将导致程序不能通过编译，因为这时EOF是未定义的。假定我们手工定义了EOF（当然，这是一种不好的做法）：
``` c
#define EOF -1

main()
{
    register int c;

    while((c = getchar()) != EOF)
        putchar(c);
}
```
#### 这个程序在许多系统中仍然能够运行，但是在某些系统运行起来却慢的多。这是为什么？
* 在库函数中puchar()是通过宏实现的，其运行速度要比通过函数调用快，而不引人库函数的结果就是通过函数调用来使用getchar()。

---