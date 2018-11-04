#include <iostream>
using namespace std;
class Clock
{
	public:
		Clock(int newH, int newM, int newS);//构造函数
		Clock();//默认构造函数
		Clock(const Clock& p) = delete;//复制构造函数，一般情况下编译器会自动生成，这种写法是不生成默认的复制构造函数 
		//在一切对象需要进行复制的时候都会自动调用复制构造函数
		//自动生成的默认构造函数会将两个对象的各个元素进行一一复制 
		void setTime(int newH, int newM, int newS);
		void showTime(); 
	private: 
		int hour, minute, second;
}; 
Clock::Clock(int newH, int newM, int newS):
	hour(newH),minute(newM),second(newS)//初始化列表，初始化简单参数首选，效率高 
{
	
}
Clock::Clock():
	hour(0),minute(0),second(0)//Clock(0,0,0);委托构造函数 
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
