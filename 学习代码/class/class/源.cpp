#include <iostream>
using namespace std;
class Student//Ĭ�ϳ�Ա����˽��Ȩ�ޣ����ʹ��structĬ�ϵĳ�Ա���ǹ��е��ˣ�����û���κ�����
{
private://˽�г�Ա:ֻ���ڱ���ĳ�Ա������ʹ��
	int nNumb = 1;
public://���г�Ա:���������ⶼ�ܵ���
	char sName[20];
	float fMath;
	void SetData(int n, char* p, float f)
	{

	}
	void Print()
	{
	cout << this->nNumb << endl;//thisָ�룬����ָ�����еĳ�Ա
	//thisָ����һ��ָ�볣�������Ըı�ָ����������ݵ����ɸı�ָ���ĸ���
	}
};
int main()
{
	Student d1, d2;
	d1.Print();
}