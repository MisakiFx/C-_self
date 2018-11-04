#include <iostream>
#include <vector>
using namespace std;
int main()
{
	//基于范围的for循环遍历vector数组
	vector<int> v = {1, 2, 3};
	for(auto i = v.begin(); i != v.end(); ++i)
	{
		cout << *i << '\t';
	}
	cout << endl;
	for(auto e : v)
	{
		cout << e << '\t';
	}
	cout << endl; 
}
