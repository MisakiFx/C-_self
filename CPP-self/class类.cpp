#include <iostream>
using namespace std;
struct Stime//�ýṹ�嶨���� 
{
	int nHour;
	int nMin;
	int nSec;
	void SetTime(int h, int m, int s)//c++�п��ڽṹ���ڶ����������� 
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
	Stime Morn, noon;//������� 
	Morn.SetTime(9,36,30);//ͨ�������Ա��ࣨ�ṹ�壩�еı������и��� 
	noon.SetTime(15, 36, 30);
	cout << sizeof(Morn) << endl;
	cout << sizeof(noon) << endl; 
	Morn.Print();
	noon.Print();
} 
