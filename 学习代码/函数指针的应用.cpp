#include <iostream>
using namespace std;
/** �ӷ� */
double add(double, double); 
/** ���� */
double sub(double, double);
/** �˷� */
double mul(double, double);
/** ���� */
double div(double, double);
/** ��ӡ���������������һ������ָ�룬����double���� */
void print_result(double (*)(double, double),double, double);
int main()
{
	double (*ptrCalc)(double, double);//���ﻹ��������д��auto ptrCalc = add;(��auto�Զ�����ָ�����ͣ�������Ҫ����һ��ָ���ʼ��)����������typedef�������� 
	double num1,num2;
	char op;
	cout << "���������ʽ��";
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
		cout << "��������Ϊ0" << endl;
		return 0;
	}
	return num1 / num2;
}
void print_result(double (*ptrCalc)(double, double),double num1, double num2)
{
	double result = ptrCalc(num1,num2);
	cout << "����ǣ�" << result << endl;
}
 
