#include <iostream>
using namespace std;
int sum(int & num)
{
	num++;
	return num;
}
int main()
{
	int num = 10;
 	//sum(num)++;//�����������͵ĺ���������Ϊ��ֵ������result��ֵҲ���޸�
	//��������ǽ�����ֵ����ǰ��const 
	cout << sum(num) + 1 << endl;
}
