#include <stdio.h>
enum ETest//���������Ķ���,��ö�ٶ��壬�Զ��������ɲ��ظ��ĳ��� 
{
	READ_ONLY = 1,
	HIDE,
	SYSTEM,
}; 
int main()
{
	int i = HIDE;
	int j = SYSTEM;
	printf("i = %d\n",HIDE);
	printf("j = %d\n",SYSTEM);
	ETest t = HIDE;//ʹ��ö�ٶ���һ������������ֵֻ����ö�������е�һ����������ʱҲһ����ֻ����ö�����ݵ�һ��
} 
