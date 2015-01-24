#include <stdio.h>
#include <gtest/gtest.h>

//Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer. 
//NOTE: One or two additional variables are fine. An extra copy of the array is not.

//FOLLOW UP

// Write the test cases for this method.

// 思路：先把第一个字符作为标杆，之后遍历字符串，分别和标杆作对比，如果和标杆相同，在将剩余字符依次向前移意味
// 之后再开始第二个，时间复杂度为 O(n^3)
int remove_duplicate_char_in_string(char *pstr, int len)
{
	int ret = 0;
	if (!pstr || len <= 0)
	{
		ret = 1;
		return 1;
	}

	char *temp1 = NULL;
	char *temp2 = NULL;
	for (int i = 0; i < len && *(pstr + i) != '\0'; ++i)
	{
		temp1 = pstr + i;
		for (int j = i + 1; j < len && *(temp1 + j) != '\0'; )
		{
			temp2 = pstr + j;
			if (*temp1 != *temp2)
			{
				++j;
				continue;
			}
			else
			{
				while(*temp2 != '\0')
				{
					*temp2 = *(temp2 + 1);
					temp2++;
				}
				*(temp2 - 1) = '\0';
			}
		}
	}

	return ret;
}

TEST(reverse_TEST, TRUE_CASE)
{
	char test1[] = "abcda";
	int ret = remove_duplicate_char_in_string(test1, 5);
	EXPECT_STREQ("abcd", test1);
	EXPECT_EQ(0, ret);

	char test2[] = "aaa";
	remove_duplicate_char_in_string(test2, 3);
	EXPECT_STREQ("a", test2);

	char test3[] = "abcad";
	remove_duplicate_char_in_string(test3, 4);
	EXPECT_STREQ("abcd", test3);

	char test4[] = "ababc";
	remove_duplicate_char_in_string(test4, 5);
	EXPECT_STREQ("abc", test4);
}
