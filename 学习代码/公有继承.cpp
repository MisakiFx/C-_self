#include <iostream>
using namespace std;
//派生：将原有类进行扩展新增或修改功能形成新类 
//在类外和类内都可以直接调用父类的公有或保护成员，private成员有要使用父类的借口进行访问 
//如果子类中的函数或变量名与父类中的函数或变量名重名，则会自动遮盖父类中的函数和变量，要想调用父类中的变量需要加类名限定 
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
class Rectangle : public Point//派生类 
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
		float getW() const
		{
			return w;
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
