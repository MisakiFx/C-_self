#include <iostream>
#include <cstdlib>
using namespace std;
//函数都在<stdlib.h>中 
int main()
{
	int a = atoi("123456");
	//atoi函数，将输入的数字字符根据理解转换为int型 
	//如果字符不是数字字符会返回0，但是支持正负号，不支持运算，
	//空格将被忽略，但中间如果间隔空格将停止函数 
	cout << a << endl;
	//atof与atoi相似，不过类型是转换为double型 
}
