#include <iostream>
#include <map>
#include <utility>
#include <string> 
using namespace std;
//ӳ�� 
int main()
{
	map<string, int> courses;
	//���γ���Ϣ����coutrsesӳ����
	courses.insert(make_pair("CSAPP", 3));
	courses.insert(make_pair("C++", 2));
	courses.insert(make_pair("CSARCH", 4));
	courses.insert(make_pair("COMPILER", 4));
	courses.insert(make_pair("OS", 5));
	int n = 3;//���µĿ�ѡ����
	int sum = 0;//ѧ���ܺ�
	while(n > 0)
	{
		string name;
		cin >> name;//����γ�����
		map<string, int>::iterator iter = courses.find(name);//���ҿγ�
		if(iter == courses.end())
		{
			cout << name << " is not available" << endl; 
		}
		else
		{
			sum += iter->second;//�ۼ�ѧ�� 
			courses.erase(iter);//����ѡ���Ŀγ̴�ӳ����ɾ��
			n--; 
		} 
	 }
	 cout << "TOtal credit:" << sum << endl;//�����ѧ�� 
}
