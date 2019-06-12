
#include <stdlib.h>
#include <string.h>

#include <iostream>
using namespace std;

// 链表节点
struct Node {
	int m;
	struct Node* next;
};

Node* add()
{
	Node* node = (Node*)malloc(sizeof(Node));
	memset(node, 0, sizeof(Node));
	node->next = NULL;
	
	return node;
}

// 创建链表
Node* create(int size)
{
	if (size <= 0) 
	{
		return NULL;
	}
	
	Node* head = NULL;
	Node* p = NULL;
	
	for (int i = 0; i < size; i++) {
		Node* node = add();
		node->m = i;
		
		if (!head)
		{
			head = node;
			p = node;
		}
		else
		{
			p->next = node;
			p = node;
		}
	}
	
	return head;
}

// 遍历打印链表内容
void print(Node*p)
{
	if (!p)
	{
		return;
	}
	
	while (p != NULL)
	{
		cout << p->m<< " ";
		p = p->next;
	}
	cout << endl;
}

// 链表逆序
Node* reverse(Node* p)
{
	Node* p0 = NULL;
	
	while (p->next != NULL)
	{
		Node* p_tmp = p->next;
		p->next = p0;
		p0 = p;
		p = p_tmp;
	}
	
	p->next = p0;
	
	return p;
}

// 释放链表
void destroy(Node* p)
{
	if (!p)
	{
		return;
	}
	
	while (p)
	{
		Node* p1 = p;
		p = p->next;
		free(p1);
	}
}

int main()
{
	Node* head = create(10);
	print(head);
	head = reverse(head);
	print(head);
	
	destroy(head);
	
	return 0;
}