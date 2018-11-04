#include <iostream>
using namespace std;
//将运算符重载为类外非成员函数 
//函数参数要包含所有操作数,而且操作数要有一个是自定义类型 
//重载运算符实现复数+、-复数 
class Complex
{
	public:
		Complex(double r = 0.0, double i = 0.0) : real(r), imag(i)
		{
			
		}
		friend Complex operator + (const Complex & c1,const Complex & c2);
		friend Complex operator - (const Complex & c1,const Complex & c2);
		friend ostream & operator << (ostream & out, const Complex & c);
	private:
		double real;
		double imag;
};
Complex operator + (const Complex & c1, const Complex & c2)
{
	return Complex(c1.real + c2.real, c1.imag + c2.imag);//构造临时无名对象进行返回 
}
Complex operator - (const Complex & c1, const Complex & c2)
{
	return Complex(c1.real - c2. real, c1.imag - c2.imag);
}
ostream & operator << (ostream & out, const Complex & c)//第一个参数为流对象的一个引用 
{
	cout << "(" << c.real << "," << c.imag << ")" << endl;
}
int main()
{
	Complex c1(5,4),c2(2,10),c3;
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;//利用运算符重载进行打印 
	c3 = c1 - c2;//operator(c1,c2)
	cout << "c3 = c1 - c2 = " << c3 << endl;
	c3 = c1 + c2;
	cout << "c3 = c1 + c2 = " << c3 << endl;
} 
