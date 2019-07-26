#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

#include "List_mod.h"

template<class Container>
void print_container(const Container& c)
{
	Container::const_iterator it = c.begin();
	while (it != c.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_list1()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_front(0);

	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;

	print_container(l);

	vector<int> v(10, 5);
	print_container(v);
}

void test_list2()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	list<int>::iterator pos = find(l.begin(), l.end(), 3);
	if (pos != l.end())
	{
		l.insert(pos, 30);
	}

	pos = find(l.begin(), l.end(), 3);
	if (pos != l.end())
	{
		l.erase(pos);
	}
	// erase以后迭代器失效，不要再去访问pos
	// ++pos;
	//cout << *pos << endl;

	print_container(l);
}

void test_list3()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));

	auto it = l.begin();
	while (it != l.end())
	{
		// erase()函数执行后，it所指向的节点已被删除，因此it无效，在下一次使用it时，必须先给其赋值
		//it = l.erase(it);
		//l.erase(it++);
		if (*it % 2 == 0)
		{
			l.erase(it++);
		}
		else
		{
			++it;
		}
	}

	print_container(l);
}

int main()
{
	//test_list3();
	//TestList1();
	string s1("hello");
	string s2 = "world";

	return 0;
}