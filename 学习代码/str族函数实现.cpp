#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Strcmp(const char* s1, const char* s2)//�ַ�ָ����ǳ���ָ�� 
{
	unsigned char* p1 = (unsigned char*)s1;
	unsigned char* p2 = (unsigned char*)s2;//��unsigned char*���¶��������ַ�����ָ�룬�����Ϳ����ú��ִ�����ĸ 
	while(*p1 && *p2 && *p1 == *p2)//��*s1!=*s2������������һ�����ֿ��ַ�ʱ����ѭ�� 
	{
		p1++;
		p2++;
	}
	int n = *p1 - *p2;////�ó��ֵĵ�һ������ͬ���ַ��õ�һ�������ڶ����ж��ַ�����С ,'c' - 'b' = 1;
	if(n > 0)
	{
		printf("ǰ���");
	}
	else if (n < 0)
	{
		printf("�����");
	}
	else
	{
		printf("һ����");
	}
}
char* Strcpy(char* pDest,const char* pSrc)
{
	char* p = pDest;
	while (*p++ = *pSrc)//���ڶ����ַ����������һ��һ������һ���ַ��� 
	{
		
	}
	return pDest;
}
char Strcat(char* pDest, const char* pSrc)
{
	char*p = pDest;
	while(*p)//�ҵ���ƴ�Ӻ���������β 
	{
		p++;
	}

}
int main()
{
	//���Ը�����ֵ�����ƶ����ַ�����Ҫ��mallocһ��һ����ֵ����������
	Strcmp("abc","abb");
	
}
