#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
int main()
{
	int num;
	char ch1,ch2 ,ch3; 
	cout << "请输入：" << endl;
	cin >> num;//scanf("%d",&num);自动选取数字到第一个非数字为止 
	cin >> ch1;//scanf("%c",ch);自动忽略空白符 
	cin.get(ch2);//不忽略空白符 
	ch3 = cin.get();//不忽略空白符 
	/*排版练习*/ 
	cout << left;//左对齐 
	cout << setfill('_');//设置填充，空白填充 
	cout << setw(-8) <<num << '\n' << setw(4) << ch1 << setw(4) << ch2 << setw(4) << ch3 << endl;
	cout << hex << num << endl; 
	cout.setf(ios::oct, ios::basefield);//设置16进制显示 
	/*
	setprecision:设置小数点后保留几位小数 
	dec:10进制
	hex:16进制
	oct:8进制
	ws:T恤空白符
	endl:插入换行符，并刷新流
	ends:插入空字符 
	*/ 
	cout.setf(ios::showbase | ios::uppercase);//设置基指示符和数值中的字母大写输出 
	cout << num << endl;
	cout.unsetf(ios::oct);//恢复默认十进制 
	cout << num << endl;
} 
