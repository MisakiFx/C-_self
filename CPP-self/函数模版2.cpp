#include <iostream>
#include <vector>
/*
����ģ�����ģ��һ������ʹ��ʱ������Զ������Ͳ��ں�������������޷�ȷ����������Ҫ�ü����ű�ʾ��������˳���ʾ
���޷�ȷ��������ж�����ͱ��ǰ�棬����ȷ���ľͲ���д������ 
*/
using namespace std;
template<class Y, class T>
T abs1(T x)
{
	vector<Y> s;
	return  x < 0 ? -x : x;
}
int main()
{
	cout << abs1<int>(-5) << '\t' << abs1<double>(-5.5) << endl;
} 
