#include <stdio.h>
#include <string>
#include <gtest/gtest.h>

#include "../cracking_the_coding_interview/test.h"

// Assume you have a method isSubstring which checks if one word is a substring of another.
// Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only 
// one call to isSubstring ( i.e., “waterbottle” is a rotation of “erbottlewat”).

// 判断str2是否是str1的子字符串
// TODO::使用kmp算法
bool isSubstring(const char *str1, const int len1,
				const char *str2, const int len2)
{
	bool ret = false;

	std::string string1(str1);
	std::string string2(str2);
	if (string1.find(string2) != std::string::npos)
	{
		ret = true;
	}

	return ret;

}

// 只使用一次 isSubstring来判断是否是变位词
// 那么str2一定是str1+str1的子字符串
bool isRotation(const char* str1, const int len1,
				const char* str2, const int len2)
{
	bool ret = false;

	if (!str1 
		|| len1 <= 0
		|| !str2
		|| len2 <= 0
		|| len1 != len2)
	{
		return ret;
	}

	char *temp = (char *)operator new(2 * len1 + 1);
	if (!temp)
	{
		return ret;
	}
	memset(temp, 0, 2 * len1 + 1);

	for (int i = 0; i < len1; ++i)
	{
		*(temp + i) = str1[i];
	}

	for (int i = len1; i < 2 * len1; ++i)
	{
		temp[i] = str1[i - len1];
	}
	temp[2 * len1] = '\0';

	if (isSubstring(temp, 2 * len1, str2, len2))
	{
		ret = true;
	}
	operator delete(temp);

	return ret;
}

TEST(IsRotationTest, TrueTest)
{
	EXPECT_EQ(true, isRotation("abc", 3, "bca", 3));
}

TEST(IsRotationTest, FlaseTest)
{
	EXPECT_EQ(false, isRotation("abc", 3, "bc", 2));
	EXPECT_EQ(false, isRotation(NULL, 2, "ab", 2));
	EXPECT_EQ(false, isRotation("ab", -1, "ba", 2));
}