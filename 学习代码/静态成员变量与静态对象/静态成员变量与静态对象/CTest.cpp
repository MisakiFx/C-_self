#include "CTest.h"
int m_nStatic = 0;//全局变量全局只有一份，每个对象都公用同一份变量和内存空间
int CTest::m_nStatic2 = 0;//在类外进行全局变量的初始化
CTest::CTest()
{
}


CTest::~CTest()
{
}


void CTest::Test(int n)
{
	// TODO: 在此处添加实现代码.
	m_nTest += n;
	m_nStatic += n;
}


void CTest::Print()
{
	// TODO: 在此处添加实现代码.
	cout << m_nTest << endl;
	cout << m_nStatic << endl;
	return;
}
