#include "CTest.h"
int m_nStatic = 0;//ȫ�ֱ���ȫ��ֻ��һ�ݣ�ÿ�����󶼹���ͬһ�ݱ������ڴ�ռ�
int CTest::m_nStatic2 = 0;//���������ȫ�ֱ����ĳ�ʼ��
CTest::CTest()
{
}


CTest::~CTest()
{
}


void CTest::Test(int n)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	m_nTest += n;
	m_nStatic += n;
}


void CTest::Print()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	cout << m_nTest << endl;
	cout << m_nStatic << endl;
	return;
}
