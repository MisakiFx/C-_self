#include <iostream>
#include <vector> 
#include <algorithm>/* 算法 */
using namespace std;
int main()
{
	//数组的替代品vector容器 
	//是一个快速的动态分配内存的容器
	//大小可以动态扩展，动态数组
	//可以插入和删除函数
	//vector<类型名> 对象名(数组长度) 
	vector<double> vec1;
	vector<string> vec2(5);//初始给五个空间 
	vector<int> vec3(20,998);//给20个空间，每个都是998
	//*************************************************************************************** 
	//常用函数
	vector<double> vecDouble={3,2,1};
	//向容器中插入数字
	vecDouble.push_back(100.0);//push_back在尾部加入数字
	/*第一种打印方法（不通用）*/ 
	for(int i=0;i<vecDouble.size();i++)//size()量取容器的大小 
	{
		cout << vecDouble[i] << endl;
	}
	//********************************************************************** 
	/*第二种打印方法：集合的通用遍历方法，使用迭代器*/
	//以下是基本用法
	vector<double>::iterator it;//得到迭代器对象命名为  'it',迭代器对象实际上是一个指针 
	/*让相应类型的迭代器从容器的开始遍历到容器的末尾*/
	for(it = vecDouble.begin();it!=vecDouble.end(); ++it)//begin()从容器的开始，end()到容器的末尾
	{
		cout << *it << endl;
	}
	//********************************************************************************************* 
	//排序 (要加算法头文件)
	sort(vecDouble.begin(),vecDouble.end());//由小到大顺序排序 
	for(it=vecDouble.begin();it!=vecDouble.end();++it)
	{
		cout << *it <<endl;
	}
	reverse(vecDouble.begin(),vecDouble.end());//由大到小逆序排序 
	for(it=vecDouble.begin();it!=vecDouble.end();++it)
	{
		cout << *it <<endl;
	}
	//***************************************************************************************
	//	
	
	 
}
