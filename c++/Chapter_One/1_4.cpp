#include <stdio.h>
#include <gtest/gtest.h>

// Write a method to decide if two strings are anagrams(变位词) or not.
// 变位词(anagrams)指的是组成两个单词的字符相同，但位置不同的单词。
// 比如说， abbcd和abcdb就是一对变位词

// 思路：变位词，可以理解为字符串中所有字符出现的次数相等，可以直接开两个256的数组
// 来分别记录两个单词的字符出现次数。之后在遍历比较两个数据的元素是否相等
// 改进：可以只申请一个数组，在遍历字符的时候，字符1递加数组对应元素的值，字符2用来递减对应元素的值
int is_string_anagrams(const char *pstr_1, int len_1, const char *pstr_2, int len_2)
{
	int ret = 0;

	// 非法参数
	if (!pstr_1 
		|| !pstr_2
		|| len_1 != len_2 
		|| len_1 <= 0
		|| len_2 <= 0)
	{
		ret = 1;
		return ret;
	}

	// 相等
	if (pstr_1 == pstr_2)
	{
		return ret;
	}

	// 记录字符串中字符出现的次数
	int strs_1[256] = {0};

	for (int i = 0; i < len_1; ++i)
	{
		strs_1[*(pstr_1 + i)]++;
		strs_1[*(pstr_2 + i)]--;
	}

	for (int i = 0; i < 256; ++i)
	{
		if (strs_1[i] != 0)
		{
			ret = 2;
		}
	}

	return ret;
}

TEST(ANAGRAMS_TEST, SUCCESS_CASE)
{
	char test_1_1[] = "abcda";
	char test_1_2[] = "abacd";
	int ret = is_string_anagrams(test_1_1, 5, test_1_2, 5);
	EXPECT_EQ(0, ret);

	char test_2_1[] = "aaa";
	char test_2_2[] = "aaa";
	ret = is_string_anagrams(test_2_1, 3, test_2_2, 3);
	EXPECT_EQ(0, ret);

}

TEST(ANAGRAMS_TEST, FAILDE_CASE)
{
	char test_1_1[] = "abcde";
	char test_1_2[] = "adgce";
	int ret = is_string_anagrams(test_1_1, 5, test_1_2, 5);
	EXPECT_EQ(2, ret);

	ret = is_string_anagrams(NULL, 1, NULL, 2);
	EXPECT_EQ(1, ret);

	ret = is_string_anagrams(test_1_1, 2,  test_1_2, 4);
	EXPECT_EQ(1, ret);
}
