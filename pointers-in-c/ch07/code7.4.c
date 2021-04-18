// 2020-12-08 created by Akson
// Code7.4 clarray.c 将一个数组设置为零

// 把一个数组的所有元素都设置为零

void clear_array(int array[], int n_elements)
{
	// 从数组最后一个元素开始，逐个清除数组中的所有元素。注意前缀自增避免了数组越界的可能性
	while(n_elements > 0)
	{
		array[--n_elements] = 0;
	}
}