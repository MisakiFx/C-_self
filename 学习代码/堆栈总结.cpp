#include <stdio.h>
#include <stdlib.h> 
//�ڶѿռ���������� 
typedef struct sStud
{
	int nNumb;
	char sName[20];
	float fMath;
}SStud;
void Test (int* p, int n)
{
	int i = 0;
	while (i < n)
	{
		p[i] = -13 * i + 19;
		i++;
	}
 } 
 
int main()
{
	int n = 10;//��ջ�ڴ洢����
	int i = 0;
	int* p = (int*)malloc(sizeof(int) * 10);//��������ռ䣬4�����οռ䣬16���ֽ�
	int ar[10];//��ջ�ڶ��� 
	*(p + 1) = n;//��ջ������ת�浽���� 
	*(p + 2) = -1;
	Test(p,10);//ͨ�������޸Ķ��ڵ����� 
	Test(ar,10);//ͨ�������޸�ջ�ڵ�����
	SStud st = {1024,"Misaki",5};//��ջ����������� 
	SStud* pt = (SStud*)malloc(sizeof(SStud));//�ڶ������������
	*pt = st;
	char* ss[] = {"abc","scf","adc","159"};//��ջ������4��ָ����������� 
	char** ps = (char**)malloc(sizeof(char*)*4); //�ڶ�������4��ָ����������� 
	while(i < 4)//��ջ�ϵ�����ת�浽���� 
	{
		ps[i] = ss[i];
		i++;
	} 
} 
