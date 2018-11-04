#include <iostream>
using namespace std;
//保护继承：基类中的公有和保护成员到了子类中全部成为保护成员
//外部对象不可直接访问父类中的所有成员
//子类内部可以访问父类中的公有和保护成员
//保护成员无法在类外使用，但是可以在类内自由使用，派生类中也可以自由使用 
{
	public:
		void InitX()
		{
			x = 1;
			cout << x << endl;
		}
	protected:
		int x;	
};
int main()
{
	Point a;
	a.InitX();
}
