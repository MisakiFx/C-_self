#include <iostream>
#include <numeric>
using namespace std;
/*
������������ĺ�������
һԪ��������(һ������) ��negate
��Ԫ��������(��������) ��plus��minus��multiplies��divides��modulus
���ڹ�ϵ���㡢�߼�����ĺ�������(Ҫ�󷵻�ֵΪbool)
һԪν��(һ������)��logical_not
��Ԫν��(��������)��equalto��notequalto��greater��less��greaterequal��lessequal��logicaland��logical_or
*/
/*
�����������һ��������()��������������Ķ��� 
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
		 << accumulate(a, a + N, 1, MultClass())//����multclass���ݸ�ͨ���㷨
		 << endl;	
}
