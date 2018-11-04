#include <iostream>
using namespace std;
int Add(int, int = 0, int = 0);//定义或声明给默认参数二选一,但必须在调用函数前给默认参数 
int main()
{
	cout << Add(4,5) << endl;
}
int Add(int a, int b, int c)
{
	return a + b + c;
}  
