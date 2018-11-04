#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	char ch='a';
	char * ptr_ch = &ch;
	cout << ptr_ch << '\t' << *ptr_ch << endl;//在c和c++中char型的指针默认定义为字符串指针char* ch="12312132"，要进行强制的类型转换转换为指针型 
	//空指针
	int *ptr1=nullptr;//c++里的空指针等于int *ptr1=0;
	int *ptr2=0;
	int *ptr3=NULL;//需要包含<cstdlib> 
	//****************************************************************************************************************** 
	//void指针可以存放任意类型指针的指针类型
	//不能确定指针所指向的变量的类型因此不能用void指针修改变量的值 
	//void类型指针一般用来和别的指针进行比较，作为函数的输入和输出 
	double num=3.14;
	double * ptr_num1=&num;
	void * vptr_num1=&num;//void类型指针，任意类型转换 
	cout << boolalpha;
	cout << (ptr_num1==vptr_num1) << endl; 
} 
