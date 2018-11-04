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
		void display() const//公有继承Base1 
		{
			cout << "Base2::display()" << endl;
		}
};
class Derived : public Base2//公有继承Base2 
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
	fun(&base2);//base2类型为派生类，调用fun函数类型自动转换为基类base1 
	fun(&derived);//同理
	/*
	公有继承类型转换为基类的派生类只能调用基类中有的公有成员函数
	可读性不好，不要重新定义继承来的非虚函数 
	*/ 
}
