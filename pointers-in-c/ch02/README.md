# 第2章 基本概念

---
### 问题

#### 1. 在C语言中，注释不允许嵌套。在下面的代码段中，用注释来“注释掉”一段语句会导致什么结果？
``` c
void squares(int limit)
{
/* Comment out this entire function
    int i; /* loop conter */

    /*
    ** print table of squares
    */
   for(i = 0; i < limit; i++>)
   {
       printf("%d %d0, i, i * i);
   }

   End of commented-out code */
}
```
* 正如上面的例子显示的这样，在`/* */`之间的`/*`会失去作用，导致最后匹配的数量不符。

---
#### 2. 把一个大型程序放入一个单一的源文件中有什么优点？有什么缺点？
* 我看不出来吧大型程序放在一个单一的源文件中有什么优点，可能是简便了编译指令输入？方便转移？
* 缺点就很多了，最主要的就是不方便以后的阅读修改维护，然后只要有一点修改就要重新编译整个源文件，降低了效率。

---
#### 3. 你需要用printf函数打印出下面这段文本（包括两边的双引号）。你应该使用什么样的字符串常量参数？
`"Blunder??!??"`
``` c
#include <stdio.h>

int main(void)
{
    printf("\"Blunder\?\?!\?\?\"\n");

    return 0;
}
```

---
#### 4. `\40`的值是多少？`\100`、`\x40`、`\x100`、`\0123`、`\x0123`的值又分别是多少？
* 分别是：' '， '@'， '@'， 超出范围，'\n'3， 超出范围。

---
#### 5. 下面这条语句的结果是什么？`int x/*blah blah*/y;`
``` c
int x y;
```

---
#### 6. 下面的声明存在什么错误（如果有的话）？`int Case, If, While, Stop, stop;`
* Case, If, While有可能会出问题，如果编译器的设置形式是对前6位大小写不敏感的话。

---
#### 7. 是非题：因为C（除了预处理指令外）是一种自由形式的语言，唯一规定程序应如何编写的规则就是语法规则，所以程序实际看上去的样子无关紧要。
* 这样的想法是不合适的，因为程序写完之后很大概率是要在之后进行修改和维护的，如果程序代码的组织非常混乱不易阅读和理解，这样会给后续的维护工作带来很大的麻烦。

---
#### 8. 下面程序中的循环是否正确？
``` c
#include <stdio.h>

int main(void)
{
    int x, y;

    x = 0;
    while(x < 10>)
    {
        y = x * x;
        printf("%d\t%d\n", x, y);
        x += 1;
    }
```
#### 这个程序中的循环是否正确？
``` c
#include <stdio.h>

int main(void)
{
    int x, y;

    x = 0;
    while(x < 10>)
    {
        y = x * x;
        printf("%d\t%d\n", x, y);
        x += 1;
}
```
#### 哪个程序更易于检查其正确性？
* 对于循环来说都是正确的，但是两者都缺少了一个`}`会造成程序错误。
* 第一个更易于检查，因为第一个可以更明显的看出来少了一个`}`。

---
#### 9. 假定你有一个C程序，它的main函数位于文件main.c，它还有一些函数位于文件list.c和report.c。在编译和链接这个程序时，你应该使用什么命令？
* `clang main.c list.c report.c`
* `clang a.out`

---
#### 10. 接上题，如果你想使程序链接到parse函数库，你应该对命令做何修改？
* `clang main.c list.c report.c -lname parse`
* `clang a.out`

---
#### 11. 假定你有一个C程序，它由几个单独的文件组成，而这几个文件又分别包含了其他文件，如下所示
| 文件 | 包含文件 |
| :----: | :----: |
| main.c | stdio.h, table.h |
| list.c | list.h |
| symbol.c | symbol.h |
| table.c | table.h |
| table.h | symbol.h, list.h |
#### 如果你对list.c做了修改，你应该用什么命令进行重新编译？如果是list.h或者table.h做了修改，又分别应该使用什么命令？
* `clang main.o symbol.o table.o list.c`
* `clang symbol.o main.c list.c table.c`

---

### 编程练习

#### 1. 
* pe2.1

#### 2. 
* pe2.2.c