#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;
int main()
{
	//����cout��ʾ����
	//1��ǿ����С���ķ�ʽ��ʾ 
	cout << fixed;
	//2��������ʾ�ľ���
	cout << setprecision(2); 
	double num = 100.0 / 3.0;
	cout << num * 100000000 << endl;
	printf("%.2lf\n",num*100000000);
	//��setw�������ÿ�� 
	cout << setw(8);
	cout << "|" << setw(-8) << 3.14 << "|" << endl;//sewֱ�۽���������ĵ�һ�仰
	 
}
