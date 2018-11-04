#include <iostream>
using namespace std;
//��Ŀ���������
//ǰ�õ�Ŀ�����U op, U����Ϊop������ĳ�Ա����,���βΣ�U op = op.operator U () 
//���õ�Ŀ�����op U,��ǰ��Ψһ���������ò���������������������أ��Ժ�ǰ��������������֣��������һ��int���β�0
class Clock
{
	public:
		Clock(int hour = 0, int minute = 0, int second = 0);
		void showTime() const;
		//ǰ�õ�Ŀ���������(�������õ�ԭ����ǰ�����������������������ʹ������Ҫ����һ����ֵ����ʹ��)
		Clock & operator ++ ();
		//���õ�Ŀ��������� 
		Clock operator ++ (int);
	private:
		int hour, minute, second;
}; 
Clock::Clock(int hour, int minute, int second)
{
	if(0 <= hour && hour < 24 && 0 <= minute && minute < 60 && 0 <= second && second < 60)
	{
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}
	else
	{
		cout << "error!" << endl;
	}
}
void Clock::showTime() const//��ʾʱ�� 
{
	cout << hour << ":" << minute << ":" << second << endl;
}
Clock & Clock::operator ++ ()//ǰ��++���㷨ʦ�����Լ���������ã�ֱ�ӽ����ò�������������� 
{
	second++;
	if(second >= 60)
	{
		second -= 60; 
		minute++;
		if(minute >= 60)
		{
			minute -= 60;
		hour = (hour + 1) % 24;
		}
	}
	return *this; 
}
Clock Clock::operator ++ (int)//����++�Ƿ���һ����������������������������� 
{
	Clock old = *this;
	++(*this);//����ǰ��++ 
	return old;
} 
int main()
{
	Clock myClock(23, 59, 59);
	cout << "First time output:";
	myClock.showTime();
	cout << "Show myClock++:";
	(myClock++).showTime();
	cout << "Show ++myClock:";
	(++myClock).showTime();
}
