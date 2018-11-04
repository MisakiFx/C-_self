#include <iostream>
using namespace std;
int sum(int & num)
{
	num++;
	return num;
}
int main()
{
	int num = 10;
 	//sum(num)++;//返回引用类型的函数可以作为左值，所以result的值也被修改
	//解决方案是将返回值类型前加const 
	cout << sum(num) + 1 << endl;
}
