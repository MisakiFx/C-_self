#include <iostream>
#include <cstdlib>
using namespace std;
//c++与c 
int main()
{
	int **p = new int*[20];//分配指针数组
	cout << sizeof(*p) << endl;
	int **p2 = (int**)malloc(sizeof(int*)*20);
	cout << sizeof(*p2) << endl;
	int (*p3)[20] = new int[10][20];//分配二维数组
	cout << sizeof(*p3) << endl;
	int (*p4)[20] = (int(*)[20])malloc(sizeof(int[20])*10);
	cout << sizeof(*p4) << endl;
	delete []p;//释放内存 
	delete []p2;
	delete []p3;
	delete []p4; 
}
