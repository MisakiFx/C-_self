#include <stdio.h>
#include <string.h> 
char string[] = "A string\tof ,,tokens\nand some more tokens";
char seps[] = " ,\t\n";
char* token;
int main()
{
	printf("Tokens��");
	token = strtok(string,seps);//�ַ����ضϺ�������һ��������Ŀ���ַ������ڶ��������ǽض��ַ�,����ֵ�ǽضϺ���ַ����ĵ�ַ 
	while (token != NULL)
	{
		printf("%s\n",token);
		token = strtok(NULL,seps);//�������Ҫ�����ض��ϴνضϵ��ַ�����ѵ�һ����������ΪNULL���� 
	} 
	
} 
