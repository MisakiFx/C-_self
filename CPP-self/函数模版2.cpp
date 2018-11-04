#include <iostream>
#include <vector>
/*
函数模版和类模板一样，在使用时如果有自定义类型不在函数参数里或者无法确定的类型需要用尖括号表示出来，按顺序表示
把无法确定的类型卸载类型表的前面，后面确定的就不用写出来了 
*/
using namespace std;
template<class Y, class T>
T abs1(T x)
{
	vector<Y> s;
	return  x < 0 ? -x : x;
}
int main()
{
	cout << abs1<int>(-5) << '\t' << abs1<double>(-5.5) << endl;
} 
