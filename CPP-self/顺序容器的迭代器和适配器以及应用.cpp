#include <iostream>
#include <string>
#include <stack>
using namespace std;
/*
顺序容器的插入迭代器
1、用于向容器头部、尾部或中间指定位置插入元素的迭代器
2、包括前叉迭代器(front_inserter)、后插迭代器(back_inserter)
和任意位置插入迭代器(inserter) 
*/
/*
顺序容器的适配器
1、以顺序容器为基础构建一些常用数据结构，是对顺序容器的封装
栈(stack):最先亚茹的元素最后被弹出
队列(queue):最先压入的元素最先被弹出
优先级队列(priority_queue)：最“大”的元素最先被弹出 
*/
/*
s1 op s2 op可以是==、!=、<、<=、>、>=之一，它会对两个容器适配器之间的元素按字典序进行比较
s.size() 返回s的元素个数
s.empty() 返回s是否为空
s.push(t) 将元素t压入到s中
s.pop() 将一个元素从s中弹出，对于栈来说，每次弹出的是最后被压入的元素，而对于队列，每次被弹出的是最先被压入的元素
不支持迭代器，因为它们不允许对任意元素进行访问
栈的操作
s.top() 返回栈顶元素的引用
队列操作
s.front() 获得队头元素的引用
s.back() 获得队尾元素的引用
*/
int main()
{
	stack<char> s;//栈也是stl中的一个类模板 
	string str;
	cin >> str;//从键盘输入一个字符串
	//将字符串的每个元素顺序压入栈中
	for(string::iterator iter = str.begin(); iter != str.end(); ++iter)
	{
		s.push(*iter);
	} 
	//将栈中的元素顺序弹出并输出
	while(!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	cout << endl; 
}
