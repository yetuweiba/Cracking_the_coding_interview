#include <stdio.h>
#include <gtest/gtest.h>

// Write a method to replace all spaces in a string with ‘%20’.

// 思路：首先遍历字符串，计算所需缓存的大小。之后再遍历字符串，依次将
// 字符放入缓存中，若是遇到空格，则放入‘%20’
// 同时注意：此方法在内部申请了内存，应当在使用完成后delete内存。
// 很讨厌，实际应用中应当传入构造好的内存，不应当让new和delete不成对出现
char * replace_spaces(char *pstr, int len)
{
	char *presult = NULL;
	if (!pstr || len <= 0)
	{
		return presult;
	}

	int space_num = 0;
	for (int i = 0; i < len; ++i)
	{
		if (pstr[i] == ' ')
		{
			space_num++;
		}
	}
	presult = new char(sizeof(char) * (len + space_num * 2 + 1));
	if (!presult)
	{
		return presult;
	}
	// 记录当前presult 写入字符的位置
	// 如果是std::string 直接+字符 就好了
	int presult_location = 0;
	for (int i = 0; i < len; ++i)
	{
		if (pstr[i] == ' ')
		{
			presult[presult_location++] = '%';
			presult[presult_location++] = '2';
			presult[presult_location++] = '0';
		}
		else
		{
			presult[presult_location++] = pstr[i];
		}
	}
	presult[presult_location] = '\0';

	return presult;
}

TEST(ReplaceTest, SuccessCase1)
{
	char test_1[] = "ab cd ";
	char* pret1 = replace_spaces(test_1, 6);
	EXPECT_STREQ("ab%20cd%20", pret1);
	if (!pret1)
	{
		delete pret1;
	}
}
TEST(ReplaceTest1, SuccessCase2)
{
	char *test_2 = " a a ";
	char *pret2 = replace_spaces(test_2, 5);
	EXPECT_STREQ("%20a%20a%20", pret2);
	if (!pret2)
	{
		delete pret2;
	}
}

TEST(ReplaceTest2, SuccessCase3)
{
	char *test_3 = "abcde";
	char *pret3 = replace_spaces(test_3, 5);
	EXPECT_STREQ("abcde", pret3);
	if (!pret3)
	{
		delete pret3;
	}
}

TEST(ReplaceTest, FailedCase)
{
	char *pret1 = replace_spaces(NULL, 1);
	EXPECT_EQ(NULL, pret1);

	char test_1[] = "ab a";
	char *pret2 = replace_spaces(test_1, 0);
	EXPECT_EQ(NULL, pret2);
}
