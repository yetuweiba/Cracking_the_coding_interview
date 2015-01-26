#include <stdio.h>
#include <gtest/gtest.h>

// Write a method to replace all spaces in a string with ��%20��.

// ˼·�����ȱ����ַ������������軺��Ĵ�С��֮���ٱ����ַ��������ν�
// �ַ����뻺���У����������ո�����롮%20��
// ͬʱע�⣺�˷������ڲ��������ڴ棬Ӧ����ʹ����ɺ�delete�ڴ档
// �����ᣬʵ��Ӧ����Ӧ�����빹��õ��ڴ棬��Ӧ����new��delete���ɶԳ���
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
	// ��¼��ǰpresult д���ַ���λ��
	// �����std::string ֱ��+�ַ� �ͺ���
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
