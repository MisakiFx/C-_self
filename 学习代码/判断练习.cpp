#include <iostream>
using namespace std;
int main()
{
	/*��ϰ1*/ 
	char pan='\0';
	cout << "������һ���ַ������ж��Ƿ�Ϸ���" << endl;
	cin >> pan;
	if(pan<=96&&pan>=65)
	{
		cout << "����Ϸ�" << endl;
	}
	else
	{
		cout << "���벻�Ϸ�" << endl;
	}
	/*��ϰ2*/
	double price1=35000;
	double price2=11044.5;
	double price3=1535.0;
	int choose;
	cout << "1��·��˹����\n"
		 << "2��������\n"
		 << "3�����ζ�" << endl;
	cout << "�����빺��Ķ����ı��" << endl;
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
