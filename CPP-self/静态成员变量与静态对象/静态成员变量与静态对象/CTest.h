#pragma once
#include <iostream>
using namespace std;
class CTest
{
	friend void Test();//友员函数，在这个函数内可以调用私有的成员变量和成员函数
	int m_nTest = 0;
public:
	CTest();
	~CTest();
	static int m_nStatic2;//如果加上static他就是全局变量而不是类内变量,初始化要在类外进行初始化,不占用类的内存空间
	void Test(int);
	void Print();
};

