// Given a circular linked list, implement an algorithm which returns node at the beginning of the loop.
// DEFINITION

// Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an earlier node, so as to make a loop in the linked list.

// EXAMPLE

// Input: A -> B -> C -> D -> E -> C [the same C as earlier]

// Output: C

// 即寻找链表中是否有环,如果有的话，返回环的节点。

// 两种思路：
// 1. 使用一个map来存储所有节点的地址，之后对比每个节点的地址，看是否有相同地址，如果有，则说明
// 链表中有环，时间复杂度为O(nlogn).
// 2. 使用两个指针，一个快指针，一个慢指针，当快指针赶上慢指针的时候，说明链表中存在环
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
	
	// 此循环是证明链表存在环
	while(temp2 && temp2->next)
	{
		temp1 = temp1->next;
		temp2 = temp2->next->next;
		if (temp1 == temp2)
		{
			break;
		}
	}

	// 到队尾，说明没有环
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
	// 目前申请的内存暂无法释放，因为链表中存在环
	// 只有等到程序退出去后由系统销毁
	int a[] = {
		3, 6, 3, 5 
	};
	Node *head1 = init_list(a, 4, 2);
	Node *loop_node = get_loop_element(head1);
	printf("the loop data is: %d", loop_node->data);
	return 0;
}
