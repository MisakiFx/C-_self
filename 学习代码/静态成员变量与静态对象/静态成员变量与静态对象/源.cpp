#include <iostream>
#include "CTest.h"
using namespace std;
CTest t3;
void Test()
{
	t3.m_nTest = 1;
}
int main()
{
	CTest t1;
	CTest t2;
	CTest::m_nStatic2 = 0;
	t1.m_nStatic2 = 99;
	t1.Test(32);
	t1.Test(33);
	t1.Print();
	t2.Test(11);
	t2.Test(5);
	t2.Print();
}