// 2020-12-16 created by Akson
// Code11.1a alloc.h 错误检查分配器：接口

// 定义一个不易发生错误的内存分配器
#ifndef _ALLOC_H_
#define _ALLOC_H_

#include <stdlib.h>

#define malloc donotusemallocdirectly

#define MALLOC(num,type) (type*)alloc((num) * sizeof(type))

void* alloc(size_t size);

#endif