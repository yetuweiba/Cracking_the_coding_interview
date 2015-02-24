// Given a circular linked list, implement an algorithm which returns node at the beginning of the loop.
// DEFINITION

// Circular linked list: A (corrupt) linked list in which a node��s next pointer points to an earlier node, so as to make a loop in the linked list.

// EXAMPLE

// Input: A -> B -> C -> D -> E -> C [the same C as earlier]

// Output: C

// ��Ѱ���������Ƿ��л�,����еĻ������ػ��Ľڵ㡣

// ����˼·��
// 1. ʹ��һ��map���洢���нڵ�ĵ�ַ��֮��Ա�ÿ���ڵ�ĵ�ַ�����Ƿ�����ͬ��ַ������У���˵��
// �������л���ʱ�临�Ӷ�ΪO(nlogn).
// 2. ʹ������ָ�룬һ����ָ�룬һ����ָ�룬����ָ�������ָ���ʱ��˵�������д��ڻ�
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
		Node *temp1 = new Node();
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
// 
Node* get_loop_element(Node* head)
{
	Node *pResult = NULL;;

	if (!head || !head->next)
	{
		return pResult;
	}

	Node *temp1 = head;
	Node *temp2 = head;
	
	// ��ѭ����֤��������ڻ�
	while(temp2 && temp2->next)
	{
		temp1 = temp1->next;
		temp2 = temp2->next->next;
		if (temp1 == temp2)
		{
			break;
		}
	}

	// ����β��˵��û�л�
	if (!temp2 || !temp2->next)
	{
		return pResult;
	}

	temp1 = head;
	while(temp1 != temp2)
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	pResult = temp1;
	return pResult;
}

int main()
{
	// Ŀǰ������ڴ����޷��ͷţ���Ϊ�����д��ڻ�
	// ֻ�еȵ������˳�ȥ����ϵͳ����
	int a[] = {
		3, 6, 3, 5 
	};
	Node *head1 = init_list(a, 4, 2);
	Node *loop_node = get_loop_element(head1);
	printf("the loop data is: %d", loop_node->data);
	return 0;
}
