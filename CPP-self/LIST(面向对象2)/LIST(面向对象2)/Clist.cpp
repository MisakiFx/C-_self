#include "Clist.h"

Clist::Clist()
{
	m_pHead = NULL;
}
void Clist::SetName(char* name)
{
	strcpy_s(m_name, name);
}
void Clist::AddHead(DATA data)
{
	SNode* p = new SNode;
	p->data = data;
	p->pNext = m_pHead;
	m_pHead = p;
}
void Clist::Print()
{
	SNode* p = m_pHead;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->pNext;
	}
}
void Clist::Sort()
{
	SNode* p = m_pHead;
	DATA temp;
	while (p->pNext != NULL)
	{
		SNode* p1 = p->pNext;
		SNode* mix = p;
		while (p1 != NULL)
		{
			if (p1->data < mix->data)
			{
				mix = p1;
			}
			p1 = p1->pNext;
		}
		if (mix != p)
		{
			temp = p->data;
			p->data = mix->data;
			mix->data = temp;
		}
		p = p->pNext;
	}
	Print();
}
void Clist::AddTail(DATA data)
{
	SNode* p = new SNode;
	p->data = data;
	p->pNext = NULL;
	if (m_pHead == NULL)
	{
		m_pHead = p;
		return;
	}
	SNode* p1 = m_pHead;
	while (p1->pNext != NULL)
	{
		p1 = p1->pNext;
	}
	p1->pNext = p;
}
int Clist::Menu()
{
	int choice;
	cout << "1、头部插入" << endl
		<< "2、尾部插入" << endl
		<< "3、打印" << endl
		<< "4、排序" << endl
		<< "0退出" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		DATA data;
		cout << "请输入插入值:";
		cin >> data;
		AddHead(data);
		break;
	case 2:
		DATA data2;
		cout << "请输入插入值:";
		cin >> data2;
		AddTail(data2);
		break;
	case 3:
		Print();
		break;
	case 4:
		Sort();
	default:
		break;
	}
	return choice;
}
Clist::~Clist()
{
	SNode* p1 = m_pHead;
	SNode* p2;
	while (p1 != NULL)
	{
		p2 = p1;
		p1 = p1->pNext;
		delete p2;
	}
}
