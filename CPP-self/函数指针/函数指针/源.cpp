#include <stdio.h>
int Add(int a, int b);
int Dec(int a, int b)
{
	return a - b;
}
int Mult(int a, int b)
{
	return a * b;
}
int(*p)(int, int) = NULL;//��������ָ��p
int main()
{
	//����ָ��
	p = Add;
	int i = p(32, 15);//ָ�����ͺͲ���������Ŀ�꺯����ȫƥ��
	printf("%d",i);
}
//��������ָ�������������������������е���
int Add(int a, int b)
{
	return a + b;
}