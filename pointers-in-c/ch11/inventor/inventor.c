// 2020-12-16 created by Akson
// Code11.4b invcreat.c 动态创建变体记录
// Code11.4c invdelet.c 变体记录的销毁

#include <stdlib.h>
#include <stdio.h>
#include "inventor.h"

// 用于创建SUBASSEMBLY（装配件）存货记录的函数。
Invrec* create_subassy_record(int n_parts)
{
	// 试图为Invrec部分分配内存
	Invrec* new_rec = (Invrec*)malloc(sizeof(Invrec));
	// 内存分配失败
	if(new_rec == NULL)
	{
		return NULL;
	}

	// 内存分配成功，现在存储SUBASSYINFO部分。
	new_rec -> info.subassy = (Subassyinfo*)malloc(sizeof(Subassyinfo));
	// 内存分配失败
	if(new_rec -> info.subassy == NULL)
	{
		// 释放之前分配的内存
		free(new_rec);
		return NULL;
	}

	// 内存分配成功，为零件获取一个足够大的数组。
	new_rec -> info.subassy -> part = (struct SUBASSYPART*)malloc(n_parts * sizeof(struct SUBASSYPART));
	// 如果分配失败
	if(new_rec -> info.subassy -> part == NULL)
	{
		// 释放之前分配的内存
		free(new_rec -> info.subassy);
		free(new_rec);
		return NULL;
	}

	// 分配成功，填充我们已知的字段，然后返回。
	new_rec -> type = SUBASSY;
	new_rec -> info.subassy -> n_parts = n_parts;
	return new_rec;
}

// 释放存货记录的函数。
void discard_inventory_record(Invrec* record)
{
	// 删除记录中的变体部分
	switch(record -> type)
	{
		case SUBASSY:
		{
			free(record -> info.subassy -> part);
			free(record -> info.subassy);
			break;
		}
		case PART:
		{
			free(record -> info.part);
			break;
		}
	}

	// 删除记录的主体部分
	free(record);
}