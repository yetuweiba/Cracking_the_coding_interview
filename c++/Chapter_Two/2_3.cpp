// Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node.

//EXAMPLE

//Input: the node ‘c’ from the linked list a->b->c->d->e Result: nothing is returned, but the new linked list looks like a->b->d->e

// 思路:此题给出头结点，要求删除链表中的某一个节点，如果要删除链表的某一个节点，就必须要知道这个节点的上一个节点，
// 可以使用两个指针来进行偏移，一个指针是另一个指针的上一个节点，两个指针一起位移，当到达要删除节点的时候，就可以
// 知道此节点的上一个节点了。
// 另一个方法则稍微取巧，即只使用一个指针，等待访问到要删除节点的时候，将下一个节点的数值和要删除节点的数值交换
// 之后删除下一个节点。这样保证链表中数据是正确的
#include <stdio.h>

struct Node
{
	int data;
	Node *next;
	Node()
		:data(0)
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
// n为要删除的节点的数值
// 此实现是第二种方法
int remove_element(Node* head, const int n)
{
	int ret = 0;

	if (!head)
	{
		ret = 1;
		return ret;
	}

	Node* temp1 = head;
	while (temp1)
	{
		if (temp1->data == n)
		{
			break;
		}
		temp1 = temp1->next;
	}

	if (temp1)
	{
		Node* temp2 = temp1->next;
		// 在此要考虑，如果要删除节点是最后一个节点该怎么办
		if (temp2)
		{
			temp1->data = temp2->data;
			temp1->next = temp2->next;
			delete temp2;
			temp2 = NULL;
		}
		// 如果要删除的节点是尾节点
		// 设置为一个数字，输出的时候不输出即可
		else
		{
			temp1->data = -1;
		}
	}
	return ret;
}

int main()
{
	int n = 9;
	int a[] = {
		3, 2, 3, 5, 6, 2, 6, 3, 1 
	};
	Node *head = init_list(a, n);	
	int ret = remove_element(head, 2);
	print_list(head);
	printf("--------------------------------------\n");
	ret = remove_element(head, 1);
	print_list(head);
	destory_list(head);
	return 0;
}
