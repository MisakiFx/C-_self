#include <stdio.h>
int Add(int a, int b);
int Dec(int a, int b)
{
	return a - b;
}
int Mult(int a, int b)
{
	return a * b;
}
int(*p)(int, int) = NULL;//声明函数指针p
int main()
{
	//函数指针
	p = Add;
	int i = p(32, 15);//指针类型和参数必须与目标函数完全匹配
	printf("%d",i);
}
//还可以用指针数组来将函数整理起来进行调用
int Add(int a, int b)
{
	return a + b;
}