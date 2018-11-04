#include <iostream>
using namespace std;
class Point
{
	public:
		Point(int xx, int yy);//构造函数 
		~Point();//析构函数，会自动生成 
	private:
		int x, y;
 };
Point::Point(int xx, int yy)//构造函数 
{
 	x = xx;
 	y = yy;
}
Point::~Point()//析构函数 
{
	
} 
int main()
{
	
}
