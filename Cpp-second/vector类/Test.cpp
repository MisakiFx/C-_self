#include <vector>
#include <iostream>
#include <algorithm>
#include "vector_mod.h"
using std::cout;
using std::endl;

void test_vector1()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//auto ret = std::find(v.begin(), v.end(), 3);
	//v.erase(ret); // ret ß–ß

	// ∑«∑®
	//++ret;
	//cout << *ret << endl;
	cout << v.capacity() << endl;
	auto ret = std::find(v.begin(), v.end(), 2);
	v.insert(ret, 20);
	cout << v.capacity() << endl;
//	cout << *ret << endl;
}

void test_vector2()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else
		{
			++it;
		}
	}

	for (auto e : v)
	{
		cout << e << endl;
	}
}

#include "Vector.h"

void TestVector1()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);

	for (size_t i = 0; i < v.Size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	cout << v.Capacity() << endl;

	Vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void TestVector2()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);
	v.PushBack(6);
	v.PushBack(7);

	Vector<int>::iterator it = v.begin();
	v.Insert(it, 0);
	Vector<int>::iterator ret = std::find(v.begin(), v.end(), 3);
	if (ret != v.end())
	{
		cout << *ret << endl;
		v.Insert(ret, 30);
		//cout << *ret << endl;
	}

	ret = std::find(v.begin(), v.end(), 3);
	v.Erase(ret);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void TestVector3()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);
	v.PushBack(6);
	v.PushBack(7);

	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it = v.Erase(it);
		}
		else
		{
			++it;
		}
	}

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void TestVector4()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);
	v.PushBack(6);
	v.PushBack(7);

	Vector<int> copy(v);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : copy)
	{
		cout << e << " ";
	}
	cout << endl;

	Vector<int> v2;
	v2.PushBack(10);
	v2.PushBack(10);
	v = v2;

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

#include <string>

void TestVector5()
{
	Vector<std::string> v;
	v.PushBack("1111111111111111");
	v.PushBack("1111111111111111");
	v.PushBack("1111111111111111");
	v.PushBack("1111111111111111");
	v.PushBack("1111111111111111");
	//v.PushBack("2222222222222222");

	for (auto e : v)
	{
		cout << e << endl;
	}
	cout << endl;
}

int main()
{
	//test_vector1();
	//test_vector2();
	TestVector5();

	//char* p1 = "hello";
	//char p2[] = "hello";
	//cout << *p1 << endl;
	//cout << *p2 << endl;

	//*p1 = 'x';
	//*p2 = 'y';

	//int a[3];
	//a[3] = 3;
	//a[4] = 4;
	/*a[5] = 5;
	a[10] = 10;
	cout << a[3] << endl;
	cout << a[4] << endl;
	cout << a[5] << endl;*/

	return 0;
}