#include <iostream>
using namespace std;
struct Stime//用结构体定义类 
{
	int nHour;
	int nMin;
	int nSec;
	void SetTime(int h, int m, int s)//c++中可在结构体内定义声明函数 
	{
		nHour = h;
		nMin = m;
		nSec = s;
	}	
	void Print()
	{
		cout << nHour << ',' << nMin << ',' << nSec << endl;
	}
}; 
int main()
{
	Stime Morn, noon;//定义对象 
	Morn.SetTime(9,36,30);//通过函数对本类（结构体）中的变量进行更改 
	noon.SetTime(15, 36, 30);
	cout << sizeof(Morn) << endl;
	cout << sizeof(noon) << endl; 
	Morn.Print();
	noon.Print();
} 
