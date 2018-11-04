#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>
#include <string>
using namespace std;
/*
列表（list） 
1、在任意位置插入和删除元素都很快
2、不支持随机访问
3、结合(splice)操作：s1.splice(p,s2,q1,q2):将s2中[q1,q2)移动到s1中p所指向元素之前 
*/
int main()
{
	string names1[] = {"Alice", "Helen", "Lucy", "Susan"};
	string names2[]	= {"Bob", "David", "Levin", "Mike"};
	//用names1数组的内容构造列表s1
	list<string> s1(names1.begin(), names1.end());
	//用names2数组内的容构造列表s2
	list<string> s2(names2, names2 + 4);
	//将s1的第一个元素放到s2的最后
	s2.splice(s2.end(), s1, s1.begin()); 
	list<string>::iterator iter1 = s1.begin();//iter1指向s1的首
	advance(iter1, 2);//iter1前进两个元素，指向s1的第三个元素
	list<string>::iterator iter2 = s2.begin();//iter2指向s2的首
	++iter2;//iter2前进一个元素，指向s2第二个元素
	list<string>::iterator iter3 = iter2;//用iter2初始化iter3
	advance(iter3, 2);//让iter3前景两个元素，指向s2的第4个元素
	//将[iter2,iter3)范围内的节点接到s1中iter1指向的节点前
	s1.splice(iter1, s2, iter2, iter3);
	//分别将s1和s2输出
	copy(s1.begin(), s1.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	copy(s2.begin(), s2.end(), ostream_iterator<string>(cout, " "));
	cout << endl; 
	 
}
