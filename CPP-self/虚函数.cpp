#include <iostream>
using namespace std;
//���캯�������飬�������������� 
class Base1
{
	public:
		virtual void display() const; //�麯��:����������д�����幹����������	
};
void Base1::display() const
{
	cout << "Base1::display()" << endl;
}
class Base2 : public Base1 
{
	public:
		virtual void display() const; //�麯��:����������д�����幹����������	
};
void Base2::display() const
{
	cout << "Base2::display()" << endl;
}
class Derived : public Base2 
{
	public:
		virtual void display() const; //�麯��:����������д�����幹����������	
};
void Derived::display() const//����ʱ���ü�virtual 
{
	cout << "Derived::display()" << endl;
}
void fun(Base1* ptr)//�����������display�����麯�������ڱ���ʱ�����к�����󶨣�ֱ������ʱ�Ž��к������ ����̬�󶨣� 
{
	ptr->display();
}
int main()
{
	Base1 base1;
	Base2 base2;
	Derived derived;
	fun(&base1);
	fun(&base2);
	fun(&derived);
}
