#include <iostream>
using namespace std;
class IntNum
{
	public:
		IntNum(int x = 0):xptr(new int(x))//构造函数 
		{
			cout << "Calling constructor..." << endl;
		}
		IntNum(const IntNum & n):xptr(new int(*n.xptr))//深层复制构造函数（成员变量有指针时使用），新创建空间给新的对象，并且将值赋值过去 
		{
			cout << "Calling copy constructor..." << endl;
		}
		IntNum(IntNum && n):xptr(n.xptr)//移动构造函数,实际是将一个对象里的指针赋值给新的对象并将原来的对象的指针置空 
		{
			n.xptr = nullptr;
			cout << "Calling move constructor..." << endl;
		}
		~IntNum()
		{
			delete xptr;
			cout << "Calling Destructing..." << endl;
		}
		int getInt()
		{
			return *xptr;
		}
	private:
		int *xptr;
};
IntNum getNum()
{
	IntNum a;
	return a;
}
int main()
{
	cout << getNum().getInt() << endl;
} 
