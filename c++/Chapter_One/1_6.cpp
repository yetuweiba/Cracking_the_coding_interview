#include <iostream>

// Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, 
// write a method to rotate the image by 90 degrees. Can you do this in place?

// 思路：先将矩阵对角线对称的元素交换，再将i行与n-i-1行交换
// 此方法是逆时针旋转90度，如果是顺时针的话，原理和这相同，只是反过来了。

int rotate_matrix(int data[][4], int len)
{
	int ret = 0;
	if (!data || len <=0)
	{
		ret = 1;
		return ret;
	}

	// 对角线交换
	for (int i = 0; i < len; ++i)
	{
		for(int j = i + 1; j < 4; ++j)
		{
			int temp = data[i][j];
			data[i][j] = data[j][i];
			data[j][i] = temp;
		}
	}

	// 将第i行和第n-i-1行交换
	for (int i = 0; i < len / 2; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			int temp = data[i][j];
			data[i][j] = data[len - i - 1][j];
			data[len - i - 1][j] = temp;
		}
	}
	return ret;
}

int test_1_6()
{
	int a[4][4] =
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	for(int i=0; i<4; ++i)
	{
		for(int j=0; j<4; ++j)
		{
			std::cout << a[i][j] <<" ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	rotate_matrix(a, 4);
	for(int i=0; i<4; ++i)
	{
		for(int j=0; j<4; ++j)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

