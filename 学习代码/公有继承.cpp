#include <iostream>
using namespace std;
//��������ԭ���������չ�������޸Ĺ����γ����� 
//����������ڶ�����ֱ�ӵ��ø���Ĺ��л򱣻���Ա��private��Ա��Ҫʹ�ø���Ľ�ڽ��з��� 
//��������еĺ�����������븸���еĺ��������������������Զ��ڸǸ����еĺ����ͱ�����Ҫ����ø����еı�����Ҫ�������޶� 
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
class Rectangle : public Point//������ 
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
		float getW() const
		{
			return w;
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
