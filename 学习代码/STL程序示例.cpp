#include <iostream>
#include <vector>//向量容器头文件 
#include <iterator>//迭代器头文件 
#include <algorithm>//算法头文件 
#include <functional>//函数对象头文件 
using namespace std;
int main()
{
	const int N = 5;
	vector<int> s(N);//容器
	for(int i = 0; i < N; i++)
		cin >> s[i];
	transform/*算法*/(s.begin()/*迭代器*/, s.end()/*迭代器*/, ostream_iterator<int>/*迭代器*/(cout, " "), negate<int>()/*函数对象*/);
	/*
	transform算法：
	原型：
	transform <class InputIterator, class OutputIterator, class UnaryFunction>
	OutputIterator transform(InputIterator first, InputIterator last, OutputIterator result, UnaryFunction op)
	{
		for(; first != last; ++first, ++result)
			*result = op(*first);
		return result;
	}
	1、transform算法顺序遍历first和last两个迭代器所指向的元素；
	2、将每个元素的值作为函数对象op的参数
	3、 将op的返回值通过迭代器result顺序输出；
	4、遍历完成后result迭代器指向的是输出的最后一个元素的下一个位置，treansform会将该迭代器返回 
	**/
	cout << endl; 
}
