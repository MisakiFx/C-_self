#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
struct SUser
{
	int nNumb;//ѧ��
	char sName[20];//����
	float fMath;//�ɼ�
};
SUser g_user[10000];//�ṹ������������
void Print()//��ӡ����
{
	puts("ѧ��\t����\t\t�ɼ�");
	int i = 0, sum = 0;
	while (g_user[i].nNumb)
	{
		if (g_user[i].nNumb > -1)//��ѧ��Ϊ-1ʱ����ѭ��
		{
			printf("%d\t%s\t\t%0.1f\n", g_user[i].nNumb, g_user[i].sName, g_user[i].fMath);
			sum++;
		}
		i++;
	}
	printf("�ܹ���%d��ѧ��\n\n", sum);
}
void Save()//���溯�����ӵ�һ���ṹ�忪ʼ�ң�ֻҪ��һ�����ݲ�Ϊ0���ʹ洢�������
{
	FILE* pf = fopen("data.lv", "w");//ʹ�����·��
	if (!pf)
	{
		puts("�ļ���ʧ��");
		return;
	}
	int i = 0;
	while (g_user[i].nNumb)
	{
		if (g_user[i].nNumb != -1)
		{
			fwrite(&g_user[i], 1, sizeof(SUser), pf);//��һ������һ��Ҫ��һ��ָ��
		}
		i++;
	}
	fclose(pf);
}
void Add()//���Ӻ���
{
	int i = 0;
	int j = 0;
	while (g_user[i].nNumb)
	{
		i++;//ͨ��ѭ���ҵ���һ���յĽṹ��������±�i
	}
	printf("������ѧ�ţ�");
	scanf_s("%d", &g_user[i].nNumb);
	while (g_user[j].nNumb > 0)
	{
		if (g_user[j].nNumb == g_user[i].nNumb && j != i)
		{
			puts("ѧ���Ѵ��ڣ�����������");
			g_user[i].nNumb = 0;
			return;
		}
		j++;
	}
	printf("������������");
	scanf_s("%s", g_user[i].sName, sizeof(g_user[i].sName));
	printf("������ɼ���");
	scanf_s("%f", &g_user[i].fMath);
	Save();
	Print();
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
		Save();
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
		Save();
	}
}
void SortByNumb()//��ѧ������
{
	int i = 0, n = 0;//n������
	while (g_user[n].nNumb)//ð������
	{
		n++;
	}
	while (i < n)
	{
		int j = 0;
		while (j < n - i -1)
		{
			if(g_user[j].nNumb > g_user[j].nNumb)
			{
				SUser t = g_user[j];
				g_user[j] = g_user[j + 1];
				g_user[j + 1] = t;
			}
			j++;
		}
		i++;
	}
}
void SortByName()//����������
{
	int i = 0, n = 0;//n������
	while (g_user[n].nNumb)//ð������
	{
		n++;
	}
	while (i < n)
	{
		int j = 0;
		while (j < n - i - 1)
		{
			if (strcmp(g_user[j].sName,g_user[j].sName) > 0)
			{
				SUser t = g_user[j];
				g_user[j] = g_user[j + 1];
				g_user[j + 1] = t;
			}
			j++;
		}
		i++;
	}
}
void SortByMath()//���ɼ�����
{
	int i = 0, n = 0;//n������
	while (g_user[n].nNumb)//ð������
	{
		n++;
	}
	while (i < n - 1)
	{
		int j = 0;
		while (j < n - i - 1)
		{
			if (g_user[j].fMath > g_user[j].fMath)
			{
				SUser t = g_user[j];
				g_user[j] = g_user[j + 1];
				g_user[j + 1] = t;
			}
			j++;
		}
		i++;
	}
}
int Display()
{
	puts("1����ѧ������");
	puts("2������������");
	puts("3�����ɼ�����");
	puts("0���������˵�");
	puts("��ѡ��");
	int i = 0;
	scanf("%d", &i);
	switch (i)
	{
	case 0:
		return 0;
	case 1:
		SortByNumb();
		Print();
		break;
	case 2:
		SortByName();
		Print();
		break;
	case 3:
		SortByMath();
		Print();
		break;
	default:
		break;
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
	case 0:
		return 0;
	case 1:
		while (Display())
		{

		}
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
void Load()
{
	FILE* pf = fopen("data.lv","r");
	if (!pf)
	{
		puts("�ļ���ʧ��");
		return;
	}
	int i = 0;
	SUser u;//��ʱ������
	while (fread(&u,1,sizeof(SUser),pf) > 0)
	{
		g_user[i] = u;
		i++;
	}
	fclose(pf);
}
int main()
{
	Load();
	while (Menu())
	{

	}
}