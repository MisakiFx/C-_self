#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	char ch='a';
	char * ptr_ch = &ch;
	cout << ptr_ch << '\t' << *ptr_ch << endl;//��c��c++��char�͵�ָ��Ĭ�϶���Ϊ�ַ���ָ��char* ch="12312132"��Ҫ����ǿ�Ƶ�����ת��ת��Ϊָ���� 
	//��ָ��
	int *ptr1=nullptr;//c++��Ŀ�ָ�����int *ptr1=0;
	int *ptr2=0;
	int *ptr3=NULL;//��Ҫ����<cstdlib> 
	//****************************************************************************************************************** 
	//voidָ����Դ����������ָ���ָ������
	//����ȷ��ָ����ָ��ı�����������˲�����voidָ���޸ı�����ֵ 
	//void����ָ��һ�������ͱ��ָ����бȽϣ���Ϊ�������������� 
	double num=3.14;
	double * ptr_num1=&num;
	void * vptr_num1=&num;//void����ָ�룬��������ת�� 
	cout << boolalpha;
	cout << (ptr_num1==vptr_num1) << endl; 
} 
