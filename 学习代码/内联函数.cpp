#include <iostream>
using namespace std;
inline int S(int);//声明内联函数，或者在定义时加inline,其它和常规函数一样 
int main()
{
	/*常规函数通过函数指针找到函数进行执行
	内联函数通过函数代码的替换进行执行（效率更高）,适用于代码执行时间短的情况下 
	*/ 
	int result = S(5);
	cout << result << endl; 
} 
int S(int num)
{
	return num * num;
}
