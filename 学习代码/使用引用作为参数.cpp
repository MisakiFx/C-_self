#include <iostream>
using namespace std;
void Swap(int, int);
void Swap2(int*, int*);
void Swap3(int&, int&);
int main()
{
	int num1 = 10,num2 = 5;
	Swap(num1, num2);//�������ݣ�����ʵ�ʽ���ԭʼ���ݵĽ��� 
	cout << "Swap1��" << num1 << '\t' << num2 << endl;
	Swap2(&num1, &num2);//ָ��ĸ������ݣ�ԭʼ���ݵ�ָ�벢���ύ�� 
	cout << "Swap2��" << num1 << '\t' << num2 << endl;
	Swap3(num1, num2);//���ô��ݣ��൱�ڴ������ݱ���ԭʼ���ݸı� 
	cout << "Swap3��" << num1 << '\t' << num2 << endl;
	//ʹ��������Ϊ�������ݵĺô���
	//1�����Ը��Ӽ�����д����
	//2������ֱ�Ӵ���ĳ�����󣬶���ֻ�ǰѶ�����һ��
	//�����ϣ�������޸����õ�ֵ��������ǰ����const 
} 
void Swap(int num1, int num2)
{
	int temp;
	temp = num1;
	num1 = num2;
	num2 = temp;
}
void Swap2(int* p1, int* p2)
{
	int * temp;
	temp = p1;
	p1 = p2;
	p2 = temp;
}
void Swap3(int &ref1, int &ref2)//�൱�ڴ���ԭʼ���� 
{
	int temp;
	temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}
