#include <iostream>
using namespace std;
//虚析构函数通常用在解决通过子类构造对象而把子类的对象类型转换为父类，
//而在对象在释放空间时可能只调用父类的析构函数不调用子类析构函数所可能造成的内存泄漏的问题 
class Base
{
	public:
		virtual ~Base();
};
Base::~Base()
{
	cout << "Base destructor" << endl;
}
class Derived : public Base
{
	public:
		Derived();
		~Derived();
	private:
		int *p;
};
Derived::Derived()
{
	p = new int(0);
}
Derived::~Derived()
{
	cout << "Derived destructor" << endl;
	delete p; 
}
void fun(Base* b)
{
	delete b;
}
int main()
{
	Base *b = new Derived();
	delete b;
}
