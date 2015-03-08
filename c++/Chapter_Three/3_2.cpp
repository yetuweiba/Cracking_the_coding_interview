// How would you design a stack which, in addition to push and pop, 
// also has a function min which returns the minimum element? Push, 
// pop and min should all operate in O(1) time.

// ˼·��push��pop����ʵ��O(1)time, ����min��Ҫ�м���ע�⡣
// 1. ����ʹ��һ���������洢min����Ϊ��min������ջ��ʱ��pop��min�ͻ����
// 2. Ҳ����ջ���Ƶ����ݽṹ���洢minֵ��ÿ��Ԫ�ض�Ӧһ������������������
// �������࣬������pushʱ��Ԫ��С��minʱ������minջ��ֵ����ջ��Ԫ�ص���min��pop��ʱ��Ҳ��Ҫ��minջpop

#include <iostream>
#include <gtest/gtest.h>

const int MAX_DATA_COUNT = 100;

class MyStack
{
private:
	int _datas[MAX_DATA_COUNT];
	int _min_datas[MAX_DATA_COUNT];
	int _data_count;
	int _min_data_count;
public:
	MyStack()
		: _data_count(0)
		, _min_data_count(0)
	{
		memset(_datas, 0, sizeof(_datas));
		memset(_min_datas, 0, sizeof(_min_datas));
	}
public:
	int push(const int data)
	{
		int ret = 0;
		if (_data_count >= MAX_DATA_COUNT)
		{
			std::cout << "stack is full" << std::endl;
			ret = 1;
			return ret;
		}
		
		if (data < _min_datas[_min_data_count] || _min_data_count == 0)
		{
			_min_datas[++_min_data_count] = data;
		}
		_datas[++_data_count] = data;

		return ret;
	}

	int pop()
	{
		int ret = -1;
		if (_data_count == 0)
		{
			return ret;
		}

		ret = _datas[_data_count--];

		if (ret == _min_datas[_min_data_count])
		{
			_min_data_count--;	
		}

		return ret;
	}

	int min()
	{
		int ret = -1;
		if (_min_data_count == 0)
		{
			return ret;
		}

		ret = _min_datas[_min_data_count];
		return ret;
	}
};

TEST(MyStackTest, PositiveTest)
{
	MyStack stack;
	EXPECT_EQ(stack.min(), -1);
	EXPECT_EQ(stack.pop(), -1);
	EXPECT_EQ(stack.push(5), 0);
	EXPECT_EQ(stack.min(), 5);
	EXPECT_EQ(stack.push(7), 0);
	EXPECT_EQ(stack.min(), 5);
	EXPECT_EQ(stack.push(3), 0);
	EXPECT_EQ(stack.min(), 3);
}