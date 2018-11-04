#include <iostream>
using namespace std;
//单继承情况下派生类的构造函数 
class B
{
	public:
		B();
		B(int i);
		~B();
		void print() const;
	private:
		int b;
}; 
B::B()
{
	b = 0;
	cout << "B's default constructor called." << endl;
}
B::B(int i)
{
	b = i;
	cout << "B's constructor called." << endl;
}
B::~B()
{
	cout << "B's destructor called" << endl;
}
void B::print() const
{
	cout << b << endl;
}
class C : public B
{
	public:
		C();
		C(int i, int j);
		~C();
		void print() const;
	private:
		int c;
};
C::C()
{
	c = 0;
	cout << "C's default constructor called." << endl;
}
C::C(int i, int j) : B(i),c(j)//在构造函数初始化列表中的最前面写上父类名1(参数1),父类名2(参数2)...+本来成员（含对象成员）的初始化列表 
{
	cout << "C's destructor called" << endl;
}
C::~C()
{
	cout << "C's destructor called" << endl;
}
void C::print() const
{
	B::print();
	cout << c << endl;
}
int main()
{
	C obj(5,6);
	obj.print();
}
