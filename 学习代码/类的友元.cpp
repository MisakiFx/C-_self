#include <iostream>
#include <math.h>
using namespace std;
//类的友元：单向的 
class A//友元类 
{
	friend class Point;//友元类的声明，想要Point类能够使用A里的私有成员必须在A类中进行友元声明 
	public:
	private:
		int a = 0, b = 0;
};
class Point
{
	public:
		Point(int x = 0, int y = 0):x(x),y(y)
		{
			
		}
		int getX()
		{
			return x;
		}
		int getY()
		{
			return y;
		}
		friend float dist(Point& a, Point& b);//声明友元函数，将函数的声明写在类内。声明为友元函数
		void set();
		void get()
		{
			cout << b.a << endl;
		}
	private:
		int x, y;
		A b;
};
void Point::set()
{
	b.a = 5;
}
float dist(Point& a, Point& b)//友元函数 
{
	double x = a.x - b.x;
	double y = a.y - b.y;
	return static_cast<float>(sqrt(x * x + y * y));
}
int main()
{
	Point p1(1,1),p2(4,5);
	cout << "The distance is:" << dist(p1,p2) << endl;
	p1.set();
	p1.get();
} 
