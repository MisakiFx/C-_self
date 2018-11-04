#include <iostream>
using namespace std;
int pow(int,int);
int main()
{
	//声明函数指针
	int (*ptr_pow)(int,int); 
	//让函数指针指向函数以便调用
	ptr_pow = pow;//函数名就是函数的地址 
	//调用函数指针
	cout << ptr_pow(3,2) << endl; //方式1
	cout << (*ptr_pow)(3,2) << endl; //方式2 
	cout << pow(3,2) << endl; 
}
int pow(int num1, int num2)
{
	int result = 1;
	for(int i = 0;i < num2; i++)
	{
		result *= num1;
	}
	return result;
 } 
