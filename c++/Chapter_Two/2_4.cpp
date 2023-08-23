// You have two numbers represented by a linked list, where each node contains a single digit. 
// The digits are stored in reverse order, such that the 1¡¯s digit is at the head of the list. 
// Write a function that adds the two numbers and returns the sum as a linked list.

// EXAMPLE

// Input: (3 -> 1 -> 5), (5 -> 9 -> 2)

// Output: 8 -> 0 -> 8

// Ë¼Â·:
#include <stdio.h>
#include "util_2.h"

// 
Node* add_element(Node* head1, Node* head2)
{

	if (!head1 || !head2)
	{
		return NULL;
	}
	Node* presult = new Node();
	if (!presult)
	{
		return NULL;
	}
	Node* temp1 = presult;

	bool flag = false;
	while(head1 != NULL
		&& head2 != NULL)
	{
		temp1->data = head1->data + head2->data;
		if (flag)
		{
			temp1->data++;
			flag = false;
		}
		if (temp1->data > 9)
		{
			temp1->data = temp1->data % 10;
			flag = true;
		}
		head1 = head1->next;
		head2 = head2->next;
		temp1->next = new Node();
		temp1 = temp1->next;
	}

	while (head1)
	{
		if (flag)
		{
			temp1->data = head1->data + 1;
			flag = false;
		}
		else
		{
			temp1->data = head1->data;
		}
		head1 = head1->next;
		temp1->next = new Node();
		temp1 = temp1->next;
	}

	while(head2)
	{
		if (flag)
		{
			temp1->data = head2->data + 1;
			flag = false;
		}
		else
		{
			temp1->data = head2->data;
		}
		head2 = head2->next;
		temp1->next = new Node();
		temp1 = temp1->next;
	}

	if (flag)
	{
		temp1->data = 1;
	}

	return presult;
}

int test_2_4()
{
	int a[] = {
		3, 6, 3, 5 
	};
	Node *head1 = init_list(a, 4);
	Node *head2 = init_list(a, 4);
	print_list(head1);
	printf("--------------------------------------\n");
	print_list(head2);
	printf("--------------------------------------\n");
	Node *result = add_element(head1, head2);
	print_list(result);
	destory_list(result);
	return 0;
}
