#include <iostream>
using namespace std;
class Clock
{
	public:
		Clock(int newH, int newM, int newS);//���캯��
		Clock();//Ĭ�Ϲ��캯��
		Clock(const Clock& p) = delete;//���ƹ��캯����һ������±��������Զ����ɣ�����д���ǲ�����Ĭ�ϵĸ��ƹ��캯�� 
		//��һ�ж�����Ҫ���и��Ƶ�ʱ�򶼻��Զ����ø��ƹ��캯��
		//�Զ����ɵ�Ĭ�Ϲ��캯���Ὣ��������ĸ���Ԫ�ؽ���һһ���� 
		void setTime(int newH, int newM, int newS);
		void showTime(); 
	private: 
		int hour, minute, second;
}; 
Clock::Clock(int newH, int newM, int newS):
	hour(newH),minute(newM),second(newS)//��ʼ���б���ʼ���򵥲�����ѡ��Ч�ʸ� 
{
	
}
Clock::Clock():
	hour(0),minute(0),second(0)//Clock(0,0,0);ί�й��캯�� 
{
		
}
void Clock::showTime()
{
	cout << hour << ':' << minute << ':' << second << endl;
}
int main()
{
	Clock c1(8,10,0);
	c1.showTime();
	Clock c2;
	c2.showTime(); 
}
