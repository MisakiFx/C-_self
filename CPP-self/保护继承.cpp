#include <iostream>
using namespace std;
//�����̳У������еĹ��кͱ�����Ա����������ȫ����Ϊ������Ա
//�ⲿ���󲻿�ֱ�ӷ��ʸ����е����г�Ա
//�����ڲ����Է��ʸ����еĹ��кͱ�����Ա
//������Ա�޷�������ʹ�ã����ǿ�������������ʹ�ã���������Ҳ��������ʹ�� 
{
	public:
		void InitX()
		{
			x = 1;
			cout << x << endl;
		}
	protected:
		int x;	
};
int main()
{
	Point a;
	a.InitX();
}
