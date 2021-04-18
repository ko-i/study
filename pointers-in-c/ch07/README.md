# 第7章 函数

---
### 问题

#### 1. 具有空函数体的函数可以作为存根使用，你如何对这类函数进行修改，使其更加有用？
* 可以在其中打印一些语句，说明自己被成功调用。

---
#### 2. 在ANSI C中，函数的原型非必须。请问这个规定是优点还是缺点？
* 是缺点。当有一个函数原型的清单列表在程序较前的位置时，可以让人更好的注意与了解本源代码所需要的一些函数调用的简要但重点的信息。

---
#### 3. 如果在一个函数声明中，它的返回值类型为A，但他的函数体内有一条return语句，返回了一个类型为B的表达式。请问，这将导致什么后果？
* 编译器报错。

---
#### 4. 如果一个函数声明的返回类型为void，但它的函数体内包含了一条return语句，返回了一个表达式。请问，这将导致什么后果？
* 这个返回表达式会被解释成整型。

---
#### 5. 如果一个函数被调用之前，编译器无法看到它的原型，那么当这个函数返回一个不是整形的值时，会发生什么情况？
* 返回结果会被转换为整型。

---
#### 6. 如果一个函数被调用之前，编译器无法看到它的原型，那么当这个函数被调用时，实际传给他的参数与它的形式参数不匹配，会发生什么情况？
* 会将实际传入的参数进行缺省提升：char，short转换为int，float转换为double。

---
#### 7. 下面的函数有没有错误？如果有，错在哪里？
``` c
int find_max(int array[10])
{
    int i;
    int max = array[0];
    for(int i = 1; i < 10; i++)
    {
        if(array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}
```
* 它只能对数组大小为10的数组进行运算，如果传入其他大小的数组，会引起异常。

---
#### 8. 递归和while循环之间是如何相似的？
* 他们都会重复进行某项操作直到某个条件达成。

---
#### 9. 请解释把函数原型单独放在#include文件中的优点。
* 方便使用此程序的用户快速获取使用方法。
* 也对用户隐蔽的实现细节。
* 降低模块之间的耦合度，方便维护与修改。

---
#### 10. 在你的系统中，进入递归形式的斐波那契数列，并在函数的起始处增加一条语句，它增加一个全局整形变量的值。现在编写一个main函数，把这个全局变量设置为0并计算`Fibonacci(1)`。重复这个过程，计算`Fibonacci(2)`至`Fibonacci(10)`。在每个计算过程中分别调用了几次Fibonacci函数（用这个变量值表示）？这个全局变量的值增加和斐波那契数列本身有没有任何关联？基于上面这些信息，你能不能计算出`Fibonacci(11)`、`Fibonacci(25)`、`Fibonacci(50)`分别调用了多少次Fibonacci函数？
* 代码：p7.10.c
``` c
#include <stdio.h>

static long long count = 0;

long long Fibonacci(int n);

int main(int argc, char const *argv[])
{
	for(int i = 1; i < 51; i++)
	{
		count = 0;
		long long result = Fibonacci(i);
		printf("Fibonacci(%d) = %lld, call Fibo count: %lld\n", i, result, count);
	}

	printf("Bye!\n");

	return 0;
}

long long Fibonacci(int n)
{
	count++;
	if(n == 0 || n == 1)
	{
		return 1;
	}

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
```
* 运行结果：  
> Fibonacci(1) = 1, call Fibo count: 1  
> Fibonacci(2) = 2, call Fibo count: 3  
> Fibonacci(3) = 3, call Fibo count: 5  
> Fibonacci(4) = 5, call Fibo count: 9  
> Fibonacci(5) = 8, call Fibo count: 15  
> Fibonacci(6) = 13, call Fibo count: 25  
> Fibonacci(7) = 21, call Fibo count: 41  
> Fibonacci(8) = 34, call Fibo count: 67  
> Fibonacci(9) = 55, call Fibo count: 109  
> Fibonacci(10) = 89, call Fibo count: 177  
> Fibonacci(11) = 144, call Fibo count: 287  
> Fibonacci(12) = 233, call Fibo count: 465  
> Fibonacci(13) = 377, call Fibo count: 753  
> Fibonacci(14) = 610, call Fibo count: 1219  
> Fibonacci(15) = 987, call Fibo count: 1973  
> Fibonacci(16) = 1597, call Fibo count: 3193  
> Fibonacci(17) = 2584, call Fibo count: 5167  
> Fibonacci(18) = 4181, call Fibo count: 8361  
> Fibonacci(19) = 6765, call Fibo count: 13529  
> Fibonacci(20) = 10946, call Fibo count: 21891  
> Fibonacci(21) = 17711, call Fibo count: 35421  
> Fibonacci(22) = 28657, call Fibo count: 57313  
> Fibonacci(23) = 46368, call Fibo count: 92735  
> Fibonacci(24) = 75025, call Fibo count: 150049  
> Fibonacci(25) = 121393, call Fibo count: 242785  
> Fibonacci(26) = 196418, call Fibo count: 392835  
> Fibonacci(27) = 317811, call Fibo count: 635621  
> Fibonacci(28) = 514229, call Fibo count: 1028457  
> Fibonacci(29) = 832040, call Fibo count: 1664079  
> Fibonacci(30) = 1346269, call Fibo count: 2692537  
> Fibonacci(31) = 2178309, call Fibo count: 4356617  
> Fibonacci(32) = 3524578, call Fibo count: 7049155  
> Fibonacci(33) = 5702887, call Fibo count: 11405773  
> Fibonacci(34) = 9227465, call Fibo count: 18454929  
> Fibonacci(35) = 14930352, call Fibo count: 29860703  
> Fibonacci(36) = 24157817, call Fibo count: 48315633  
> Fibonacci(37) = 39088169, call Fibo count: 78176337  
> Fibonacci(38) = 63245986, call Fibo count: 126491971  
> Fibonacci(39) = 102334155, call Fibo count: 204668309  
> Fibonacci(40) = 165580141, call Fibo count: 331160281  
> Fibonacci(41) = 267914296, call Fibo count: 535828591  
> Fibonacci(42) = 433494437, call Fibo count: 866988873  
> Fibonacci(43) = 701408733, call Fibo count: 1402817465  
> Fibonacci(44) = 1134903170, call Fibo count: 2269806339  
> Fibonacci(45) = 1836311903, call Fibo count: 3672623805  
> Fibonacci(46) = 2971215073, call Fibo count: 5942430145  
> Fibonacci(47) = 4807526976, call Fibo count: 9615053951  
> Fibonacci(48) = 7778742049, call Fibo count: 15557484097  
> Fibonacci(49) = 12586269025, call Fibo count: 25172538049  
> Fibonacci(50) = 20365011074, call Fibo count: 40730022147  
> Bye!  

---

### 编程练习

#### 1. 
* pe7.1.c

#### 2. 
* pe7.2.c

#### 3. 
* pe7.3.c

#### 4. 
* pe7.4.c

#### 5. 
* pe7.5.c

#### 6. 
* pe7.6.c

---