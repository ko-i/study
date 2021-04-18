# 第10章 结构和联合
 
---
### 问题

#### 1. 成员和数组元素有什么区别？
* 成员的类型可以是不相同的。

---
#### 2. 结构名和数组名有什么不同？
* 结构名是一个标量，表示一个结构。数组名是一个常量指针，指向一个数组的首地址。

---
#### 3. 结构声明的语法有几个可选部分。请列出所有合法的结构声明形式，并解释每一个是如何实现的。
* 每种声明与实现如下：
``` c
// 声明及实现
struct 
{
    int a;
    float b;
    char c;
} MyStruct;
```
* 第二种：
``` c
// 声明
struct MyStruct
{
    int a;
    float b;
    char c;
};

// 实现
struct MyStruct my_struct;
```
* 第三种：
``` c
// 声明
typedef struct
{
    int a;
    float b;
    char c;
} MyStruct;

// 实现
MyStruct my_struct;
```

---
#### 4. 下面的程序段有没有错误？如果有，错误在哪里？
``` c
struct abc {
    int a;
    int b;
    int c;
};
...
abc.a = 25;
abc.b = 15;
abc.c = -1;
```
* 这个`abc`只是标签，不能把它当结构来使用。

---
#### 5. 下面的程序段有没有错误？如果有，错误在哪里？
``` c
typedef struct {
    int a;
    int b;
    int c;
} abc;
...
abc.a = 25;
abc.b = 15;
abc.c = -1;
```
* 这道题的答案同上，这里的`abc`都是标签，并不是结构变量。

---
#### 6. 完成下面声明中对x的初始化，使成员a为3，b为字符串“hello”，c为0.你可以假设x存储于静态内存中。
``` c
struct {
    int a;
    char b[10];
    float c;
} x = {3, "hello", 0};
```

---
#### 7. 考虑下面这些声明和数据。
``` c
struct NODE {
    int a;
    struct NODE *b;
    struct NODE *c;
};

struct NODE nodes[5] = {
    {5, nodes + 3, NULL},
    {15, nodes + 4, nodes + 3},
    {22, NULL, nodes + 4},
    {12, nodes + 1, nodes},
    {18, nodes + 2, nodes + 1}
};
...
struct NODE *np = nodes + 2;
struct NODE **npp = &nodes[1].b;
```
#### 对下面每个表达式求值，并写出它的值。同时，写明任何表达式求值过程中可能出现的副作用。你应该用最初显示的值对每个表达式求值（也就是说，不要使用某个表达式的结果来对下一个表达式求值）。假定nodes数组在内存中的起始位置为200，并且在这台机器上整数和指针的长度都是4个字节。
* 表达式与相关答案如下表：

| 表达式 | 值 | 表达式 | 值 |
| :--- | :--- | :--- | :--- |
| `nodes` | 200 | `&nodes[3].c -> a` | 200 |
| `nodes.a` | Invalid | `&nodes -> a` | 200 |
| `nodes[3].a` | 12 | `np` | 224 |
| `nodes[3].c` | 200 | `np -> a` | 22 |
| `nodes[3].c -> a` | 5 | `np -> c -> c -> a` | 15 |
| `*nodes` | `{5, nodes + 3, NULL}` | `npp` | 216 |
| `*nodes.a` | Invalid | `npp -> a` | Invalid |
| `(*nodes).a` | 5 | `*npp` | 248 |
| `nodes -> a` | 5 | `**npp` | `{18, nodes + 2, nodes + 1}` |
| `nodes[3].b -> b` | 248 | `*npp -> a` | Invalid |
| `*nodes[3].b -> b` | `{18, nodes + 2, nodes + 1}` | `(*npp) -> a` | 18 |
| `&nodes` | 200 | `&np` | 未知 |
| `&nodes[3].a` | 236 | `&np -> a` | 224 |
| `&nodes[3].c` | 244 | `&np -> c -> c -> a` | 212 |

---
#### 8. 在一个16位的机器上，下面这个结构由于边界对齐浪费了多少空间？在一个32位的机器上又如何？
``` c
struct {
    char a;
    int b;
    char c;
};
```
* 16位上浪费了16位（2字节）的空间。
* 32位上浪费了48位（6字节）的空间。

---
#### 9. 至少说出两个位段不可移植的理由：
* 机器的大端小端模式会不相同。
* 依赖于特定位数。

---
#### 10. 编写一个声明，允许根据下面的格式方便地访问一个浮点值的单独部分。
* 声明如下：
``` c
struct my_float{
    unsigned int my_sign : 1;
    unsigned int exponent : 7;
    unsigned int fraction : 24;
};
```

---
#### 11. 如果不使用位段，你怎样实现西面这段代码的功能？假定你使用的是一台16位的机器，它从左向右为位段分配内存。
``` c
struct {
    int a : 4;
    int b : 8;
    int c : 3;
    int d : 1;
} x;
...
x.a = aaa;
x.b = bbb;
x.c = ccc;
x.d = ddd;
```
* 以下是我的方法：
``` c
unsigned int x = 0;

x |= (aaa << 12);
x |= (bbb << 4);
x |= (ccc << 1);
x |= ddd;
```

---
#### 12. 下面这个代码段将打印出什么？
``` c
struct {
    int a : 2;
} x;
...
x.a = 1;
x.a += 1;
printf("%d\n", x.a);
```
* 将打印如下结果：
> -2

---
#### 13. 下面的代码段有没有错误，如果有，错误有哪里？
``` c
union {
    int a;
    float b;
    char c;
} x;
...
x.a = 25;
x.b = 3.14;
x.c = 'x';
printf("%d %g %c\n", x.a, x.b, x.c);
```
* 没什么问题，不会报错。但输出的值会很奇怪，可能应当把`union`改成`struct`。

---
#### 14. 假定有一些信息已经赋值给一个联合变量，我们该如何正确的提取这个信息呢？
* 再使用一个枚举变量表明当前的联合变量是按哪种类型在使用的。

---
#### 15. 下面的结构可以被一个BASIC解释器使用，用于记住变量的类型和值。
``` c
struct VARIABLE {
    enum {INT, FLOAT, STRING} type;
    union {
        int i;
        float f;
        char *s;
    } value;
};
```
#### 如果结构改写成下面这种形式，会有什么不同呢？
``` c
struct VARIABLE {
    enum {INT, FLOAT, STRING} type;
    union {
        int i;
        float f;
        char s[MAX_STRING_LENGTH];
    } value;
};
```
* 整个结构的大小会随着`MAX_STRING_LENGTH`的值而改变，这个值可能很大，从而会浪费较多的空间。

---

### 编程练习

#### 1. 
* pe10.1.c

#### 2. 
* pe10.2.c

#### 3. 
* pe10.3.c

---