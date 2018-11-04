#include <iostream>
#include <cmath>
#define PAI 3.14 //效率不高，最好用const 
using namespace std;
int main()
{
	double r = 4.5;
	double h = 90.0;
	double v;
	v = PAI * pow (r,2) * h;
	cout << v << endl;
} 
