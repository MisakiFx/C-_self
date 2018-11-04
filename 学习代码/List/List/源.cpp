#include <iostream>
#include <cstring>
using namespace std;
typedef int DATA;
struct SNode//�ڵ�
{
	DATA data;//������
	SNode* pNext;//��ַ��
};
class CList//�����࣬����������
{
	//�ڳ�Ա����ǰ��m_��ʾ��Ա
	SNode * m_pHead;//ͷָ��
	char m_name[20];
	int m_nYear;
	int m_nMonth;
	int m_nDay;
public:
	CList()//���캯��:��ʼ����Ա����,�޷���ֵ
	{
		m_pHead = NULL;
		m_nYear = 0;
		m_nMonth = 0;
		m_nDay = 0;
	}
	CList(int y,int m = 1,int d = 1)//���캯��:��ʼ����Ա����,�޷���ֵ
	{
		m_pHead = NULL;
		m_nYear = y;
		m_nMonth = m;
		m_nDay = d;
	}
	CList(CList &p)//ϵͳĬ�ϵĿ�������
	{
		
	}
	~CList()//��������������ݻ�ʱ���ã�
	{//���ٵ����е����ϵĶѿռ�
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
	void AddHead(DATA data)//ͷ�����
	{
		SNode* p = new SNode;
		p->data = data;
		p->pNext = m_pHead;
		m_pHead = p;
	}
	void AddTail(DATA data)//β�����
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
	void Print()//��ӡ����
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
	CList list1, list2;//�������������
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
	CList list3(2018, 3, 16);//���ù��캯��
	CList* list4 = new CList(2018);//�ڶѿռ��϶���Ķ�������ֶ��ͷţ��Ż�ִ����������
	delete list4;//��������ִ��
	//�ȶ���ĺ���������������ĺ���������
}