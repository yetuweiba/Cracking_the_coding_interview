// You have two numbers represented by a linked list, where each node contains a single digit. 
// The digits are stored in reverse order, such that the 1’s digit is at the head of the list. 
// Write a function that adds the two numbers and returns the sum as a linked list.

// EXAMPLE

// Input: (3 -> 1 -> 5), (5 -> 9 -> 2)

// Output: 8 -> 0 -> 8

// 思路:
#include <stdio.h>

struct Node
{
	int data;
	Node *next;
	Node()
		:data(-1)
		,next(NULL)
	{
		// empty
	}
};

Node* init_list(int data[], const int len)
{
	Node* head = NULL;

	if (!data || len <= 0)
	{
		return head;
	}


	Node* temp = new Node();
	temp->data = data[0];
	head = temp;
	for (int i = 1; i < len; ++i)
	{
		Node *temp1 = new Node();
		temp->next = temp1;
		temp1->data = data[i];
		temp = temp->next;
	}

	return head;
}

void destory_list(Node *head)
{
	if (!head)
	{
		return; 
	}

	Node* temp = head;
	Node* temp1 = NULL; 
	// 删除到最后一个节点，但是最后一个节点没有释放
	while(temp->next)
	{
		temp1 = temp->next;
		delete temp;
		temp = temp1;
	}
	// 释放最后一个节点
	delete temp;
	return;
}

void print_list(Node *head)
{
	while(head)
	{
		if (head->data != -1)
		{
			printf("the data is <%d>\n", head->data);
		}
		head = head->next;
	}
}
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

int main()
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
