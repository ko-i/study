# 第11章 动态内存分配

---
### 问题

#### 1. 在你的系统中，你能够声明的静态数组最大程度能达到多少？使用动态内存分配，你能获得的最大内存够快有多大？
* 静态测试样例代码：
``` c
#include <stdio.h>

#define MAXSIZE 8000000
int main(int argc, char const *argv[])
{
    char array[MAXSIZE];
    printf("Success for %d\n", MAXSIZE);
    
    return 0;
}
```
* 我的电脑最多到8000000不会报错。
* 下面是动态内存分配测试：
``` c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int max = 1;
    char* ch = (char*)malloc(max * sizeof(char));
    while(ch != NULL)
    {
    	free(ch);
    	max += 1000;
    	ch = (char*)malloc(max * 10000 * sizeof(char));
    }

    printf("Break in %d0000\n", max);
    
    return 0;
}
```
* 打印输出：
> test(95276,0x110d66e00) malloc: can't allocate region  
> :*** mach_vm_map(size=18446744071564595200, flags: 100) failed (error code=3)  
> test(95276,0x110d66e00) malloc: *** set a breakpoint in malloc_error_break to debug  
> Break in 2150010000
* 所以最多分配了2150010000字节的空间，大概2G的空间

---
#### 2. 当你一次请求分配500个字节的内存时，你实际获得的动态内存分配的内存数量总共有多大？当你一次请求分配5000个字节时又如何？他们存在区别吗？如果有，你如何解释？
* 以目前的机器来说，应该是4字节的倍数，500与5000刚好可以被4整除，所以就是他原来的大小。

---
#### 3. 在一个从文件读取字符串的程序中，有没有什么值可以合乎逻辑的作为输入缓冲区的长度？
* 我觉得没有。

---
#### 4. 有些C编译器提供了一个成为alloca的函数，它与malloc函数的不同之处在于它在对站上分配内存。这种类型的分配有什么优点和缺点？
* 堆栈上分配的内存可以伴随函数的返回而被自动销毁。这可能既是优点也是缺点。

---
#### 5. 下面的程序用于读取整数，整数的范围在1和从标准输入读取的size之间，它返回每个值出现的次数。这个程序包含了几个错误，你能找出他们吗？
``` c
#include <stdlib.h>

int* frequency(int size)
{
    int* array;
    int i;

    /*
    **获得足够多的内存来容纳计数
    */
    arry = (int*)malloc(size * 2)

    /*
    **调整指针，让它后退一个整型位置，这样我们就可以使用范围1-size的下标。
    */
    arry - = 1;

    /*
    ** 把各个元素值清零。
    for(i = 0; i <= size; i++)
        array[i] = 0;

    /*
    ** 计数每个值出现的次数，然后返回结果。
    */
    while(scanf(*%d*, &i) = = ) )
        arry[ i ] +=1;

        free(arry);
        return arry;
}
```
* 这愚蠢的代码，但凡吃几粒头孢，也不至于写成这样。修改如下：
``` c
#include <stdlib.h>

int* frequency(int size)
{
    int* array;
    int i;

    /*
    **获得足够多的内存来容纳计数
    */
    array = (int*)malloc((size + 1) * sizeof(int));

    /*
    ** 把各个元素值清零。
    */
    for(i = 0; i <= size; i++)
    {
        array[i] = 0;
    }
        
    /*
    ** 计数每个值出现的次数，然后返回结果。
    */
    while(scanf("%d", &i) == 1)
    {
        array[i] += 1;
    }

    return array;
}
```

---
#### 6. 假定你需要编写一个程序，并希望最大限度的减少堆栈的使用量。动态内存分配能不能对你有所帮助？使用标量数据又该如何？
* 动态内存可以对我有所帮助。标量数据可以申请为静态类型。

---
#### 7. 在程序11.4b中，删除两个free函数的调用会导致什么后果？
* 显然会内存泄漏。

---

### 编程练习

#### 1. 
* pe11.1.c

#### 2. 
* pe11.2.c

#### 3. 
* pe11.3.c

#### 4. 
* pe11.4.c

---

