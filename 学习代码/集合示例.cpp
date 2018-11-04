#include <iostream>
#include <set>//集合头文件 
#include <iterator>
#include <utility>
using namespace std;
/*
集合中插入的元素会自动排序，由小到大 
*/
int main()
{
	set<double> s;
	while(true)
	{
		double v;
		cin >> v;
		if(v == 0)
		{
			break;//(0表示输出结束)
		}
		//尝试将v插入
		pair<set<double>::iterator, bool> r = s.insert(v); 
		if(!r.second)//如果b已经存在，输出提示信息
		cout << v << "is duplicated" << endl; 
	}
	//得到第一个元素的迭代器
	set<double>::iterator iter1 = s.begin();
	//得到末尾的迭代器
	set<double>::iterator iter2 = s.end();
	//得到最小和最大元素的中值
	double medium = (*iter1 + *(--iter2)) / 2;
	//输出小于或等于中值的元素
	cout << "<= medium:";
	copy(s.begin(), s.upper_bound(medium), ostream_iterator<double>(cout, " "));
	cout << endl;
	cout << ">= medium:";
	copy(s.lower_bound(medium), s.end(), ostream_iterator<double>(cout, " "));
	cout << endl; 
}
