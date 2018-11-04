#include <stdio.h>
#include <stdlib.h>
typedef int DATA;
struct SNode//节点
{
	DATA data;
	SNode* pNext;//尾指针
};
SNode* g_pHead = NULL;//头指针
void AddHead(DATA data)//在头部添加
{
	SNode* p = (SNode*)malloc(sizeof(SNode));
	p->data = data;
	p->pNext = g_pHead;
	g_pHead = p;
}
void AddTail(DATA data)//在尾部添加
{
	SNode* pf = (SNode*)malloc(sizeof(SNode));
	pf->data = data;
	pf->pNext = NULL;
	SNode* p = g_pHead;
	if (g_pHead == NULL)
	{
		g_pHead = pf;
		return;
	}
	while (p->pNext != NULL)
	{
		p = p->pNext;
	}
	p->pNext = pf;
}
int Delete(DATA data)//删除
{
	SNode* p = g_pHead,*p1 = NULL;//找到头
	if (p = NULL)//如果是空链表直接删除失败
	{
		return 0;
	}
	if (p->data == data)//如果删除的是头节点要特殊处理
	{
		g_pHead = p->pNext;
		free(p);
		return 1;
	}
	while (p != NULL)//遍历链表
	{
		if (p->data == data)
		{
			p1->pNext = p->pNext;//将删除节点的前一个节点与后一个节点连接起来
			free(p);//单纯释放内存不行，链表就断了
			return 1;
		}
		p1 = p;//让p1记录节点的前一个节点
		p = p->pNext;
	}
	return 0;
}
void Print()//打印
{
	SNode* p = g_pHead;//找到头
	while (p != NULL)//遍历链表
	{
		printf("%d\t", p->data);
		p = p->pNext;
	}
	printf("\n");
}
void Modfx(DATA data, DATA newData)//修改
{
	SNode* p = g_pHead;//找到头
	while (p != NULL)//遍历链表
	{
		if (p->data == data)
		{
			p->data = newData;
		}
		p = p->pNext;//找到下一节点
	}
}
int Find(DATA data)//查找
{
	SNode* p = g_pHead;//找到头
	while (p != NULL)//遍历链表
	{
		if (p->data == data)
		{
			return 1;
		}
		p = p->pNext;
	}
	return 0;
}
int main()
{
	AddHead(3);
	AddHead(2);
	AddHead(1);
	puts("修改前");
	Print();
	Modfx(2, 888);//将2修改为888
	puts("修改后");
	Print();
	if (Find(56))
	{
		puts("找到了");
	}
	else
	{
		puts("没找到");
	}
	if (Delete(888) == 0)
	{
		puts("删除失败！");
	}
	puts("删除后");
	Print();
}