#include <iostream>
#include <iterator>
#include <algorithm> 
using namespace std;
/*
1、输入流迭代器:istream_iterator<T> *(p++)获得下一个输入的元素 
2、输出流迭代器:ostream_iterator<T> (*p++) = x将x输出到输出流 
3、二者都属于适配器:
1)适配器是用来为已有对象提供新的接口的对象
2)输入流适配器和输出流适配器为流对象提供了迭代器的接口 
*/
/*
迭代器的分类
1、输入迭代器：从序列中读取数据，如输入流迭代器 
2、输出迭代器：允许向序列中写入数据，如输出流迭代器 
3、前向迭代器：既是输入迭代器又是输出迭代器，并且可以对序列进行单向的遍历 
4、双向迭代器：与前向迭代器相似，但是两个方向上都可以对数据遍历 
5、随机访问迭代器：也是双向迭代器，但能够在序列中的任意两个位置之间进行跳转 
6、迭代器 = 泛型的指针 
*/
double square(double x)
{
	return x * x;
}
int main()
{
	transform(istream_iterator<double>(cin), istream_iterator<double>()/*默认参数表示输入流的结束位置*/, ostream_iterator<double>(cout, "\t"), square);
	cout << endl;
}
