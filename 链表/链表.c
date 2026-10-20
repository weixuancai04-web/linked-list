//#include<stdio.h>
//#include<stdlib.h>
//typedef int ElemType;
//typedef struct node {
//	ElemType data;
//	struct node* next;
//} Node;
////初始化
//Node* initList()
//{
//		Node* head = (Node*)malloc(sizeof(Node));
//		head->data = 0;
//		head->next = NULL;
//		return head;
//}
////头插法
//int insertHead(Node* L, ElemType e)
//{
//	Node* p = (Node*)malloc(sizeof(Node));
//	if (p == NULL)
//	{
//		printf("nei cun fen pei shi bai!\n");
//		return 1;
//	}
//	p->data = e;
//	p->next = L->next;
//	L->next = p;
//	return 1;
//}
////遍历
//void listNode(Node* L)
//{
//	Node* p = L->next;
//	while (p != NULL)
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
////在指定位置插入数据
//int insertNode(Node* L, int pos, ElemType e)
//{
//	/*Node* p = L;
//	int i = 0;
//	while (i < pos - 1)
//	{
//		p = p->next;
//		i++;
//		if (p == NULL)
//		{
//			return 0;
//		}
//	}*/
//	if (pos < 1)
//	{
//		return 0;
//	}
//	Node* p = L;
//	for (int i = 0;i < pos;i++)
//	{
//		p = p->next;
//		if (p == NULL)
//		{
//			return 0;
//		}
//	}
//	Node* q = (Node*)malloc(sizeof(Node));
//	q->data = e;
//	q->next = p->next;
//	p->next = q;
//	return 1;
//}
////删除节点
//int deleteNode(Node* L, int pos)
//{
//	if (pos < 1)
//	{
//		return 0;
//	}
//	Node* p = L;
//	for (int i = 0;i < pos-1;i++)
//	{
//		p = p->next;
//		if (p == NULL)
//		{
//			return 0;
//		}
//	}
//	Node* q = p->next;
//	p->next = q->next;
//	free(q);
//	return 1;
//}
////获取链表长度
//int listLength(Node* L)
//{
//	Node* p = L;
//	int len = 0;
//	while (p != NULL)
//	{
//		p = p->next;
//		len++;
//	}
//	return len;
//}
//int main() {
//	Node* list = initList();
//	insertHead(list, 10);
//	insertHead(list, 20);
//	insertHead(list, 30);
//	listNode(list);
//	insertNode(list, 2, 666);
//	listNode(list);
//	deleteNode(list, 2);
//	listNode(list);
//	printf("%d\n",listLength(list));
//	return 0;
//}
//
//
//
//
//
#include<stdio.h>
#include<stdlib.h>
typedef int Elemtype;
typedef struct node
{
	Elemtype data;
	struct node* next;
}Node;

void initList(Node* L)
{
	L->data = 0;
	L->next = NULL;
}

int insertHead(Node* L, Elemtype e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("nei cun fen pei shi bai\n");
		return 0;
	}
	p->data = e;
	p->next = L->next;
	L->next = p;
	return 1;
}

void listNode(Node* L)
{
	Node* p = L->next;
	while (p != NULL)
	{
		printf(" %d", p->data);
		p = p->next;
	}
	printf(" \n");
}

Node* get_tail(Node* L)
{
	Node* p = L;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return p;
}

Node* insertTail(Node* p, Elemtype e)
{
	Node* q = (Node*)malloc(sizeof(Node));
	if (q == NULL)
	{
		printf("nei cun fen pei shi bai\n");
		return NULL;
	}
	q->data = e;
	q->next = p->next;
	p->next = q;
	return q;
}

int insertNode(Node* L, int pos, Elemtype e)
{
	if (pos < 1)
	{
		printf("cha ru wei zhi cuo wu\n");
		return 0;
	}
	Node* p = L;
	int i = 0;
	while (i < pos - 1)
	{
		p = p->next;
		i++;
		if (p == NULL)
		{
			printf("cha ru wei zhi cuo wu\n");
			return 0;
		}
	}
	Node* q = (Node*)malloc(sizeof(Node));
	if (q == NULL)
	{
		printf("nei cun fen pei shi bai\n");
		return 0;
	}
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;
}

int deleteNode(Node* L, int pos)
{
	if (pos < 1)
	{
		printf("shan chu wei zhi cuo wu\n");
		return 0;
	}
	Node* p = L;
	int i = 0;
	while (i < pos - 1)
	{
		p = p->next;
		i++;
		if (p == NULL)
		{
			printf("shan chu wei zhi cuo wu\n");
			return 0;
		}
	}
	if (p->next == NULL)
	{
		printf("shan chu wei zhi cuo wu\n");
		return 0;
	}
	Node* q = p->next;
	p->next = q->next;
	free(q);
	return 1;
}

int listLength(Node* L)
{
	Node* p = L->next;
	int len = 0;
	while (p != NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}

void freeList(Node* L)
{
	Node* q;
	Node* p = L->next;
	while (p != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
}

int main()
{
	Node node;
	initList(&node);
	insertHead(&node, 10);
	insertHead(&node, 20);
	insertHead(&node, 30);
	listNode(&node);
	Node* tail = get_tail(&node);
	tail = insertTail(tail, 10);//看inertTail最后干了啥：返回了q-相当于把q的值赋值给了tail
	tail = insertTail(tail, 20);
	tail = insertTail(tail, 30);
	listNode(&node);
	insertNode(&node, 4, 0);
	insertNode(&node, 5, 0);
	insertNode(&node, 6, 0);
	listNode(&node);
	deleteNode(&node, 5);
	listNode(&node);
	printf("%d\n", listLength(&node));
	freeList(&node);
	printf("%d\n", listLength(&node));
	return 0;
}
