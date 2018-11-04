#include <iostream>
using namespace std;
constexpr int get_size()
{
	return 20;
}
int main()
{
	//constexpr函数：当其所有参数都是constexpr时一定返回constexpr
	 constexpr int foo = get_size();
	 cout << foo << endl;
}
