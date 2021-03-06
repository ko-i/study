# 第4章 连接

### 练习

---
#### 1. 假定一个程序在一个源文件中包含了声明：
``` c
long foo;
```
#### 2. 而在另一个源文件中包含了：
``` c
extern short foo;
```
#### 又进一步假定，如果给long类型的foo赋一个较小的值，例如37，那么short类型的foo就同时获得了一个值37。我们能够对运行该程序做出什么样的推断？如果short类型的foo得到的值不是37而是0，我们又能够作出什么样的推断？
* 第一种情况我们可以得知，他们公用同一片存储空间，并且机器是从低位开始存储，37的低位数据也成功的呗short访问到了。
* 第二种情况可以说明这台机器是从高位开始存储的，所以读取时对于short的空间内只有0。

---
#### 2. 本章第4节中讨论的错误程序，经过适当简化后如下所示：
``` c
#include <stdio.h>

main()
{
    printf("%g\n", sqrt(2));
}
```
#### 在某些系统中打印出的结果是：
> %g
#### 请问这是为什么？
* 这可能是当前所使用的printf函数并没有实现对"%g"的格式化操作。

---