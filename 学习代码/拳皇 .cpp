#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;
int main()
{
	int hp1=100;
	int hp2=100;
	int attack1=0;
	int attack2=0;
	int randNum;//������� 
	//ģ����ҳ���
	//����������������������ż������˭�ȳ���
	while(hp1>0 && hp2>0)
	{
		srand(time(NULL));
		randNum=rand();
		if(randNum%2==1)//player1�ȳ��� 
		{
			attack1=rand()%11+5;
			attack2=rand()%11+5;
			hp2-=attack1;
			hp1-=attack2;
			
		}
		else//player2�ȳ��� 
		{
			attack1=rand()%11+5;
			attack2=rand()%11+5;
			hp1-=attack2;
			hp2-=attack1;
		}
	cout << "player1 HP =" << hp1 << endl;
	cout << "player2 HP =" << hp2 << endl;
	cout << "*********************************************" << endl; 
	}
	//��ӡ���ս��
	cout << "player1 HP =" << hp1 << endl;
	cout << "player2 HP =" << hp2 << endl;
}
