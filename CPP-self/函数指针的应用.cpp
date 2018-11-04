#include <iostream>
using namespace std;
/** 加法 */
double add(double, double); 
/** 减法 */
double sub(double, double);
/** 乘法 */
double mul(double, double);
/** 除法 */
double div(double, double);
/** 打印结果函数，参数是一个函数指针，两个double变量 */
void print_result(double (*)(double, double),double, double);
int main()
{
	double (*ptrCalc)(double, double);//这里还可以这样写：auto ptrCalc = add;(用auto自动调节指针类型，但是需要给他一个指针初始化)，还可以用typedef定义类型 
	double num1,num2;
	char op;
	cout << "请输入计算式：";
	cin >> num1 >> op >> num2;
	switch (op)
	{
		case '+':
			ptrCalc = add;
			break;
		case '-':
			ptrCalc = sub;
			break;
		case '*':
			ptrCalc = mul;
			break;
		case '/':
			ptrCalc = div;
			break;
	 }
	 print_result(ptrCalc,num1,num2); 
}
double add(double num1, double num2)
{
	return num1 + num2;
}
double sub(double num1, double num2)
{
	return num1 - num2;
}
double mul(double num1, double num2)
{
	return num1 * num2;
}
double div(double num1, double num2)
{
	if(num2 == 0)
	{
		cout << "除数不能为0" << endl;
		return 0;
	}
	return num1 / num2;
}
void print_result(double (*ptrCalc)(double, double),double num1, double num2)
{
	double result = ptrCalc(num1,num2);
	cout << "结果是：" << result << endl;
}
 
