#include <iostream>
using namespace std;
inline int S(int);//�������������������ڶ���ʱ��inline,�����ͳ��溯��һ�� 
int main()
{
	/*���溯��ͨ������ָ���ҵ���������ִ��
	��������ͨ������������滻����ִ�У�Ч�ʸ��ߣ�,�����ڴ���ִ��ʱ��̵������ 
	*/ 
	int result = S(5);
	cout << result << endl; 
} 
int S(int num)
{
	return num * num;
}
