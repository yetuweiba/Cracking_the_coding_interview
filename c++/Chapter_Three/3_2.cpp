// How would you design a stack which, in addition to push and pop, 
// also has a function min which returns the minimum element? Push, 
// pop and min should all operate in O(1) time.

// 思路：push和pop容易实现O(1)time, 但是min需要有几点注意。
// 1. 不能使用一个变量来存储min，因为当min正好是栈顶时，pop后min就会出错。
// 2. 也是用栈类似的数据结构来存储min值，每个元素对应一个，但是这样会引起
// 数据冗余，可以在push时的元素小于min时再增加min栈的值，若栈顶元素等于min，pop的时候也需要将min栈pop

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