#include <stdio.h>
struct SUser
{
	int nNumb;//ѧ��
	char sName[20];//����
	float fMath;//�ɼ�
};
SUser g_user[10000];
void Add()//���Ӻ���
{
	int i = 0;
	while (g_user[i].nNumb)
	{
		i++;//ͨ��ѭ���ҵ���һ���յĽṹ��������±�i
	}
	printf("������ѧ�ţ�");
	scanf_s("%d", &g_user[i].nNumb);
	printf("������������");
	scanf_s("%s", g_user[i].sName, sizeof(g_user[i].sName));
	printf("������ɼ���");
	scanf_s("%f", &g_user[i].fMath);
}
void Print()//��ӡ����
{
	puts("ѧ��\t����\t\t�ɼ�");
	int i = 0,sum = 0;
	while (g_user[i].nNumb)
	{
		if (g_user[i].nNumb > -1)//��ѧ��Ϊ-1ʱ����ѭ��
		{
			printf("%d\t%s\t\t%0.1f\n", g_user[i].nNumb, g_user[i].sName, g_user[i].fMath);
			sum++;
		}
		i++;
	}
	printf("�ܹ���%d��ѧ��\n\n",sum);
}
void Delete()//ɾ������
{
	Print();
	printf("������Ҫɾ����ѧ�ţ�");
	int nNumb;
	scanf_s("%d", &nNumb);
	int i = 0;
	while (g_user[i].nNumb)
	{
		if (g_user[i].nNumb == nNumb)
		{
			g_user[i].nNumb = -1;//����-1����Ϊwhile(-1)��ʾ��������ѭ����while(0)��ʾ��ֹѭ��
			break;
		}
		i++;
	}
	if (g_user[i].nNumb == 0)
	{
		puts("ѧ�Ų�����");
	}
	else
	{
		Print();
	}
}
void Modify()//�޸ĺ���
{
	Print();
	printf("������Ҫ�޸ĵ�ѧ�ţ�");
	int nNumb;
	scanf_s("%d", &nNumb);
	int i = 0;
	while (g_user[i].nNumb)
	{
		if (g_user[i].nNumb == nNumb)
		{
			printf("������ѧ�ţ�");
			scanf_s("%d", &g_user[i].nNumb);
			printf("������������");
			scanf_s("%s", g_user[i].sName, sizeof(g_user[i].sName));
			printf("������ɼ���");
			scanf_s("%f", &g_user[i].fMath);
			break;
		}
		i++;
	}
	if (g_user[i].nNumb == 0)
	{
		puts("ѧ�Ų�����");
	}
	else
	{
		Print();
	}
}
int Menu()//���˵�
{
	puts("1�����������Ϣ");
	puts("2�������Ϣ");
	puts("3��ɾ����Ϣ");
	puts("4���޸���Ϣ");
	puts("5��������Ϣ");
	puts("0���˳�");
	puts("��ѡ��");
	int i = 0;
	scanf_s("%d", &i);
	switch (i)
	{
	case 1:
		Print();
		break;
	case 2:
		Add();
		break;
	case 3:
		Delete();
		break;
	case 4:
		Modify();
		break;
	default:
		puts("��������ȷ��ѡ��");
		break;
	}
	return i;
}
int main()
{
	while (Menu())
	{
		
	}
}