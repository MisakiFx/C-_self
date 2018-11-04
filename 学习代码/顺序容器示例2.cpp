#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
/*
向量(vector)
1、一个可以扩展的动态数组
2、随机访问、在尾部插入或删除元素快
3、在中间或头部插入或删除元素慢
4、容量：实际分配空间的大小
5、s.capacity():返回当前容量
6、s.reserve(n):若容量小于n，则对s进行扩展，时期容量至少达到n 
*/
/*
双端队列（deque）
1、在两端插入或删除元素快
2、在中间插入或删除元素慢
3、随机访问较快，但比向量容器慢 
*/
int main()
{
	istream_iterator<int> i1(cin),i2;//建立一对输入流迭代器
	vector<int> s1(i1,i2);//通过输入流迭代器从标准输入流中输入数据 
	sort(s1.begin(), s1.end());//将输入的整数排序
	deque<int> s2;
	for(vector<int>::iterator iter = s1.begin(); iter != s1.end(); ++iter)
	{
		if(*iter % 2 == 0)
		{
			s2.push_back(*iter);
		}
		else
		{
			s2.push_front(*iter);
		}
		copy(s2.begin(), s2.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	} 
}
