#include <iostream>
using namespace std;
//˽�м̳лὫ�����е����г�Աȫ����Ϊprivate���ͳ�����������
//�����������л����Ե��ø����public���͵ĳ�Ա
//�����ⲻ��ֱ�ӵ��ø�������г�Ա
class Point//���� 
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
class Rectangle : private Point//������ 
{
	public:
		void initRectangle(float x, float y, float w, float h)
		{
			initPoint(x,y);//���û��๫�г�Ա����
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
	private://����˽�г�Ա���� 
		float w, h;
};
int main()
{
	Rectangle rect;
	rect.initRectangle(2, 3, 20, 10);
	rect.move(3, 2);//Point���move���� 
	cout << "The data of rect(x,y,w,h):" << endl;
	cout << rect.getX() << ","
		 << rect.getY() << ","
		 << rect.getW() << ","
		 << rect.getH() << endl;
}
