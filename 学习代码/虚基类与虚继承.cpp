#include <iostream>
using namespace std;
//虚基类，为了防止冗余（子类继承了多个相同的基类）而产生的特殊继承方式，是基类只复制一份,要在最开始继承共同基类的时候使用虚继承 
//所有直接或间接继承虚基类的派生类都要在构造函数的初始化列表中给虚基类进行初始化，但是虚基类只接受最远的派生类的参数 
class Base0
{
	public:
		Base0(int var) : var0(var)
		{
			
		}
		int var0;
		void fun0()
		{
			cout << "Member of Base0" << endl;
		}
};
class Base1 : virtual public Base0
{
	public:
	Base1(int var) : Base0(var)
	{
		
	}
	int var1;	
};
class Base2 : virtual public Base0
{
	public:
		Base2(int var) : Base0(var)
		{
			
		}
		int var2;
};
class Derived : public Base1, public Base2
{
	public:
	Derived(int var) : Base0(var), Base1(var), Base2(var)
	{
		
	}
	int var;
	void fun()
	{
		cout << "Member of Derived" << endl;
	}	
};
int main()
{
	Derived d(1);
	d.var0 = 2;//直接访问虚基类的数据成员
	d.fun();//直接访问虚基类的函数成员 
}
