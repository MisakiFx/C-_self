#include <iostream>
using namespace std;
void sample(int = 10);//�ڶ����ʱ�������Ĭ��ֵ
void sample(int num)//����������ʱ������Ĭ��ֵ������ͬʱ���� 
{
	cout << num << endl;
} 
void test1(int a, int b = 5, int c = 10);//��ȷ
void test2(int a, int b = 5, int c); //����Ĭ�ϲ���������в�����������Ĭ��ֵ 
int main()
{
	sample();//ʹ�ú���Ĭ�ϲ��� 
	sample(123);//��ʹ��������������Ӱ�� 
} 
