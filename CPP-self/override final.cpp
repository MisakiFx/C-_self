#include <iostream>
using namespace std;
//override �� final
class Base1 final//final�ؼ��ֲ������̳� 
{
	
}; 
class Derived : public Base1//������� 
{
	
};
class Base2
{
	virtual void f() final;//final�ؼ��֣����������� 
};
class Derived2 : public Base2
{
	void f();//�������	
};
int main()
{
	
}
