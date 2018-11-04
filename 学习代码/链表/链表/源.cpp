#include <stdio.h>
#include <stdlib.h>
//#define DATA int//宏定义
//单向链表，链表由一个个结构体（节点）组成，一个节点的尾部有指向下一个节点的指针
typedef int DATA;//类型定义
struct SNode//节点结构体：1、数据区，2、地址区
{
	DATA data;//不确定数据类型（数据区）
	SNode* pNext;//尾：四个字节（地址区）
};
SNode* g_pHead = NULL;//头指针
void AddHead(DATA data)//从头部插入
{
	SNode* p = (SNode*)malloc(sizeof(SNode));//在对内存中申请一个新节点的内存空间
	p->data = data;//把传入的数据放到新的节点中
	p->pNext = g_pHead;//将尾指针指向头
	g_pHead = p;//头指针等于新的内存空间的指针，即可完成头部插入
}
void AddTail(DATA data)//从尾部插入
{
	SNode* pNew = (SNode*)malloc(sizeof(SNode));//创造新节点
	pNew->data = data;//赋值
	pNew->pNext = NULL;//让新节点尾巴为0
	if (g_pHead == NULL)//如果是空链表，是新链表
	{
		g_pHead = pNew;//就让新插入的节点当头节点
		return;
	}
	SNode* p = g_pHead;//用临时变量指向头指针
	while (p->pNext)//通过循环让临时指针指向最后一个节点
	{
		p = p->pNext;//临时指针指向最后一个节点
	}
	p->pNext = pNew;//让原来的最后一个节点的尾巴等于新节点的指针
}
void Print()//打印函数
{
	SNode* p = g_pHead;//新申请临时变量让p来动进行循环打印，头不懂以来多次打印
	while (p != NULL)//只要头指针不为空（还有结构体存在）
	{
		printf("%d\t", p->data);
		p = p->pNext;//打印完一次头指针更新为这个节点里的尾指针（即下一个节点的头指针）
	}
	
}
int main()
{
	AddHead(3);
	AddHead(2);
	AddHead(1);
	printf("第一次打印:");
	Print();
	AddTail(67);
	AddTail(98);
	printf("\n");
	printf("第二次打印:");
	Print();
}