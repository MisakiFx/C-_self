#include <iostream>
using namespace std;
int Add(int, int = 0, int = 0);//�����������Ĭ�ϲ�����ѡһ,�������ڵ��ú���ǰ��Ĭ�ϲ��� 
int main()
{
	cout << Add(4,5) << endl;
}
int Add(int a, int b, int c)
{
	return a + b + c;
}  
