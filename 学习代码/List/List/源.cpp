#include <iostream>
#include <cstring>
using namespace std;
typedef int DATA;
struct SNode//节点
{
	DATA data;//数据区
	SNode* pNext;//地址区
};
class CList//链表类，定义多个链表
{
	//在成员变量前加m_表示成员
	SNode * m_pHead;//头指针
	char m_name[20];
	int m_nYear;
	int m_nMonth;
	int m_nDay;
public:
	CList()//构造函数:初始化成员变量,无返回值
	{
		m_pHead = NULL;
		m_nYear = 0;
		m_nMonth = 0;
		m_nDay = 0;
	}
	CList(int y,int m = 1,int d = 1)//构造函数:初始化成员变量,无返回值
	{
		m_pHead = NULL;
		m_nYear = y;
		m_nMonth = m;
		m_nDay = d;
	}
	CList(CList &p)//系统默认的拷贝构造
	{
		
	}
	~CList()//析构函数，对象摧毁时调用，
	{//销毁掉所有的作废的堆空间
		SNode* p = m_pHead, *p1;
		while (p)
		{
			p1 = p;
			p = p->pNext;
			delete p1;
		}
	}
	void SetName(const char* p)
	{
		strcpy_s(m_name, p);
	}
	void AddHead(DATA data)//头部添加
	{
		SNode* p = new SNode;
		p->data = data;
		p->pNext = m_pHead;
		m_pHead = p;
	}
	void AddTail(DATA data)//尾部添加
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
	void Print()//打印函数
	{
		cout << this->m_name << ':';
		SNode* p = m_pHead;
		while (p != NULL)
		{
			cout << p->data << '\t';
			p = p->pNext;
		}
		cout << endl;
	}
	int GetCount()
	{
		SNode* p = m_pHead;
		int i = 0;
		while (p != NULL)
		{
			i++;
			p = p->pNext;
		}
		return i;
	}
};
int main()
{
	CList list1, list2;//定义多个链表对象
	list1.SetName("Misaki");
	list2.SetName("Msk");
	list1.AddHead(32);
	list1.AddHead(32);
	list1.AddHead(32);
	list1.AddHead(32);
	list1.AddHead(32);
	list1.AddHead(32);
	cout << list1.GetCount() << endl;
	cout << list2.GetCount() << endl; 
	list1.Print();
	CList list3(2018, 3, 16);//调用构造函数
	CList* list4 = new CList(2018);//在堆空间上定义的对象必须手动释放，才会执行析构函数
	delete list4;//析构函数执行
	//先定义的函数后析构，后定义的函数先析构
}