#include <iostream>
using namespace std;
int main()
{
	//用指针定义二维数组
	//要给指针一个维度
	int (*p)[3] = new int [5][3]; 
	
	p[2][2]=123;
	
	for (int i = 0;i<5;i++)
	{
		for (int j=0;j<3;j++)
		{
			cout << p[i][j] << '\t' ;
		}
		cout << '\n' << endl;
	 } 
} 
