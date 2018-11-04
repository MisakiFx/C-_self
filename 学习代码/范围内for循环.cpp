#include <iostream>
using namespace std;
int main()
{
	int a[10] = {0};
	for(int & e : a)
	{
		e += 1;
		cout << e << '\t';
	}
}
