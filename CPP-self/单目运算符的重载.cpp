#include <iostream>
using namespace std;
//单目运算符重载
//前置单目运算符U op, U重载为op所属类的成员函数,无形参，U op = op.operator U () 
//后置单目运算符op U,与前置唯一的区别是用参数表来进行运算符的重载，以和前置运算符进行区分，参数表多一个int型形参0
class Clock
{
	public:
		Clock(int hour = 0, int minute = 0, int second = 0);
		void showTime() const;
		//前置单目运算符重载(返回引用的原因是前置运算符都是先运算再拿来使用所以要返回一个左值方便使用)
		Clock & operator ++ ();
		//后置单目运算符重载 
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
void Clock::showTime() const//显示时间 
{
	cout << hour << ":" << minute << ":" << second << endl;
}
Clock & Clock::operator ++ ()//前置++的算法师返回自己对象的引用，直接将引用参与接下来的运算 
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
Clock Clock::operator ++ (int)//后置++是返回一个副本，对象本身布参与接下来的运算 
{
	Clock old = *this;
	++(*this);//调用前置++ 
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
