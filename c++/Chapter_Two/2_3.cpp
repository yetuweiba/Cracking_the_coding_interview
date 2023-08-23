// Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node.

//EXAMPLE

//Input: the node ��c�� from the linked list a->b->c->d->e Result: nothing is returned, but the new linked list looks like a->b->d->e

// ˼·:�������ͷ��㣬Ҫ��ɾ�������е�ĳһ���ڵ㣬���Ҫɾ�������ĳһ���ڵ㣬�ͱ���Ҫ֪������ڵ����һ���ڵ㣬
// ����ʹ������ָ��������ƫ�ƣ�һ��ָ������һ��ָ�����һ���ڵ㣬����ָ��һ��λ�ƣ�������Ҫɾ���ڵ��ʱ�򣬾Ϳ���
// ֪���˽ڵ����һ���ڵ��ˡ�
// ��һ����������΢ȡ�ɣ���ֻʹ��һ��ָ�룬�ȴ����ʵ�Ҫɾ���ڵ��ʱ�򣬽���һ���ڵ����ֵ��Ҫɾ���ڵ����ֵ����
// ֮��ɾ����һ���ڵ㡣������֤��������������ȷ��
#include <stdio.h>

#include "util_2.h"

// nΪҪɾ���Ľڵ����ֵ
// ��ʵ���ǵڶ��ַ���
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
		// �ڴ�Ҫ���ǣ����Ҫɾ���ڵ������һ���ڵ����ô��
		if (temp2)
		{
			temp1->data = temp2->data;
			temp1->next = temp2->next;
			delete temp2;
			temp2 = NULL;
		}
		// ���Ҫɾ���Ľڵ���β�ڵ�
		// ����Ϊһ�����֣������ʱ���������
		else
		{
			temp1->data = -1;
		}
	}
	return ret;
}

int test_2_3()
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
