#include <iostream>
using namespace std;
//����������ͨ�����ڽ��ͨ�����๹������������Ķ�������ת��Ϊ���࣬
//���ڶ������ͷſռ�ʱ����ֻ���ø��������������������������������������ɵ��ڴ�й©������ 
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
