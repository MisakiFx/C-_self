#include <iostream>
using namespace std;
void Swap(int, int);
void Swap2(int*, int*);
void Swap3(int&, int&);
int main()
{
	int num1 = 10,num2 = 5;
	Swap(num1, num2);//副本传递，不会实际进行原始数据的交换 
	cout << "Swap1后：" << num1 << '\t' << num2 << endl;
	Swap2(&num1, &num2);//指针的副本传递，原始数据的指针并不会交换 
	cout << "Swap2后：" << num1 << '\t' << num2 << endl;
	Swap3(num1, num2);//引用传递，相当于传入数据本身，原始数据改变 
	cout << "Swap3后：" << num1 << '\t' << num2 << endl;
	//使用引用作为参数传递的好处：
	//1、可以更加简便的书写代码
	//2、可以直接传递某个对象，而不只是把对象复制一份
	//如果不希望函数修改引用的值，给参数前加上const 
} 
void Swap(int num1, int num2)
{
	int temp;
	temp = num1;
	num1 = num2;
	num2 = temp;
}
void Swap2(int* p1, int* p2)
{
	int * temp;
	temp = p1;
	p1 = p2;
	p2 = temp;
}
void Swap3(int &ref1, int &ref2)//相当于传入原始数据 
{
	int temp;
	temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}
