#include <iostream>
using namespace std;
int main()
{
	//C���Դ�ͳд�� 
	typedef double Area, Volume;
	typedef int Natural;
	Natural i1, i2;
	Area a;
	Volume v;
	cout << "sizoef(Volume) = " << sizeof(Volume) << endl;
	cout << "sizeof(Area) = " << sizeof(Area) << endl;
	cout << "sizeof(Natural) = " << sizeof(Natural) << endl;
	/****************************************/
	/*using �������� = ����������*/
	using Volumi = double;
	cout << "sizeof(Volumi) = " << sizeof(Volumi) << endl;
	/*****************************************/
	//ö������(���޶�������C���Լ̳�)
	enum Weekday//(����)
	{
		SUN,
		MON,
		TUE,
		WED,
		THU,
		FRI,
		SAT,
	};
	/*
	1��ö��Ԫ���ǳ��������ܸ�ֵ
	2��ö��Ԫ�ؾ���Ĭ��ֵ����������Ϊ��0��1��2����
	3��Ҳ����������ʱ����ָ��ö��Ԫ�ص�ֵ
	4��ö��ֵ���Խ��й�ϵ����
	5������ֵ����ֱ�Ӹ�ֵ��ö�ٱ��� 
	*/
	int b = 1;
	Weekday day;
	day = Weekday(b);
	cout << "day = " << day << endl; 
	/******************************************************/
	//auto �Զ�����
	int val1 = 1;
	double val2 = 2;
	auto val = val1 + val2;
	cout << "sizeof(val) = " << sizeof(val) << endl;
	//decltype :����һ��������ĳһ���ʽ��������ͬ���������øñ��ʽ��ʼ������
	double i = 1;
	decltype(i)j = 2;//��ʾ����j = 2����Ϊ i ������double
	cout << "j = " << j << endl;
	cout << "sizeof(j) = " << sizeof(j) << endl; 
}
