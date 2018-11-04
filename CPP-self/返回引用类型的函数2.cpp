#include <iostream>
using namespace std;
int & sum(int & num1, int & num2)
{
	num1++;
	num2++; 
	//返回引用类型的函数返回引用时必须包含被返回的引用对象
	//return num1+num2;不合法 
} 
int main()
{
	int num1 = 10;
	int num2 = 15;
	int result = sum(num1,num2);//当没有给返回引用类型的函数设置返回值时，会自动返回最后更新的引用参数，返回num2 
	cout << result << endl;
} 
