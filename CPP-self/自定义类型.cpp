#include <iostream>
using namespace std;
int main()
{
	//C语言传统写法 
	typedef double Area, Volume;
	typedef int Natural;
	Natural i1, i2;
	Area a;
	Volume v;
	cout << "sizoef(Volume) = " << sizeof(Volume) << endl;
	cout << "sizeof(Area) = " << sizeof(Area) << endl;
	cout << "sizeof(Natural) = " << sizeof(Natural) << endl;
	/****************************************/
	/*using 新类型名 = 已有类型名*/
	using Volumi = double;
	cout << "sizeof(Volumi) = " << sizeof(Volumi) << endl;
	/*****************************************/
	//枚举类型(不限定作用域，C语言继承)
	enum Weekday//(常量)
	{
		SUN,
		MON,
		TUE,
		WED,
		THU,
		FRI,
		SAT,
	};
	/*
	1、枚举元素是常量，不能赋值
	2、枚举元素具有默认值，它们依次为：0，1，2……
	3、也可以在声明时另行指定枚举元素的值
	4、枚举值可以进行关系运算
	5、整数值不能直接赋值给枚举变量 
	*/
	int b = 1;
	Weekday day;
	day = Weekday(b);
	cout << "day = " << day << endl; 
	/******************************************************/
	//auto 自动类型
	int val1 = 1;
	double val2 = 2;
	auto val = val1 + val2;
	cout << "sizeof(val) = " << sizeof(val) << endl;
	//decltype :定义一个变量与某一表达式的类型相同，单兵不用该表达式初始化变量
	double i = 1;
	decltype(i)j = 2;//表示定义j = 2类型为 i 的类型double
	cout << "j = " << j << endl;
	cout << "sizeof(j) = " << sizeof(j) << endl; 
}
