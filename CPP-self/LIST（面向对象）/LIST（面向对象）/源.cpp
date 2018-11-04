#include <iostream>
#include <cstring>
using namespace std;
typedef int DATA;
struct SNode
{
	DATA data;
	SNode* pNext;
};
class CList 
{
	SNode* m_pHead;
	char m_name[20];
public:
	CList()
	{
		m_pHead = NULL;
	}
	void SetName(char* name)
	{
		strcpy_s(m_name,name);
	}
	void AddHead(DATA data)
	{
		SNode* p = new SNode;
		p->data = data;
		p->pNext = m_pHead;
		m_pHead = p;
	}
	void Print()
	{
		SNode* p = m_pHead;
		while (p != NULL)
		{
			cout << p->data << endl;
			p = p->pNext;
		}
	}
	void Sort()
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
	~CList()
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
	int Menu()
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
	void AddTail(DATA data);
};
void CList::AddTail(DATA data)//在类外定义函数，要加域名
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
int main()
{
	CList list1, list2;
	int choice1;
	do
	{
		cout << "请输入要操作的链表:";
		cin >> choice1;
		switch (choice1)
		{
		case 1:
			while (list1.Menu())
			{

			}
			break;
		case 2:
			while (list2.Menu())
			{

			}
			break;
		default:
			return 0;
			break;
		}
	} while (choice1 != 0);
}