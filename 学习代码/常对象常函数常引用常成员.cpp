#include <iostream>
using namespace std;
class A 
{
	public:
		A(int i, int j):a(0)//常成员必须在构造函数的初始化列表中进行赋值，不允许出现在函数体中 
		{
			x = i;
			y = j;
		}
		A():a(0)//每个构造函数都要出现常成员 
		{
			
		}
		/*
		常成员函数：用于处理常对象 
		*/ 
		void show() const//常成员函数，只能用常成员函数来处理常对象 
		{
			cout << x << "," << y << endl;
		} 
	private:
		int x = 0, y = 0;
		/*
		常成员只能初始化，初始化后不允许改变其值 
		*/
		const int a;//常成员 
		static const int b; //静态常数据成员 
};
const int A::b = 0; //静态常数据成员在类外单独赋初始值 
int main()
{
	/*
	常对象，不能改表成员变量的对象,只能调用常成员函数 
	*/
	A const a(3, 4);//声明常对象，常对象不能被更新
	A b;
	b.show();//一般对象也可以调用常成员函数 
	a.show(); //调用常成员函数 
	/*
	常引用，复制构造函数就用了常引用，和常量指针类似，只能读取值不能修改值，引用不可移不可改 
	*/
}
