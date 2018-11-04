#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>
#include <string>
using namespace std;
/*
�б�list�� 
1��������λ�ò����ɾ��Ԫ�ض��ܿ�
2����֧���������
3�����(splice)������s1.splice(p,s2,q1,q2):��s2��[q1,q2)�ƶ���s1��p��ָ��Ԫ��֮ǰ 
*/
int main()
{
	string names1[] = {"Alice", "Helen", "Lucy", "Susan"};
	string names2[]	= {"Bob", "David", "Levin", "Mike"};
	//��names1��������ݹ����б�s1
	list<string> s1(names1.begin(), names1.end());
	//��names2�����ڵ��ݹ����б�s2
	list<string> s2(names2, names2 + 4);
	//��s1�ĵ�һ��Ԫ�طŵ�s2�����
	s2.splice(s2.end(), s1, s1.begin()); 
	list<string>::iterator iter1 = s1.begin();//iter1ָ��s1����
	advance(iter1, 2);//iter1ǰ������Ԫ�أ�ָ��s1�ĵ�����Ԫ��
	list<string>::iterator iter2 = s2.begin();//iter2ָ��s2����
	++iter2;//iter2ǰ��һ��Ԫ�أ�ָ��s2�ڶ���Ԫ��
	list<string>::iterator iter3 = iter2;//��iter2��ʼ��iter3
	advance(iter3, 2);//��iter3ǰ������Ԫ�أ�ָ��s2�ĵ�4��Ԫ��
	//��[iter2,iter3)��Χ�ڵĽڵ�ӵ�s1��iter1ָ��Ľڵ�ǰ
	s1.splice(iter1, s2, iter2, iter3);
	//�ֱ�s1��s2���
	copy(s1.begin(), s1.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	copy(s2.begin(), s2.end(), ostream_iterator<string>(cout, " "));
	cout << endl; 
	 
}
