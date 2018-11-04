#include <iostream>
using namespace std;
void sample(int = 10);//在定义的时候给参数默认值
void sample(int num)//或者在声明时给参数默认值，不可同时出现 
{
	cout << num << endl;
} 
void test1(int a, int b = 5, int c = 10);//正确
void test2(int a, int b = 5, int c); //错误，默认参数后的所有参数都必须有默认值 
int main()
{
	sample();//使用函数默认参数 
	sample(123);//再使用其它参数不会影响 
} 
