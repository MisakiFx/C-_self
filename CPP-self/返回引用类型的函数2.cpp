#include <iostream>
using namespace std;
int & sum(int & num1, int & num2)
{
	num1++;
	num2++; 
	//�����������͵ĺ�����������ʱ������������ص����ö���
	//return num1+num2;���Ϸ� 
} 
int main()
{
	int num1 = 10;
	int num2 = 15;
	int result = sum(num1,num2);//��û�и������������͵ĺ������÷���ֵʱ�����Զ����������µ����ò���������num2 
	cout << result << endl;
} 
