#include <stdio.h>
#include <string.h>
int main()
{
	char string[50];
	char* string1,*string2;
	printf("�������ַ�����");
	scanf("%s",string);
	string1 = strupr(string);//strupr�������ַ���������Сд��ĸת��Ϊ��д��ĸ���������ַ�����ָ�� 
	string2 = strlwr(string);//strlwr�������ַ��������д�д��ĸת��ΪСд��ĸ ���������ַ�����ָ�� 
	printf("%s\n%s",string1,string2); 
} 
