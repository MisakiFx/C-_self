#include <iostream>
using namespace std;
class IntNum
{
	public:
		IntNum(int x = 0):xptr(new int(x))//���캯�� 
		{
			cout << "Calling constructor..." << endl;
		}
		IntNum(const IntNum & n):xptr(new int(*n.xptr))//��㸴�ƹ��캯������Ա������ָ��ʱʹ�ã����´����ռ���µĶ��󣬲��ҽ�ֵ��ֵ��ȥ 
		{
			cout << "Calling copy constructor..." << endl;
		}
		IntNum(IntNum && n):xptr(n.xptr)//�ƶ����캯��,ʵ���ǽ�һ���������ָ�븳ֵ���µĶ��󲢽�ԭ���Ķ����ָ���ÿ� 
		{
			n.xptr = nullptr;
			cout << "Calling move constructor..." << endl;
		}
		~IntNum()
		{
			delete xptr;
			cout << "Calling Destructing..." << endl;
		}
		int getInt()
		{
			return *xptr;
		}
	private:
		int *xptr;
};
IntNum getNum()
{
	IntNum a;
	return a;
}
int main()
{
	cout << getNum().getInt() << endl;
} 
