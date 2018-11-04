#include <iostream>
using namespace std;
/*
引用不能直接引用数组，但是引用可以引用指针， 
语法：int * &q = p;(p为指针) 
**/
int main()
{
	//在c++中多用引用，减少指针使用，因为引用效率更高 
	//引用：给对象起了另一个名字（引用即别名）
	int int_value = 1024; 
	//引用必须要有值 
	int &value = int_value;//value此时也指向int_value是它的另一个名字
	cout << value <<endl;	 
	//引用只能绑定在对象上，想要绑定数值需要变为常量
	const int &refValue = 100; 
	cout << refValue << endl; 
	/*
	引用和指针两者的关系：
	引用还是指针，封装了指针，，获取地址时，编译器会进行内部自动转换 
	*/
	//一个指针只占4个字节 
	//引用相当于指针常量，始终效忠于一个变量，引用变量作为参数，传递原始数据 
} 
