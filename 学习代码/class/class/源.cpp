#include <iostream>
using namespace std;
class Student//默认成员都是私有权限，如果使用struct默认的成员都是公有的了，其它没有任何区别
{
private://私有成员:只能在本类的成员函数内使用
	int nNumb = 1;
public://公有成员:在类内类外都能调用
	char sName[20];
	float fMath;
	void SetData(int n, char* p, float f)
	{

	}
	void Print()
	{
	cout << this->nNumb << endl;//this指针，用来指向本类中的成员
	//this指针是一个指针常量，可以改变指向变量的数据但不可改变指向哪个类
	}
};
int main()
{
	Student d1, d2;
	d1.Print();
}