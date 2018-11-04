#include <iostream>
using namespace std;
class Base1
{
	public:
		void display() const
		{
			cout << "Base1::display()" << endl;
		}
};
class Base2 : public Base1
{
	public:
		void display() const//���м̳�Base1 
		{
			cout << "Base2::display()" << endl;
		}
};
class Derived : public Base2//���м̳�Base2 
{
	public:
		void display() const
		{
			cout << "Derived::display()" << endl;
		}
};
void fun(Base1* ptr)
{
	ptr->display();
}
int main()
{
	Base1 base1;
	Base2 base2;
	Derived derived;
	fun(&base1);
	fun(&base2);//base2����Ϊ�����࣬����fun���������Զ�ת��Ϊ����base1 
	fun(&derived);//ͬ��
	/*
	���м̳�����ת��Ϊ�����������ֻ�ܵ��û������еĹ��г�Ա����
	�ɶ��Բ��ã���Ҫ���¶���̳����ķ��麯�� 
	*/ 
}
