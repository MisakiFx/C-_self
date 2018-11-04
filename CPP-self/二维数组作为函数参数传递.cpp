#include <iostream>
using namespace std;
void show(const int (*)[5],int len);
int main()
{
	int arrs[3][5]={
	{1,2,3,5,4},
	{1,2,3,4,5},
	{1,2,3,5,4}
	};
	show(arrs,3);
}
void show(const int arrs[][5],int len)//也可以使用数组指针 
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << arrs[i][j] << "\t" ; 
		}
		cout << endl;
	}
 } 
