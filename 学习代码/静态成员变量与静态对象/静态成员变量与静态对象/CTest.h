#pragma once
#include <iostream>
using namespace std;
class CTest
{
	friend void Test();//��Ա����������������ڿ��Ե���˽�еĳ�Ա�����ͳ�Ա����
	int m_nTest = 0;
public:
	CTest();
	~CTest();
	static int m_nStatic2;//�������static������ȫ�ֱ������������ڱ���,��ʼ��Ҫ��������г�ʼ��,��ռ������ڴ�ռ�
	void Test(int);
	void Print();
};

