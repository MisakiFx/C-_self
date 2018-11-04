#include <iostream>
#include <list>//容器头文件:双向链表 
#include <deque>//容器头文件:双端队列 
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
	//用s容器的内容逆序构造列表容器l
	list<int> l(s.rbegin(), s.rend());
	printContainer("list at first", l);
	//将列表容器l的每相邻两个元素顺序颠倒
	list<int>::iterator iter = l.begin();
	while(iter != l.end())
	{
		int v = *iter;
		iter = l.erase(iter);//erase在删除迭代器指向的元素后会自动移向下一个元素 
		cout << *iter << endl;
		l.insert(++iter, v);//insert在迭代器指定元素前插入一个新元素，并返回该元素的迭代器，旧迭代器不变 
	}
	printContainer("list at last", l);
	//用列表容器l的内容给s赋值，将s输出
	s.assign(l.begin(), l.end());//用l中的元素全部给s赋值 
	printContainer("deque at last", s); 
}
