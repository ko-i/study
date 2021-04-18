# 第3章 语义“陷阱”

### 练习

---
#### 1. 假定对于下标越界的数组元素即使取其地址也是非法的，那么本书3.6节中的bufwrite程序应该如何写呢？
* 将`if(bufptr == &buffer[N])`改为`if(bufptr > &buffer[N - 1])`。

---
#### 2. 比较本书3.6节中函数flush的最后一个版本与以下版本：
``` c
void flush()
{
    int row;
    int k = bufptr - buffer;
    if(k > NROWS)
        k = NROWS;
    for(row = 0; row < k; row++)
    {
        int *p;
        for(p = buffer + row; p < bufptr; p += NROWS)
            printnum(*p);
        printnl();
    }
    if(k > 0)
        printpage();
}
```
* 可以看到在之前的循环中少了对k是否大于0的检验，但好像也并没有影响呀。

---
#### 3. 编写一个函数，对一个已排序的整数表执行二分查找。函数的输入包括一个指向表头的指针，表中的元素个数，以及待查找的数值。函数的输出是一个指向满足查找要求的元素的指针，当未查找到满足要求的数值时，输出一个NULL指针。
``` c
int* binary_search(int* nums, int n, int target)
{
    int left = 0;
    int right = n - 1;
    int mid = (left + right) / 2;

    do
    {
        if(nums[mid] == target)
        {
            return &nums[mid];
        }

        if(nums[mid] < target)
        {
            left = mid;
        }

        if(nums[mid] > target)
        {
            right = mid;
        }

        mid = (left + right) / 2;
    } while(left != right && mid != right && mid != left);

    if(nums[mid] == target)
    {
        return &nums[mid];
    }

    if(nums[left] == target)
    {
        return &nums[left];
    }

    if(nums[right] == target)
    {
        return &nums[right];
    }

    return NULL;
}
```

---