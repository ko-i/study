# 第13章 高级指针话题

---
### 问题

#### 1. 下面显示了一列声明。从下面的列表中挑出与上面各个声明匹配的最佳描述。
* 声明与相关描述如下表格，有关所有的声明描述太多就略去不写了；

| 序号 | 声明 | 描述 |
| :--- | :--- | :--- |
| a. | `int abc()` | VIII. 返回值为int的函数 |
| b. | `int abc[3]` | III. int型数组 |
| c. | `int** abc()` | X. 返回值为“int型指针的指针”的函数 |
| d. | `int (*abc)()` | XI. 返回值为“int”的函数指针 |
| e. | `int (*abc)[6]` | IV. 指向“int型”数组的指针 |
| f. | `int* abc()` | IX. 返回值为“int型指针”的函数 |
| g. | `int** (*abc[6])()` | XVI. 指向“返回值为“int**”的函数”的指针的数组 |
| h. | `int** abc[6]` | VII. int型指针的指针的数组 |
| i. | `int* (*abc)[6]` | VI. 指向int型指针数组的指针 |
| j. | `int* (*abc())()` | XIX. 返回值为“返回值为int*的函数指针”的函数 |
| k. | `int (**(*abc)())()` | XXI. 返回值为“int型函数指针的指针”的函数指针 |
| l. | `int (*(*abc)())[6]` | XXIII. 返回值为“指向int型数组的指针”的函数指针 |
| m. | `int* (*(*(*abc)())[6]` | 我不玩了 |

---
#### 2. 给定下列声明：
``` c
char *array[10];
char **ptr = array;
```
#### 如果变量ptr加上1，它的效果是什么样的？
* ptr + 1的内容是array[1]的地址。

---
#### 3. 假定你将要编写一个函数，它的起始部分如下所示：
``` c
void func(int ***arg)
```
#### 参数的类型是什么？画一张图，显示这个变量的正确用法。如果想去的这个参数所指代的整数，你应该怎样使用表达式？
* 参数的类型是一个指向整型的指针的指针的指针（没什么意思）。
* 图很好画。
* 对arg做三次解引用`***arg`即可。

---
#### 4. 下面的代码可以如何改进？
``` c
Transaction *trans;
trans -> product -> orders += 1;
trans -> product -> quantity_on_hand -= trans -> quantity;
trans -> product -> supplier -> reorder_quantity += trans -> quantity;

if(trans -> product -> export_restricted)
{
    ...
}
```
* 修改如下：
``` c
Transaction *trans;
Product** pproduct= &trans -> product;

*pproduct -> orders += 1;
*pproduct -> quantity_on_hand -= trans -> quantity;
*pproduct -> supplier -> reorder_quantity += trans -> quantity;

if(*pproduct -> export_restricted)
{
    ...
}
```
---
#### 5. 给定下列声明：
``` c
typedef struct
{
    int x;
    int y;
} Point;

Point p;
Point* a = &p;
Point** b = &a;
```
#### 判断下面各个表达式的值。
* 表达式与值如下：

| 序号 | 表达式 | 值 |
| :--- | :--- | :--- |
| a. | `a` | p的地址 |
| b. | `*a` | 结构p |
| c. | `a -> x` | x的值 |
| d. | `b` | a的地址 |
| e. | `b -> a` | 非法 |
| f. | `b -> x` | 非法 |
| g. | `*b` | p的地址 |
| h. | `*b -> a` | 非法 |
| i. | `*b -> x` | 非法 |
| j. | `b -> a -> x` | x的值 |
| k. | `(*b) -> a` | 非法 |
| l. | `(*b) -> x` | x的值 |
| m. | `**b` | 结构p |

---
#### 6. 给定下列声明：
``` c
typedef struct
{
    int x;
    int y;
} Point;

Point x, y;
Point *a = &x, *b = &y;
```
#### 解释下列各语句的含义。
* 语句与含义如下表：

| 序号 | 语句 | 含义 |
| :--- | :--- | :--- |
| a. | `x = y` | 非法 |
| b. | `a = y` | 非法 |
| c. | `a = b` | 将y的地址赋给a |
| d. | `a = *b` | 非法 |
| e. | `*a = *b` | 非法 |

---
#### 7. 许多ANSI C的实现都包含了一个函数，称为getopt。这个函数用于帮助处理命令行参数。但是，getopt在标准中并未提及。拥有这样一个函数，有什么优点？又有什么缺点？
* 处理命令行参数的需求很普遍呀看来，优点那不就是不用自己写相关的函数了么。
* 缺点可能是不方便移植？

---
#### 8. 下面的代码段有什么错误（如果有的话）？你如何修正它？
``` c
char * pathname = "/usr/temp/xxxxxxxxxxxxxxx"

// Insert the filename in to the pathname.
strcpy(pathname + 10, "abcde");
```
* 修正结果如下：  
``` c
char pathname[] = "/usr/temp/xxxxxxxxxxxxxxx";

// Append the filename in to the pathname.
strcpy(pathname + 10, "abcde");
```
---
#### 9. 下面的代码段有什么错误（如果有的话）？你如何修正它？
``` c
char pathname[] = "/usr/temp/";
...
// Append the filename in to the pathname.
strcat(pathname, "abcde");
```
* 修正结果如下：
``` c
char pathname[20] = "/usr/temp/";
...
// Append the filename in to the pathname.
strcat(pathname, "abcde");
```
---
#### 10. 下面的代码段有什么错误（如果有的话）？你如何修正它？
``` c
char *pathname[20] = "/usr/temp/";
...
// Append the filename in to the pathname.
stroat(pathname, "abcde");
```
* 修正结果如下：
``` c
char pathname[20] = "/usr/temp/";
...
// Append the filename in to the pathname.
strcat(pathname, "abcde");
```
---
#### 11. 标准表示如果对一个字符串常量进行修改，其效果是未定义的。如果你修改了字符串常量，有可能会出现什么问题呢？
* 我的编译器对此行为禁止。
* 如果修改了，那在其它地方使用此字符串的函数可能会出现奇怪的行为。

---

### 编程练习

#### 1. 
* pe13.1.c

#### 2. 
* pe13.2.c

#### 3. 
* pe13.3.c

#### 4. 
* pe13.4.c

#### 5. 
* 这个留给有缘人来完成。

---


