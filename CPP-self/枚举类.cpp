#include <iostream>
using namespace std;
//ö���ࣺǿ����ö��
//enum class ö��������:�ײ�����(Ĭ��int����) ��ö��ֵ�б��;
/*
1��ǿ������
2��ת������
3������ָ���ײ����� 
*/
enum class Type 
{
	General, 
	Lisght,
	Medium, 
	Heavy
};
enum class Type2:char 
{
	General = 1,
	Light,
	Medium,
	Heavy
}; 
enum class Side
{
	Right,
	Left
};
 enum class Thing
{
	Wrong,
	Right 	
}; 
int main()
{
	Side s = Side::Right;
	Thing w = Thing::Wrong;
	cout << (s == w) << endl;//�޷�ֱ�ӱȽϲ�ͬö����
	return 0; 
}
