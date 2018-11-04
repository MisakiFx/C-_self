#include <iostream>
//input & output 
//stream流
using namespace std; //使用std(标准)命名空间 
int main()
{
	cout<<"Hello World!"<<endl; //输出流 /'<<'插入运算符 
	//表示把一个字符串插入到输出流中 
	//endl=end line
	//如果不写命名空间就要这么写 
	//std::cout<<"Hello World"<<std::endl; ‘::’表示从属关系 
	/*
	从原理上看输出是一个流，可以理解为从程序流出的一系列字符
	endl和/n的区别：
	/n：只换行
	endl：先换行，再fflush(stdin)（清空键盘缓冲区），很友好啊 
	*/
}
