#include <iostream>

// Write an algorithm such that if an element in an MxN matrix is 0, 
// its entire row and column is set to 0.

// 实现想不起给函数器什么名字，就拿最通用的吧
// 此方法的时间复杂度为O(n^2)
int fun(int **data, const int row, const int column)
{
	int ret = 0;
	if (!data 
		|| row <= 0
		|| column <= 0)
	{
		ret = 1;
		return ret;
	}

	bool *rows = new bool(sizeof(bool));
	memset(rows, 0, sizeof(rows));
	bool *columns = new bool(sizeof(bool));
	memset(columns, 0, sizeof(columns));

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			if (data[i][j] == 0)
			{
				rows[i] = true;
				columns[j] = true;
			}
		}
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			if (rows[i] || columns[j])
			{
				data[i][j] = 0;
			}
		}
	}

	return ret;
}

int test_1_7()
{
	int **a = new int*[4];
	for (int i = 0; i < 4; ++i)
	{
		a[i] = new int[4];
	}
	for(int i=0; i<4; ++i)
	{
		for(int j=0; j<4; ++j)
		{
			a[i][j] = 3;
		}
	}
	for(int i=0; i<4; ++i)
	{
		for(int j=0; j<4; ++j)
		{
			std::cout << a[i][j] <<" ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	a[1][2] = 0;
	fun(a, 4, 4);
	for(int i=0; i<4; ++i)
	{
		for(int j=0; j<4; ++j)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for(int i=0; i<4; ++i)
	{
		delete[] a[i];
	}
	delete[] a;
	return 0;
}