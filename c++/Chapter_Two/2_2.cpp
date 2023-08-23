// Implement an algorithm to find the nth to last element of a singly linked list.

// 思路：首先想到的是先遍历一遍，获取长度，之后在求得倒数第n个所在的位置，
// 在遍历一次即可。时间复杂度为O(n).
// 另外，还有方法，使用两个指针变量，之间相差为n，当第二个变量到达队尾时，
// 那么第一个变量就到达倒数第n个，此方法时间复杂度仍为O(n)，比上个方法只是
// 减少了一次遍历。

#include <stdio.h>

#include "util_2.h"

// data 为传入参数，即倒数第n个元素的值。倒数第n个由0开始算。
int get_reciprocal_nth_element(Node* head, const int n, int &data)
{
	int ret = 0;

	if (!head || n < 1)
	{
		ret = 1;
		return ret;
	}

	Node* temp1 = head;
	Node* temp2 = head;
	for (int i = 0; i < n; ++i)
	{
		temp2 = temp2->next;
		if (!temp2)
		{
			ret = 2;
			return ret;
		}
	}

	while(temp2 != NULL)
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	data = temp1->data;

	return ret;
}

int test_2_2()
{
	int n = 10;
	int a[] = {
		3, 2, 1, 3, 5, 6, 2, 6, 3, 1 
	};
	Node *head = init_list(a, n);	
	int data = -1;
	int ret = get_reciprocal_nth_element(head, 2, data);
	printf("result should be 3, the result is: %d", data);
	data = -1;
	ret = get_reciprocal_nth_element(NULL, 2, data);
	printf("result should be -1, the result is: %d", data);
	destory_list(head);
	return 0;
}
