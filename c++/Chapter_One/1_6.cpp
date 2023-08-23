#include <iostream>

// Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, 
// write a method to rotate the image by 90 degrees. Can you do this in place?

// ˼·���Ƚ�����Խ��߶ԳƵ�Ԫ�ؽ������ٽ�i����n-i-1�н���
// �˷�������ʱ����ת90�ȣ������˳ʱ��Ļ���ԭ�������ͬ��ֻ�Ƿ������ˡ�

int rotate_matrix(int data[][4], int len)
{
	int ret = 0;
	if (!data || len <=0)
	{
		ret = 1;
		return ret;
	}

	// �Խ��߽���
	for (int i = 0; i < len; ++i)
	{
		for(int j = i + 1; j < 4; ++j)
		{
			int temp = data[i][j];
			data[i][j] = data[j][i];
			data[j][i] = temp;
		}
	}

	// ����i�к͵�n-i-1�н���
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

