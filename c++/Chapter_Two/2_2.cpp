// Implement an algorithm to find the nth to last element of a singly linked list.

// ˼·�������뵽�����ȱ���һ�飬��ȡ���ȣ�֮������õ�����n�����ڵ�λ�ã�
// �ڱ���һ�μ��ɡ�ʱ�临�Ӷ�ΪO(n).
// ���⣬���з�����ʹ������ָ�������֮�����Ϊn�����ڶ������������βʱ��
// ��ô��һ�������͵��ﵹ����n�����˷���ʱ�临�Ӷ���ΪO(n)�����ϸ�����ֻ��
// ������һ�α�����

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
	// ɾ�������һ���ڵ㣬�������һ���ڵ�û���ͷ�
	while(temp->next)
	{
		temp1 = temp->next;
		delete temp;
		temp = temp1;
	}
	// �ͷ����һ���ڵ�
	delete temp;
	return;
}

void print_list(Node *head)
{
	while(head)
	{
		printf("the data is <%d>\n", head->data);
		head = head->next;
	}
}
// data Ϊ�����������������n��Ԫ�ص�ֵ��������n����0��ʼ�㡣
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

int main()
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
