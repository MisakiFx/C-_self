#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;
//将来自输入迭代器的n个T类型的数值排序，将结果通过输入迭代器result输出
template <class T, class InputIterator, class OutputIterator>
void mySort(InputIterator first, InputIterator last, OutputIterator result)
{
	//通过输入迭代器将输入数据存入向量容器s中 
	vector<T> s;
	for(; first != last; ++first)
	{
		s.push_back(*first);
	}
	//对s进行排序，sort函数的参数必须是随机访问迭代器
	sort(s.begin(), s.end());
	copy(s.begin(), s.end(), result);//将s序列通过输出序列迭代器输出 
} 
int main()
{
	//将s数组中的内容排序后输出 
	double a[5] = {1.2, 2.4, 0.8, 3.3, 3.2};
	mySort<double>(a, a + 5, ostream_iterator<double>(cout, " "));
	cout << endl;
	//从标准输入读入若干个整数，排序后的结果输出
	mySort<int>(istream_iterator<int>(cin), istream_iterator<int>(), ostream_iterator<int>(cout, " "));
	cout << endl; 
	//迭代器的辅助函数
	//advance(p. n): 对p进行n次自增操作
	//distance(first, last):计算两个迭代器之间的距离，即对first执行多少次“++”操作后能是的first == last 
} 
