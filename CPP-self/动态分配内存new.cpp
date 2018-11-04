#include <iostream>
using namespace std;
int main()
{
	//动态分配内存（运行阶段分配内存）
	//与malloc与free相似
	int * ptr_num = new int[5];
	int * ptr_num2 = new int(45);//给指针2分配一个int 型空间并初始化为45 
	*(ptr_num)=1;
	cout << ptr_num[0] << endl;//与c完全一致 
	cout << *ptr_num2 << endl;
	delete[] ptr_num;//delete只能释放new分配的内存;配套使用释放内存空间
	ptr_num=0;//防止生成野指针 
	/*程序的内存分配：堆和栈*/
	/*栈区（stack）效率高 
	int num = 90; 
	*由编译器自动分配释放，一般用于分配函数的参数值，局部变量的值等，先进后出 
	**堆区（heap）效率低，真正干事的内存区域 
	new,malloc
	*一般由程序员分配，若程序不释放，程序结束时可能由操作系统回收
	**全局区（static）
	const int num = 11; 
	*存放常量和静态变量
	**文字常量区
	*常量字符串存放处
	**程序代码区
	*存放函数体的二进制代码 
	*/ 
} 
