#include "util_2.h"

Node* init_list(int data[], int len)
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
		Node* temp1 = new Node();
		temp->next = temp1;
		temp1->data = data[i];
		temp = temp->next;
	}

	return head;
}

Node* init_list(int data[], const int len, const int m)
{
	Node* head = NULL;

	if (!data || len <= 0)
	{
		return head;
	}

	Node* temp = new Node();
	Node* loop_node = NULL;
	temp->data = data[0];
	head = temp;
	for (int i = 1; i < len; ++i)
	{
		Node* temp1 = new Node();
		temp->next = temp1;
		temp1->data = data[i];
		temp = temp->next;
		if (i == m - 1)
		{
			loop_node = temp1;
		}
	}

	temp->next = loop_node;

	return head;
}

void destory_list(Node* head)
{
	if (!head)
	{
		return;
	}

	Node* temp = head;
	Node* temp1 = NULL;
	// 删除到最后一个节点，但是最后一个节点没有释放
	while (temp->next)
	{
		temp1 = temp->next;
		delete temp;
		temp = temp1;
	}
	// 释放最后一个节点
	delete temp;
	return;
}

void print_list(Node* head)
{
	while (head)
	{
		printf("the data is <%d>\n", head->data);
		head = head->next;
	}
}