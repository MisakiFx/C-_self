#include <iostream>
//�����ռ䣺Ϊ�˷�ֹ��ͬ�ļ��к���������ͬ���֣�ʹ�ò�ͬ�������ռ���������
using namespace std;//ʹ�ñ�׼�������������ռ�
namespace M
{
	bool IsDierectory()
	{
		return true
	}
	bool IsHiden()
	{
		return false;
	}
}
namespace ZHANG
{
	bool IsDierectory();
	{
		return true;
	}
	bool IsHiden()
	{
		return false;
	}
}
bool IsDierectory()//ȫ�ֺ���
{
	return true;
}
//using namespace M;//Ĭ��ʹ��M�������ռ�
int main()
{
	double i = 20;
	bool b = M::IsDierectory();//����M�����ռ��ڵĺ���
	bool a = ZHANG::IsDierectory();//����ZHANG�����ռ��ڵĺ���
	bool c = ::IsDierectory();//����using namespace ��Ĭ�ϵ���M�ڵ������ռ�
	std::cout << "sizeof(i) = " << sizeof(i) << std::endl;
}
