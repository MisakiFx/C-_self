#include <iostream>
using namespace std;
//私有继承会将父类中的所有成员全部变为private类型出现在子类中
//但是在子类中还可以调用父类的public类型的成员
//在类外不可直接调用父类的所有成员
class Point//基类 
{
	public:
		void initPoint(float x = 0, float y = 0)
		{
			this->x = x;
			this->y = y;
		}
		void move(float offX, float offY)
		{
			x += offX;
			y += offY;
		}
		float getX() const
		{
			return x;
		}
		float getY() const
		{
			return y;
		}
	private:
		float x, y;
}; 
class Rectangle : private Point//派生类 
{
	public:
		void initRectangle(float x, float y, float w, float h)
		{
			initPoint(x,y);//调用基类公有成员函数
			this->w = w;
			this->h = h;
		}
		float getH() const
		{
			return h;
		}
		float getX() const
		{
			return Point::getX();
		}
		float getY() const
		{
			return Point::getY();
		}
		float getW() const
		{
			return w;
		}
		void move(float offX, float offY)
		{
			Point::move(offX, offY);
		}
	private://新增私有成员函数 
		float w, h;
};
int main()
{
	Rectangle rect;
	rect.initRectangle(2, 3, 20, 10);
	rect.move(3, 2);//Point里的move函数 
	cout << "The data of rect(x,y,w,h):" << endl;
	cout << rect.getX() << ","
		 << rect.getY() << ","
		 << rect.getW() << ","
		 << rect.getH() << endl;
}
