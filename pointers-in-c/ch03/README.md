# 第3章 数据

---
### 问题

#### 1. 在你的机器上，字符的范围有多大？有哪些不同的整数类型？他们的范围又是如何？
* 测试代码：
``` c
#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
	printf("CHAR_MIN: %d, CHAR_MAX: %d\n", CHAR_MIN, CHAR_MAX);
	printf("SHRT_MIN: %d, SHRT_MAX: %d\n", SHRT_MIN, SHRT_MAX);
	printf("INT_MIN: %d, INT_MAX: %d\n", INT_MIN, INT_MAX);
	printf("LONG_MIN: %ld, LONG_MAX: %ld\n", LONG_MIN, LONG_MAX);

	return 0;
}
```
* 打印结果：
> CHAR_MIN: -128, CHAR_MAX: 127  
> SHRT_MIN: -32768, SHRT_MAX: 32767  
> INT_MIN: -2147483648, INT_MAX: 2147483647  
> LONG_MIN: -9223372036854775808, LONG_MAX: 9223372036854775807  

---
#### 2. 在你的机器上，各种不同类型的浮点数的范围是怎样的？
* 测试代码：
``` c
#include <stdio.h>
#include <float.h>

int main(int argc, char const *argv[])
{
	printf("FLT_MIN: %e, FLT_MAX: %e\n", FLT_MIN, FLT_MAX);
	printf("DBL_MIN: %e, DBL_MAX: %e\n", DBL_MIN, DBL_MAX);
	printf("LDBL_MIN: %Le, LDBL_MAX: %Le\n", LDBL_MIN, LDBL_MAX);

	return 0;
}
```
* 打印结果：
> FLT_MIN: 1.175494e-38, FLT_MAX: 3.402823e+38  
> DBL_MIN: 2.225074e-308, DBL_MAX: 1.797693e+308  
> LDBL_MIN: 3.362103e-4932, LDBL_MAX: 1.189731e+4932  

---
#### 3. 假定你正编写一个程序，它必须运行于两台机器之上。这两台机器的缺省整数长度并不相同，一个是16位，另一个是32位。而这两台机器的长整形长度分别是32位和64位。程序所使用的有些变量的值并不太大，足以保存于任何一台机器的缺省变量中，但有些变量的值却较大，必须是32位的整形变量才能容纳它。一种可行的解决方案是使用长整形表示所有的值，但在16位机器上，对于那些用16位足以容纳的值而言，时间和空间的浪费不可小视。在32位机器上，也存在时间和空间浪费的问题。如果想让这些变量在任何一台机器上的长度都合适的话，你该如何声明他们呢？正确的方法是不应该在任何一台机器中编译程序前对程序进行修改。提示：试试包含一个头文件，里面包含每台机器特定的声明。
* 可以在相关程序的头文件中包含`typedef int INT;`,其中这里的`int`可以针对不同的机器改成不同的值，然后再源代码文件中所有相关的声明变量的类型均改成`INT`即可。

---
#### 4. 假定你有一个程序，它把一个long整形变量赋值给一个short整形变量。当你编译程序时会发生什么情况？当你运行程序时会发生什么情况？你认为其它编译器的结果是否也是如此？
* 测试代码：
``` c
#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
	long long_num = LONG_MAX;
	short short_num = long_num;

	printf("long num: %ld\n", long_num);
	printf("short present %ld is %d\n\n", long_num, short_num);

	long_num = SHRT_MAX;
	short_num = long_num;

	printf("long num: %ld\n", long_num);
	printf("short present %ld is %d\n\n", long_num, short_num);

	long_num = SHRT_MAX + 1;
	short_num = long_num;

	printf("long num: %ld\n", long_num);
	printf("short present %ld is %d\n\n", long_num, short_num);

	return 0;
}
```
* 打印结果：
> long num: 9223372036854775807  
> short present 9223372036854775807 is -1  
>   
> long num: 32767  
> short present 32767 is 32767  
> 
> long num: 32768  
> short present 32768 is -32768  
* 根据结果表明，如果long数字的范围大于short能表示的范围的话，那么内存中的高位可能会被截取。
* 但我的编译器并没有异常，没有警告和错误之类，不同编译器应该会有不同的处理行为。

---
#### 5. 假定你有一个程序，它把一个double变量赋值给一个float变量。当你编译程序时会发生什么情况？当你运行程序时会发生什么情况？
* 测试代码：
``` c
#include <stdio.h>
#include <float.h>

int main(int argc, char const *argv[])
{
	double double_num = 1.0;
	float float_num = double_num;

	printf("double num: %.12lf\n", double_num);
	printf("float present %.12lf is %.12f\n\n", double_num, float_num);

	double_num = 1.2345678901234;
	float_num = double_num;

	printf("double num: %.12lf\n", double_num);
	printf("float present %.12lf is %.12f\n\n", double_num, float_num);

	double_num = DBL_MAX;
	float_num = double_num;

	printf("double num: %e\n", double_num);
	printf("float present %e is %e\n\n", double_num, float_num);

	return 0;
}
```
* 打印结果：
> double num: 1.000000000000  
> float present 1.000000000000 is 1.000000000000  
> 
> double num: 1.234567890123  
> float present 1.234567890123 is 1.234567880630  
> 
> double num: 1.797693e+308  
> float present 1.797693e+308 is inf  

---
#### 6. 编写一个枚举声明，用于定义硬币的值。请使用符号PENNY、NICKEL等。
``` c
enum Coin {PENNY = 1, NICKEL = 100};
```

---
#### 7. 下列代码会打印出什么东西？
``` c
enum Liquid {OUNCE = 1, CUP = 8, PINT = 16, QUART = 32, GALLON = 128};

enum Liquid jar;
...
jar = QUART;
printf("%s\n", jar);
jar = jar + PINT;
printf("%s\n", jar);
```
* 完整的测试代码：
``` c
#include <stdio.h>

enum Liquid {OUNCE = 1, CUP = 8, PINT = 16, QUART = 32, GALLON = 128};

int main(int argc, char const *argv[])
{
	enum Liquid jar;

	jar = QUART;
	printf("%c\n", jar);
	jar = jar + PINT;
	printf("%c\n", jar);

	return 0;
}
```
* 我发现如果用`%s`来格式化输出的话会报错，所以改为了`%c`。
* 打印结果：
> &nbsp;  
> 0  
* 其中第一行为空，应该是ASCII码为32的值代表的字符空格。

---
#### 8. 你所使用的C编译器是否允许程序修改字符串常量？是否存在编译器选项，允许或禁止你修改字符串常量？
* 测试代码：
``` c
#include <stdio.h>

int main(int argc, char const *argv[])
{
	char * str = "Test";
	char * ps = str;

	printf("%s\n", str);
	
	ps += 2;
	*ps = 'a';
	printf("%s\n", str);

	return 0;
}
```
* 打印结果：
> Test  
> zsh: bus error  ./a.out  
* 可以看到修改时报了总线错误，说明我的编译器（clang）不允许修改字符串常量。
* 我未找到有关是否允许修改字符串常量的编译选项。

---
#### 9. 如果整数类型在正常情况下是有符号类型，那么`signed`关键字的目的何在呢？
* 可以对阅读代码或使用代码的人强调作用。降低代码的阅读理解难度。

---
#### 10. 一个无符号变量可不可以比相同长度的有符号变量容纳更大的值？
* 如果这个更大是数学意义上的更大，那么就是可以的。
* 书中给出的答案貌似是在针对能表示的数字数量或者范围来说，那肯定是一样的。

---
#### 11. 假如`int`和`float`类型都是32位长，你觉得哪种类型所能容纳的值精度更大一些？
* 我认为是int，虽然float能表示的范围要更大，但是他能表示的数和int是一样的，甚至如果存在某一个数（比如0）能被float格式的位多种方式表示，那么float所能表示的数字数量甚至还要比int少一些。

---
#### 12. 下面是两个代码片段，取自一个函数的其实部分：
#### 代码片段1：
``` c
int a = 25
```
#### 代码片段2：
``` c
int a;
a = 25;
```
#### 他们完成任务的方式有何不同？
* 讲道理其实没什么不同。

---
#### 13. 如果问题12中代码片段的声明中包含const关键字，他们完成任务的方式又有何不同？
* 第二个代码片段可能会失败，因为const修饰的变量只有在声明时可以初始化方式赋值，但如果声明时没有赋合适的值，那其中的值用书中的话说就是垃圾，并且之后对垃圾的修改是不允许的。

---
#### 14. 在一个代码块内部声明的变量可以从该代码块的任何位置根据名字来访问，对还是错？
* 错，还得在声明语句之后，除非声明语句在代码块的开始部分。

---
#### 15. 假定函数a声明了一个自动整形变量x，你可以再其它函数内访问变量x，只要你使用了下面这样的声明：
``` c
extern int x;
```
#### 对还是错?
* 对，而且这是唯一一种在一个函数（块）内部所声明的变量也能在函数（块）外部或其它函数（块）内使用的声明方式。

---
#### 16. 假定问题15中的变量x被声明为static。你的答案会不会有所变化？
* 会，这时候x虽具有静态存储的属性，但他现在仅限于函数内部可见。

---
#### 17. 假定文件a.c的开始部分有下面这样的声明：
``` c
int x;
```
#### 如果你希望从同一个源文件后面出现的函数中访问这个变量，需不需要添加额外的声明，如果需要的话，应该添加什么样的声明？
* 不需要，因为默认表示具有文件作用域，对于文件内部当然也是可访问的。

---
#### 18. 假定问题17中的声明中包含了关键字`static`。你的答案会不会有所变化？
* 不会，这时候就仅限文件内部访问了，对于文件内部访问还是没有影响的。

---
#### 19. 假定文件a.c的开始部分有下面这样的声明：
``` c
int x;
```
#### 如果你希望从不同的源文件的函数中访问这个变量，需不需要添加额外的声明，如果需要的话，应该添加什么样的声明？
* 不需要，因为默认表示具有文件作用域，对于文件外部的函数也是可访问的。

---
#### 20. 假定问题19中的声明中包含了关键字`static`。你的答案会不会有所变化？
* 会，这时候就仅限文件内部访问了。

--- 
#### 21. 假定一个函数包含了一个自动变量，这个函数在同一行中被调用了两次。试问，在函数第2次调用开始时该变量的值和函数第1次调用即将结束的值有无可能相同？
* 有可能，如果第一次调用是形如`x++`或`x--`这样的调用。

---
#### 22. 当下面的声明出现于某个代码块内部和出现于任意代码块外部时，他们在行为上有何不同？
``` c
int a = 5;
```
* 如果出现在代码块内部：那他是自动变量，具有代码块内作用域，无连接属性。
* 如果出现在代码块外部：那他是静态存储变量，具有文件作用域，连接属性是external。

----
#### 23. 假定你想在同一个源文件中编写两个函数x和y，需要使用下面的变量：
| 名字 | 类型 | 存储类型 | 链接属性 | 作用域 | 初始化为 |
| :---- | :---- | :---- | :---- | :---- | :----: |
| a | int | static | external | x可以访问，y不能访问 | 1 |
| b | char | static | none | x和y都可以访问 | 2 |
| c | int | automatic | none | x的局部变量 | 3 |
| d | float | static | none | x的局部变量 | 4 |
#### 你应该怎样编写这些变量？应该在什么地方编写？注意：所有初始化必须在声明中完成，而不是通过函数中任何可执行语句来完成。
* 简略的代码：
``` c
static char b = 2;

void x(void)
{
    extern int a = 1;
    int c = 3;
    static float d = 4;
}

void y(void)
{

}
```

---
#### 24. 确认下面程序中存在的任何错误（~你可能想动手编译一下~，这样能够踏实一些）。在去除所有错误之后，确定所有标识符的存储类型，作用域和链接属性。每个变量的初始值会是什么？程序中存在许多同名的标识符，他们所代表的的是相同的变量还是不同的变量？程序中的每个函数从哪个位置起可以被调用？
``` c
static int w = 5;              //  1    
extern int x;                  //  2  
static float                   //  3
func1(int a, int b, int c)     //  4   
{                              //  5    
    int c, d, e = 1;           //  6
    ...                        //  7
    {                          //  8   
        int d, e, w;           //  9
        ...                    // 10
        {                      // 11
            int b, c, d;       // 12
            static int y = 2;  // 13
            ...                // 14
        }                      // 15
    }                          // 16
    ...                        // 17
    {                          // 18
        register int a, d, x;  // 19
        extern int y;          // 20
        ...                    // 21
    }                          // 22
}                              // 23
static int y;                  // 24
float                          // 25
func2(int a)                   // 26
{                              // 27
    extern int y;              // 28
    static int z;              // 29
    ...                        // 30
}                              // 31
```
* 第4行和第6行的c定义重复冲突。
* 第20行和第24行的y声明(static与extern)冲突.
* 可以修改成以下这种方式：
``` c
static int w = 5;              //  1    
extern int x;                  //  2  
static float                   //  3
func1(int a, int b, int c)     //  4   
{                              //  5    
    int d, e = 1;              //  6
    ...                        //  7
    {                          //  8   
        int d, e, w;           //  9
        ...                    // 10
        {                      // 11
            int b, c, d;       // 12
            static int y = 2;  // 13
            ...                // 14
        }                      // 15
    }                          // 16
    ...                        // 17
    {                          // 18
        register int a, d, x;  // 19
        int y;                 // 20
        ...                    // 21
    }                          // 22
}                              // 23
static int y;                  // 24
float                          // 25
func2(int a)                   // 26
{                              // 27
    extern int y;              // 28
    static int z;              // 29
    ...                        // 30
}                              // 31
```

| 名字 | 行数 | 类型 | 存储类型 | 链接属性 | 初始值 | 作用行数范围 |
| :----: | :---- | :----: | :---- | :---- | :---- | :---- |
| w | 1 | int | static | internal | 5 | (1)~(31) |
| x | 2 | int | static | external | 0 | (3)\~(17) (23)\~(31) |
| a | 4 | int | auto | none | unknown | (4)~(17) |
| b | 4 | int | auto | none | unknown | (4)\~(10) (16)\~(23) |
| c | 4 | int | auto | none | unknown | (4)\~(10) (16)\~(23) |
| d | 6 | int | auto | none | unknown | (6)~(7) (17) |
| e | 6 | int | auto | none | 1 | (6)\~(7) (17)\~(23) |
| d | 9 | int | auto | none | unknown | (9)~(10) |
| e | 9 | int | auto | none | unknown | (9)~(15) |
| w | 9 | int | auto | none | unknown | (9)~(15) |
| b | 12 | int | auto | none | unknown | (12)~(15) |
| c | 12 | int | auto | none | unknown | (12)~(15) |
| d | 12 | int | auto | none | unknown | (12)~(15) |
| y | 13 | int | static | none | 2 | (13)~(15) |
| a | 19 | int | register | none | unknown | (19)~(22) |
| d | 19 | int | register | none | unknown | (19)~(22) |
| x | 19 | int | register | none | unknown | (19)~(22) |
| y | 20 | int | auto | none | unknown | (20)~(22) |
| y | 24 | int | static | internal | 0 | (1)\~(10) (16)\~(17) (24)\~(31) |
| a | 26 | int | auto | none | unknown | (26)~(31) |
| y | 28 | int | static | external | 0 | (24)~(31)(和24行的y等效) |
| z | 29 | int | static | none | 0 | (29)~(31) |

---