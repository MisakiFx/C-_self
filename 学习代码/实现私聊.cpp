#include <iostream>
using namespace std;
/** ģ����Ϸ��˽�ĵĺ��� */
//�����ַ�����ƴ�� 
//��һ�������������������ƣ��ڶ�����������������
//���ذ�ĳ��ʽƴ��������Ϣ����ַ��� 
string chatTo(const string& toName,const string& content)
{
	string msg = "�������ĵĶ�[" + toName + "]˵��" + content;
	return msg; 
}
string chatFrom(const string& fromName,const string& content)
{
	string msg = "��[" + fromName + "]���ĵĶ���˵��" + content;
	return msg;
}
int main()
{
	cout << "������Է������ƣ�";
	string toName, content;
	getline(cin,toName);
	cout << "�����뷢�͸��Է���������Ϣ��";
	getline(cin, content);
	string chatMsg = chatTo(toName,content);
	cout << chatMsg << endl; 
	string fromContent = "�����������";
	string fromMsg = chatFrom(toName,fromContent);
	cout << fromMsg << endl;
	
}
