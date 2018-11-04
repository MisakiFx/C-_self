#include <iostream>
#include <list>//����ͷ�ļ�:˫������ 
#include <deque>//����ͷ�ļ�:˫�˶��� 
#include <iterator> 
using namespace std;
template <class T>
void printContainer(const char* msg, const T &s)
{
	cout << msg << ":";
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
} 
int main()
{
	deque<int> s;
	for(int i = 0; i < 10; i++)
	{
		int x;
		cin >> x;
		s.push_back(x);
	}
	printContainer("deque at first", s);
	//��s�����������������б�����l
	list<int> l(s.rbegin(), s.rend());
	printContainer("list at first", l);
	//���б�����l��ÿ��������Ԫ��˳��ߵ�
	list<int>::iterator iter = l.begin();
	while(iter != l.end())
	{
		int v = *iter;
		iter = l.erase(iter);//erase��ɾ��������ָ���Ԫ�غ���Զ�������һ��Ԫ�� 
		cout << *iter << endl;
		l.insert(++iter, v);//insert�ڵ�����ָ��Ԫ��ǰ����һ����Ԫ�أ������ظ�Ԫ�صĵ��������ɵ��������� 
	}
	printContainer("list at last", l);
	//���б�����l�����ݸ�s��ֵ����s���
	s.assign(l.begin(), l.end());//��l�е�Ԫ��ȫ����s��ֵ 
	printContainer("deque at last", s); 
}
