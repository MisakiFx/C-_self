#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
int main()
{
	int num;
	char ch1,ch2 ,ch3; 
	cout << "�����룺" << endl;
	cin >> num;//scanf("%d",&num);�Զ�ѡȡ���ֵ���һ��������Ϊֹ 
	cin >> ch1;//scanf("%c",ch);�Զ����Կհ׷� 
	cin.get(ch2);//�����Կհ׷� 
	ch3 = cin.get();//�����Կհ׷� 
	/*�Ű���ϰ*/ 
	cout << left;//����� 
	cout << setfill('_');//������䣬�հ���� 
	cout << setw(-8) <<num << '\n' << setw(4) << ch1 << setw(4) << ch2 << setw(4) << ch3 << endl;
	cout << hex << num << endl; 
	cout.setf(ios::oct, ios::basefield);//����16������ʾ 
	/*
	setprecision:����С���������λС�� 
	dec:10����
	hex:16����
	oct:8����
	ws:T���հ׷�
	endl:���뻻�з�����ˢ����
	ends:������ַ� 
	*/ 
	cout.setf(ios::showbase | ios::uppercase);//���û�ָʾ������ֵ�е���ĸ��д��� 
	cout << num << endl;
	cout.unsetf(ios::oct);//�ָ�Ĭ��ʮ���� 
	cout << num << endl;
} 
