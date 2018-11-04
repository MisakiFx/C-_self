#include <iostream>
using namespace std;
class Point
{
	public:
		Point(int x = 0, int y = 0):x(x), y(y)//构造函数 
		{
			count++;	
		}
		Point(const Point & p)//复制构造函数 
		{
			x = p.x;
			y = p.y;
			count++;
		}
		~Point()//析构函数 
		{
			count--;
		}
		void showCount()//打印函数 
		{
			cout << "Object count = " << count << endl;
		}
		int getX()
		{
			return x;
		}
		int getY()
		{
			return y;
		}
		static void showCcount()//静态成员函数，属于整个类的函数 
		{
			cout << "Object count = " << count << endl;
		}
	private:
		int x;
		int y;
		static int count;//静态数据成员声明 
};
int Point::count = 0;// 静态数据成员定义和初始化，使用类名限定 (静态数据成员变量的初始化要在类外)
int main()
{
	Point::showCcount(); //使用类名调用属于类的静态成员函数 
	Point a(4,5);//定义对象a,count++ 
	cout << "Point A:" << a.getX() << "," << a.getY() << endl;
	a.showCount();//普通对象也可也调用静态函数 
	Point b(a);//定义对象b，调用复制构造函数
	cout << "Point B:" << b.getX() << "," << b.getY() << endl;
	b.showCount(); 
}
