#include <iostream>
#include <math.h>
using namespace std;
//�����Ԫ������� 
class A//��Ԫ�� 
{
	friend class Point;//��Ԫ�����������ҪPoint���ܹ�ʹ��A���˽�г�Ա������A���н�����Ԫ���� 
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
		friend float dist(Point& a, Point& b);//������Ԫ������������������д�����ڡ�����Ϊ��Ԫ����
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
float dist(Point& a, Point& b)//��Ԫ���� 
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
