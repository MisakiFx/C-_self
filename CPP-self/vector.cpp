#include <iostream>
#include <vector> 
#include <algorithm>/* �㷨 */
using namespace std;
int main()
{
	//��������Ʒvector���� 
	//��һ�����ٵĶ�̬�����ڴ������
	//��С���Զ�̬��չ����̬����
	//���Բ����ɾ������
	//vector<������> ������(���鳤��) 
	vector<double> vec1;
	vector<string> vec2(5);//��ʼ������ռ� 
	vector<int> vec3(20,998);//��20���ռ䣬ÿ������998
	//*************************************************************************************** 
	//���ú���
	vector<double> vecDouble={3,2,1};
	//�������в�������
	vecDouble.push_back(100.0);//push_back��β����������
	/*��һ�ִ�ӡ��������ͨ�ã�*/ 
	for(int i=0;i<vecDouble.size();i++)//size()��ȡ�����Ĵ�С 
	{
		cout << vecDouble[i] << endl;
	}
	//********************************************************************** 
	/*�ڶ��ִ�ӡ���������ϵ�ͨ�ñ���������ʹ�õ�����*/
	//�����ǻ����÷�
	vector<double>::iterator it;//�õ���������������Ϊ  'it',����������ʵ������һ��ָ�� 
	/*����Ӧ���͵ĵ������������Ŀ�ʼ������������ĩβ*/
	for(it = vecDouble.begin();it!=vecDouble.end(); ++it)//begin()�������Ŀ�ʼ��end()��������ĩβ
	{
		cout << *it << endl;
	}
	//********************************************************************************************* 
	//���� (Ҫ���㷨ͷ�ļ�)
	sort(vecDouble.begin(),vecDouble.end());//��С����˳������ 
	for(it=vecDouble.begin();it!=vecDouble.end();++it)
	{
		cout << *it <<endl;
	}
	reverse(vecDouble.begin(),vecDouble.end());//�ɴ�С�������� 
	for(it=vecDouble.begin();it!=vecDouble.end();++it)
	{
		cout << *it <<endl;
	}
	//***************************************************************************************
	//	
	
	 
}
