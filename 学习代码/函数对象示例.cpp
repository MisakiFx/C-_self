#include <iostream>
#include <numeric>
using namespace std;
/*
用于算术运算的函数对象：
一元函数对象(一个参数) ：negate
二元函数对象(两个参数) ：plus、minus、multiplies、divides、modulus
用于关系运算、逻辑运算的函数对象(要求返回值为bool)
一元谓词(一个参数)：logical_not
二元谓词(两个参数)：equalto、notequalto、greater、less、greaterequal、lessequal、logicaland、logical_or
*/
/*
函数对象就是一个重载了()运算符的类声明的对象 
*/
class MultClass
{
	public:
		int operator () (int x, int y) const
		{
			return x * y;
		}
};
int main()
{
	int a[] = {1, 2, 3, 4, 5};
	const int N = sizeof(a) / sizeof(int);
	cout << "The retsult by multipling all elements in a is "
		 << accumulate(a, a + N, 1, MultClass())//将类multclass传递给通用算法
		 << endl;	
}
