#include <iostream>
using namespace std;
//override 和 final
class Base1 final//final关键字不允许被继承 
{
	
}; 
class Derived : public Base1//编译错误 
{
	
};
class Base2
{
	virtual void f() final;//final关键字，不允许被覆盖 
};
class Derived2 : public Base2
{
	void f();//编译错误	
};
int main()
{
	
}
