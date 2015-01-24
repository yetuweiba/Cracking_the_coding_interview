#include <stdio.h>
#include <gtest/gtest.h>

// Q:Write code to reverse a C-Style String. 
// (C-String means that “abcd” is represented as five characters, including the null character.)
// 此题要求是也要翻转末尾的'\0'

// 在此不适用异或的交换方法是因为使用异或并不能比使用临时变量节省空间和效率，具体请看链接：
// 用异或来交换两个变量的坏处(http://blog.csdn.net/solstice/article/details/5166912)
void swap_char(char *p1, char *p2)
{
	char temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
int reverse_str(char *str)
{
	int ret = 0;
	if (!str)
	{
		ret = 1;
		return ret;
	}

	char *start = str;
	char *end = str;
	// 定位到字符串末尾 
	while (*end)
	{
		end++;
	}
	end--;

	while (end > start)
	{
		swap_char(start++, end--);
	}

	return ret;
}

//int main()
//{
	// 关于为什么不能声明为 char *str = "1234abcd";见如下链接
	// https://stackoverflow.com/questions/164194/why-do-i-get-a-segmentation-fault-when-writing-to-a-string
//	char str[] = "12345abcd";
//	reverse_str(str);
//	printf(str);
//	return 0;
//};

TEST(reverse_TEST, TRUE_CASE)
{
	char test1[] = "abcd";
	int ret = reverse_str(test1);
	EXPECT_STREQ("dcba", test1);
	EXPECT_EQ(0, ret);
}

TEST(reverse_TEST, FALSE_CASE)
{
	char *test1 = NULL;
	int ret = reverse_str(test1);
	EXPECT_EQ(1, ret);
}