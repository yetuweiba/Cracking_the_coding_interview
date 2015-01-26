#include <stdio.h>
#include <gtest/gtest.h>

// Write a method to decide if two strings are anagrams(��λ��) or not.
// ��λ��(anagrams)ָ��������������ʵ��ַ���ͬ����λ�ò�ͬ�ĵ��ʡ�
// ����˵�� abbcd��abcdb����һ�Ա�λ��

// ˼·����λ�ʣ��������Ϊ�ַ����������ַ����ֵĴ�����ȣ�����ֱ�ӿ�����256������
// ���ֱ��¼�������ʵ��ַ����ִ�����֮���ڱ����Ƚ��������ݵ�Ԫ���Ƿ����
// �Ľ�������ֻ����һ�����飬�ڱ����ַ���ʱ���ַ�1�ݼ������ӦԪ�ص�ֵ���ַ�2�����ݼ���ӦԪ�ص�ֵ
int is_string_anagrams(const char *pstr_1, int len_1, const char *pstr_2, int len_2)
{
	int ret = 0;

	// �Ƿ�����
	if (!pstr_1 
		|| !pstr_2
		|| len_1 != len_2 
		|| len_1 <= 0
		|| len_2 <= 0)
	{
		ret = 1;
		return ret;
	}

	// ���
	if (pstr_1 == pstr_2)
	{
		return ret;
	}

	// ��¼�ַ������ַ����ֵĴ���
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
