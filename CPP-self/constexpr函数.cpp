#include <iostream>
using namespace std;
constexpr int get_size()
{
	return 20;
}
int main()
{
	//constexpr�������������в�������constexprʱһ������constexpr
	 constexpr int foo = get_size();
	 cout << foo << endl;
}
