#include <stdio.h>
#include <gtest/gtest.h>

// 方案1：如果字符组成都是ascii码，可以申请一个256的数组，每个元素置为false，判断有则置为true，如果存在true，则说明有重复
bool is_unique_char_in_string(const char* data, int len)
{
	bool bret = true;
	if(!data || len <= 0)
	{
		printf("error param");
		return !bret;
	}
	bool flag[256];
	memset(flag, 0, sizeof(flag));

	for (int i = 0; i < len; ++i)
	{
		if(flag[data[i]])
		{
			bret = false;
			break;
		}
		else
		{
			flag[data[i]] = true;
		}
	}
	return bret;
}

TEST(is_unique_char_in_string_TEST, TRUE_CASE)
{
	EXPECT_EQ(true, is_unique_char_in_string("tesabc", 6));
}

TEST(is_unique_char_in_string_TEST, FALSE_CASE)
{
	EXPECT_EQ(false, is_unique_char_in_string(NULL, 1));
	EXPECT_EQ(false, is_unique_char_in_string("saf", 0));
	EXPECT_EQ(false, is_unique_char_in_string("abcdefga", 8));
}