#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
/*
����(vector)
1��һ��������չ�Ķ�̬����
2��������ʡ���β�������ɾ��Ԫ�ؿ�
3�����м��ͷ�������ɾ��Ԫ����
4��������ʵ�ʷ���ռ�Ĵ�С
5��s.capacity():���ص�ǰ����
6��s.reserve(n):������С��n�����s������չ��ʱ���������ٴﵽn 
*/
/*
˫�˶��У�deque��
1�������˲����ɾ��Ԫ�ؿ�
2�����м�����ɾ��Ԫ����
3��������ʽϿ죬�������������� 
*/
int main()
{
	istream_iterator<int> i1(cin),i2;//����һ��������������
	vector<int> s1(i1,i2);//ͨ���������������ӱ�׼���������������� 
	sort(s1.begin(), s1.end());//���������������
	deque<int> s2;
	for(vector<int>::iterator iter = s1.begin(); iter != s1.end(); ++iter)
	{
		if(*iter % 2 == 0)
		{
			s2.push_back(*iter);
		}
		else
		{
			s2.push_front(*iter);
		}
		copy(s2.begin(), s2.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	} 
}
