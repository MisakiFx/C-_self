#include <iostream>
using namespace std;
/*
前向引用声明注意事项：
1、在提供一个完整的类声明之前，不能声明该类的对象，也不能在内联成员函数中使用该类的对象。
2、在使用前向引用声明时，只能使用被声明的符号，而不能涉及类的任何细节。 
*/ 
class B;//前向引用声明，类体在其它地方出现 
class A
{
	public:
		void f(B b);//两个类互相引用 
};
class B
{
	public:
		void f(A a);//两个类互相引用 
};
int main()
{
	
} 
