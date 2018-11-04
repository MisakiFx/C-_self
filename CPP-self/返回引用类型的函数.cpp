#include <iostream>
using namespace std;
int & sum()
{
	int sum = 10;//定义局部变量 
	int &rNum = sum;//定义局部变量的引用 
	return rNum;//返回局部变量的引用 
	//函数执行完毕局部变量内存被回收 
	//内存回收并不是把内存保存的数值清0，而是指内存中程序所占用的这块内存重新归内存所属，不被程序继续占用 
 } 
void test()
{
	int x = 1;
	int y = 2;
	int z = 1024;
	
}
int main()
{
	//函数返回引用类型：
	//1、千万不要返回局部变量的引用，就像不要返回在函数内定义的变量一样，内存会被回收 
	int &result = sum();
	test();
	cout << result << endl;
	//result值被改变， 因为原本内存被回收现在又被test函数使用所以值被更改 
} 
