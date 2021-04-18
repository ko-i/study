// 2020-12-08 created by Akson
// Code7.2 parity.c 奇偶校验

// 对值进行偶校验

int even_parity(int value, int n_bits)
{
	int parity = 0;

	// 计数值中值为1的位的个数
	while(n_bits > 0)
	{
		parity += value & 1;
		value >>= 1;
		n_bits -= 1;
	}

	// 如果计数器的最低位是0，返回TRUE（表示1的位数为偶数个）
	return (parity % 2) == 0;
}