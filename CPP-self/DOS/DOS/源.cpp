#include <stdio.h>
#include <cstdlib>
int main()
{
	char a[10];
	printf("Misaki");
	scanf_s("%s",a,_countof(a));
	//��΢��c�������˰�ȫSDL��飬���scanf����ʹ��
	//Ҫ����Ҫʹ����Ҫȡ����ȫSDL��飬���аٶȻ�������define _CRT_SECURE_NO_WARNINGS
	//scanf_sҲ�������������ַ����ַ�����ʱ�����ʹ��sizeof����_count()�������ַ�������
	//�൱��������һ������������һ����ȫ����,��ֹ����Խ�磬һ������Ҫ��Ĵ�С��ȡ���ַ����ĸ�ֵ
	//һ���м丳ֵ�������⣬��ô�������и�ֵ����ȡ��
}