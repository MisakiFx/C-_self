#include <iostream>
using namespace std;
int devide(int x, int y) throw(int)
{
	if(y == 0)
	{
		throw x;
	}
	return x / y;
}
int main()
{
	try
	{
		cout << "5 / 2 = " << devide(5, 2) << endl;
		cout << "8 / 0 = " << devide(8, 0) << endl;
		cout << "7 / 1 = " << devide(7, 1) << endl;
	}
	catch(int e)
	{
		cout << e << "is devided by zero!" << endl;
	}
	cout << "That is ok!" << endl;
}
