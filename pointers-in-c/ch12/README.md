# 第12章 使用结构和指针

---
### 问题

#### 1. 程序12.3能否进行改写，不使用current变量？如果可以，把你的答案和原先的函数做一比较。
* 修改如下：
``` c
int sll_insert4(Node** linkp, int new_value)
{
	// 寻找正确的插入位置，方法是按序访问链表，知道到达一个其值大于或等于新值的节点。
	while(*linkp != NULL && (*linkp) -> value < new_value)
	{
		linkp = &(*linkp) -> link;
	}

	// 为新节点分配内存，并把新值存储到新节点中，如果内存分配失败，函数返回FALSE
	Node* new = (Node*)malloc(sizeof(Node));
	if(new == NULL)
	{
		return FALSE;
	}
	new -> value = new_value;

	// 在链表中插入新节点，并返回TRUE
	new -> link = *linkp;
	*linkp = new;

	return TRUE;
}
```

---
#### 2. 有些数据结构课本建议在单链表中使用“头结点”。这个亚节点始终是链表的第1一个元素，这就消除了插入到链表起始位置这个特殊情况。讨论这个技巧的利与弊。
* 利那么都在题目中给出了。
* 弊可能就是会浪费空间，这个在单独节点所占空间很大时尤为可观。

---
#### 3. 在程序12.3中，插入函数会把重复的值插入到什么位置？如果把比较操作符由`<`改为`<=`会有什么效果？
* 会插到前面。
* 会插到后面。

---
#### 4. 讨论一些技巧，怎样省略双链表中根节点的值字段。
* 可以另一起个根节点结构。但没必要省略，就为这点内存？

---
#### 5. 如果程序12.7中对malloc的调用在函数的其实部分执行会怎么样？
* 这个已经在书中提到了，有可能会导致内存泄漏，因为想要插入的值不一定合法。

---
#### 6. 能不能对一个无序的单链表进行排序？
* 当然可以。

---
#### 7. 索引表是一种字母链表，表中的节点是出现于一本书或一篇文章中的单词。你可以使用一个有序的字符串单链表实现索引表，使用插入函数时不插入重复的单词。和这种实现方式有关的问题是搜索链表的时间将随着链表规模的扩大而急剧增长。
#### 图12.1说明了另一种存储索引表的数据结构。它的思路是把一个大型的链表分解为26个小型的链表————每个链表中的所有单词都以同一个字母开头。最初链表中的每个节点包含一个字母和一个指向一个有序的以该字母开头的单词的单链表（以字符串形式存储）的指针。
#### 使用这种数据结构，搜索一个特定的单词所花费的时间与使用一个存储所有单词的单链表相比，有没有什么变化？
* 对搜索“a”开头的没什么变化，对于越往后的字母开头的单词，效率提升越明显。

---
### 编程练习

#### 1. 
* sll_node/sll_node.c
* 不需要知道其它信息了，这个就是遍历。
* 代码非常简单，我也放在这里：
``` c
int ssl_len(Node* p)
{
	if(p == NULL)
	{
		return 0;
	}

	int ssl_len = 1;
	while(p -> link != NULL)
	{
		ssl_len++;
		p = p -> link;
	}

	return ssl_len;
}
```

#### 2. 
* 需要修改，对于升序（降序）只要判断当前节点的值大于（小于）所需要查找的节点的值，就可以返回查找失败了。
* 这两种代码都非常简单，我就放在这里了：
``` c
// 乱序链表查找
Node* find_node(Node* p, int value)
{
    while(p != NULL)
    {
        if(p -> value == value)
        {
            return p;
        }

        p = p -> link;
    }

    return NULL;
}
```
``` c
// 升序链表查找
Node* find_node(Node* p, int value)
{
    while(p != NULL && p -> value <= value)
    {
        if(p -> value == value)
        {
            return p;
        }

        p = p -> link;
    }

    return NULL;
}
```

#### 3. 
* ./dll_node/dll_node.c 的`int dll_insert5(Node* rootp, int value)`

#### 4. 
* ./sll_node/sll_node.c 的`Node* sll_reverse(Node* first)`

#### 5. 
* ./sll_node/sll_node.c 的`int sll_remove(Node** rootp, Node* node)`

#### 6. 
* ./dll_node/dll_node.c 的`int dll_remove(Node** rootp, Node* node)`

#### 7. 
* ./index_node

---