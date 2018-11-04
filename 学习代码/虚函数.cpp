#include <iostream>
using namespace std;
//构造函数不能虚，析构函数可以虚 
class Base1
{
	public:
		virtual void display() const; //虚函数:不能在类内写函数体构成内联函数	
};
void Base1::display() const
{
	cout << "Base1::display()" << endl;
}
class Base2 : public Base1 
{
	public:
		virtual void display() const; //虚函数:不能在类内写函数体构成内联函数	
};
void Base2::display() const
{
	cout << "Base2::display()" << endl;
}
class Derived : public Base2 
{
	public:
		virtual void display() const; //虚函数:不能在类内写函数体构成内联函数	
};
void Derived::display() const//定义时不用加virtual 
{
	cout << "Derived::display()" << endl;
}
void fun(Base1* ptr)//由于三个类的display都是虚函数所以在编译时不进行函数体绑定，直到运行时才进行函数体绑定 （动态绑定） 
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
