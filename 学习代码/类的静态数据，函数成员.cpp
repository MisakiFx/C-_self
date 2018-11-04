#include <iostream>
using namespace std;
class Point
{
	public:
		Point(int x = 0, int y = 0):x(x), y(y)//���캯�� 
		{
			count++;	
		}
		Point(const Point & p)//���ƹ��캯�� 
		{
			x = p.x;
			y = p.y;
			count++;
		}
		~Point()//�������� 
		{
			count--;
		}
		void showCount()//��ӡ���� 
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
		static void showCcount()//��̬��Ա����������������ĺ��� 
		{
			cout << "Object count = " << count << endl;
		}
	private:
		int x;
		int y;
		static int count;//��̬���ݳ�Ա���� 
};
int Point::count = 0;// ��̬���ݳ�Ա����ͳ�ʼ����ʹ�������޶� (��̬���ݳ�Ա�����ĳ�ʼ��Ҫ������)
int main()
{
	Point::showCcount(); //ʹ����������������ľ�̬��Ա���� 
	Point a(4,5);//�������a,count++ 
	cout << "Point A:" << a.getX() << "," << a.getY() << endl;
	a.showCount();//��ͨ����Ҳ��Ҳ���þ�̬���� 
	Point b(a);//�������b�����ø��ƹ��캯��
	cout << "Point B:" << b.getX() << "," << b.getY() << endl;
	b.showCount(); 
}
