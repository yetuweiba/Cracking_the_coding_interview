// Write code to remove duplicates from an unsorted linked list.

// FOLLOW UP

// How would you solve this problem if a temporary buffer is not allowed?

// 思路：没有使用缓存，本质就是使用指针的位移来代替缓存，题目不难，
// 时间复杂度为O(n^2)

#include <stdio.h>

#include "util_2.h"

int remove_duplicates(Node* head)
{
	int ret = 0;

	if (!head)
	{
		ret = 1;
		return ret;
	}

	Node *temp = head;
	Node *temp1 = head;
	Node *temp2 = NULL;
	while(temp)
	{
		temp1 = temp->next;
		temp2 = temp;
		while(temp1)
		{
			if (temp->data == temp1->data)
			{
				//temp2 = temp1->next;
				temp2->next = temp1->next;
				delete temp1;
				temp1 = temp2->next;
			}
			else
			{
				temp1 = temp1->next;	
				temp2 = temp2->next;
			}

		}
		temp = temp->next;
	}

	return ret;
}

int test_2_1(){
	int n = 10;
	int a[] = {
		3, 2, 1, 3, 5, 6, 2, 6, 3, 1 
	};
	Node *head = init_list(a, n);	
	print_list(head);
	remove_duplicates(head);
	printf("---------------------");
	print_list(head);
	destory_list(head);
	return 0;
}