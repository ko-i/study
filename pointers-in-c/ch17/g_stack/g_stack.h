// 2020-12-23 created by Akson
// Code17.10a g_stack.h 泛型数组堆栈

// 用静态数组实现一个泛型的堆栈。数组的长度当堆栈实例化时作为参数给出。

#include <assert.h>

#define GENERIC_STACK(STACK_TYPE, SUFFIX, STACK_SIZE) 	\

static STACK_TYPE stack##SUFFIX[STACK_SIZE];    		\
static int top_element##SUFFIX = -1;            		\
                                                		\
int is_empty##SUFFIX(void)                      		\
{                            							\
	return top_element##SUFFIX == -1;					\
}														\
														\
int is_full##SUFFIX(void)								\
{														\
	return top_element##SUFFIX == STACK_SIZE - 1;		\
}														\
														\
void push##SUFFIX(STACK_TYPE value)						\
{														\
	assert(!is_full##SUFFIX());							\
	top_element##SUFFIX++;								\
	stack##SUFFIX[top_element##SUFFIX] = value;			\
}														\
														\
void pop##SUFFIX(void)									\
{														\
	assert(!is_empty##SUFFIX());						\
	top_element##SUFFIX--;								\
}														\
														\
STACK_TYPE top##SUFFIX(void)							\
{														\
	assert(!is_empty##SUFFIX());						\
	return stack##SUFFIX[top_element##SUFFIX] = value;	\
}														\