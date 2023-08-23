#pragma once

#include <stdio.h>

struct Node
{
	int data;
	Node* next;
	Node()
		:data(0)
		, next(NULL)
	{
		// empty
	}
};

Node* init_list(int data[], int len);

Node* init_list(int data[], const int len, const int m);

void destory_list(Node* head);

void print_list(Node* head);

