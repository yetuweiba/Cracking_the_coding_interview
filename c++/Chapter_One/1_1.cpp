#include <stdio.h>
#include <gtest/gtest.h>

// ����1������ַ���ɶ���ascii�룬��������һ��256�����飬ÿ��Ԫ����Ϊfalse���ж�������Ϊtrue���������true����˵�����ظ�
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