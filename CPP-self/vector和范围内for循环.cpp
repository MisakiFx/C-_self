#include <iostream>
#include <vector>
using namespace std;
int main()
{
	//���ڷ�Χ��forѭ������vector����
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
