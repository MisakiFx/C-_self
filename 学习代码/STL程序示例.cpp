#include <iostream>
#include <vector>//��������ͷ�ļ� 
#include <iterator>//������ͷ�ļ� 
#include <algorithm>//�㷨ͷ�ļ� 
#include <functional>//��������ͷ�ļ� 
using namespace std;
int main()
{
	const int N = 5;
	vector<int> s(N);//����
	for(int i = 0; i < N; i++)
		cin >> s[i];
	transform/*�㷨*/(s.begin()/*������*/, s.end()/*������*/, ostream_iterator<int>/*������*/(cout, " "), negate<int>()/*��������*/);
	/*
	transform�㷨��
	ԭ�ͣ�
	transform <class InputIterator, class OutputIterator, class UnaryFunction>
	OutputIterator transform(InputIterator first, InputIterator last, OutputIterator result, UnaryFunction op)
	{
		for(; first != last; ++first, ++result)
			*result = op(*first);
		return result;
	}
	1��transform�㷨˳�����first��last������������ָ���Ԫ�أ�
	2����ÿ��Ԫ�ص�ֵ��Ϊ��������op�Ĳ���
	3�� ��op�ķ���ֵͨ��������result˳�������
	4��������ɺ�result������ָ�������������һ��Ԫ�ص���һ��λ�ã�treansform�Ὣ�õ��������� 
	**/
	cout << endl; 
}
