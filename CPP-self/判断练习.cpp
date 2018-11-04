#include <iostream>
using namespace std;
int main()
{
	/*练习1*/ 
	char pan='\0';
	cout << "请输入一个字符我来判断是否合法：" << endl;
	cin >> pan;
	if(pan<=96&&pan>=65)
	{
		cout << "输入合法" << endl;
	}
	else
	{
		cout << "输入不合法" << endl;
	}
	/*练习2*/
	double price1=35000;
	double price2=11044.5;
	double price3=1535.0;
	int choose;
	cout << "1、路易斯威登\n"
		 << "2、爱马仕\n"
		 << "3、香奈儿" << endl;
	cout << "请输入购买的东西的编号" << endl;
	cin >> choose;
	switch(choose)
	{
	
		case 1:
			cout << price1*0.7 << endl;
			break;
		case 2:
			cout << price2*0.7 <<endl;
			break;	
		case 3:
			cout << price3 << endl;
			break;
		default:
			break;
	}
} 
