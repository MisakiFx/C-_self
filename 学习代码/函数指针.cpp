#include <iostream>
using namespace std;
int pow(int,int);
int main()
{
	//��������ָ��
	int (*ptr_pow)(int,int); 
	//�ú���ָ��ָ�����Ա����
	ptr_pow = pow;//���������Ǻ����ĵ�ַ 
	//���ú���ָ��
	cout << ptr_pow(3,2) << endl; //��ʽ1
	cout << (*ptr_pow)(3,2) << endl; //��ʽ2 
	cout << pow(3,2) << endl; 
}
int pow(int num1, int num2)
{
	int result = 1;
	for(int i = 0;i < num2; i++)
	{
		result *= num1;
	}
	return result;
 } 
