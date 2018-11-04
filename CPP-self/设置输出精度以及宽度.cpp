#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;
int main()
{
	//控制cout显示精度
	//1、强制以小数的方式显示 
	cout << fixed;
	//2、控制显示的精度
	cout << setprecision(2); 
	double num = 100.0 / 3.0;
	cout << num * 100000000 << endl;
	printf("%.2lf\n",num*100000000);
	//用setw函数设置宽度 
	cout << setw(8);
	cout << "|" << setw(-8) << 3.14 << "|" << endl;//sew直观接下来输出的第一句话
	 
}
