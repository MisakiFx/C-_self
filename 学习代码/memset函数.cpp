#include <stdio.h>
#include <memory.h>
int main()
{
	char string[] = "Misaki";
	printf("֮ǰ��%s",string);
	memset(string,'*',6);//�ڴ����ú�������һ���������޸ĵ�Ŀ���ڴ�λ�ã��ڶ����������޸�Ϊʲô�����������޸ļ���,����ֵ��void�� 
	printf("�޸ĺ�%s",string); 
} 
