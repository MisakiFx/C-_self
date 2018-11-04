#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct SUser//�������ṹ��
{
	int nNumb;
	char sName[20];
	float fMath;
};
typedef SUser DATA;
struct SNode//�ڵ�
{
	DATA data;//������
	SNode* pNext;//��ַ��
};
SNode* g_pHead = NULL;//ͷ�ڵ�
void AddHead(DATA data)//ͷ������
{
	SNode* p = (SNode*)malloc(sizeof(SNode));
	p->data = data;
	p->pNext = g_pHead;
	g_pHead = p;
}
void AddTail(DATA data)//β������
{
	SNode* p = (SNode*)malloc(sizeof(SNode));
	p->data = data;
	p->pNext = NULL;
	SNode* p1 = g_pHead;
	if (g_pHead == NULL)
	{
		g_pHead = p;
		return;
	}
	while (p1->pNext != NULL)
	{
		p1 = p1->pNext;
	}
	p1->pNext = p;
}
void Save()//���溯��
{
	FILE* pf = fopen("stud.lv", "w");
	if (pf == NULL)
	{
		puts("���ļ�ʧ��");
		return;
	}
	SNode* p = g_pHead;
	while (p != NULL)
	{
		fwrite(p, 1, sizeof(p->data), pf);
		p = p->pNext;
	}
	fclose(pf);
}
void Print()//��ӡ����
{
	SNode* p = g_pHead;
	puts("ѧ��\t����\t�ɼ�");
	int i = 0;
	while (p != NULL)
	{
		printf("%d\t%s\t%0.1f\n",p->data.nNumb,p->data.sName,p->data.fMath);
		p = p->pNext;
		i++;
	}
	printf("����%d����¼\n", i);
	system("pause");
}
void Input(int nDirect)//���Ӻ���
{
	DATA data;
	puts("������ѧ��");
	scanf_s("%d", &data.nNumb);
	puts("����������");
	scanf_s("%s", data.sName,sizeof(data.sName));
	puts("������ɼ�");
	scanf_s("%f", &data.fMath);
	if (nDirect == 1)
	{
		AddHead(data);
	}
	else
	{
		AddTail(data);
	}
	Save();
	Print();
}
int AddMenu()//���Ӳ˵�
{
	system("cls");
	puts("1��ͷ������");
	puts("2��β������");
	puts("0���������˵�");
	int i = 0;
	scanf_s("%d", &i);
	switch (i)
	{
	case 1:
		Input(1);
		break;
	case 2:
		Input(2);
		break;
	default:
		break;
	}
	return i;
 }
void SortByNumb()//��ѧ������
{
	SNode* p = g_pHead;
	while (p != NULL)
	{
		SNode* q = p->pNext;
		SNode* m = p;
		while (q != NULL)
		{
			if (q->data.nNumb < m->data.nNumb)
			{
				m = q;
			}
			q = q->pNext;
		}
		if (m != p)
		{
			DATA t = p->data;//����ָ����н���
			p->data = m->data;
			m->data = t;
		}
		p = p->pNext;
	}
}
void SortByName()//����������
{
	SNode* p = g_pHead;
	while (p != NULL)
	{
		SNode* q = p->pNext;
		SNode* m = p;
		while (q != NULL)
		{
			if (strcmp(q->data.sName, m->data.sName) > 0)
			{
				m = q;
			}
			q = q->pNext;
		}
		if (m != p)
		{
			DATA t = p->data;//����ָ����н���
			p->data = m->data;
			m->data = t;
		}
		p = p->pNext;
	}
}
void PrintS(SNode** ps)
{
	puts("ѧ��\t����\t�ɼ�");
	int i = 0;
	while (ps[i] != NULL)
	{
		SNode* p = ps[i];
		printf("%d\t%s\t%0.f\n", p->data.nNumb, p->data.sName, p->data.fMath);
		i++;
	}
	printf("����%d����¼\n", i);
	system("pause");
}
void SortByMath()//���ɼ�����
{
	SNode* p = g_pHead;
	while (p != NULL)
	{
		SNode* q = p->pNext;
		SNode* m = p;
		while (q != NULL)
		{
			if (q->data.fMath > m->data.fMath)
			{
				m = q;
			}
			q = q->pNext;
		}
		if (m != p)
		{
			DATA t = p->data;//����ָ����н���
			p->data = m->data;
			m->data = t;
		}
		p = p->pNext;
	}
}
void SortByNumb2()//��ѧ��������������������
{
	if (g_pHead == NULL || g_pHead->pNext == NULL)
	{
		return;
	}
	SNode* p = g_pHead;
	SNode* ps[100] = { 0 };//����ṹ��ָ������
	int n = 0, i = 0;//n��������ڵ�������������i������������
	while (p != NULL)//��������
	{
		ps[n] = p;//�������ϵ�ÿһ���ڵ��ָ�붼�ŵ��ṹ��ָ��������
		p = p->pNext;
		n++;
	}
	while (i < n - 1)//��ѡ������
	{
		int m = i;
		int j = i + 1;//j����һ��Ҫ����ѭ���ڶ���Ϊi+1��д���ʹ��
		while (j < n)//�ҵ���С��
		{
			if (ps[j]->data.nNumb < ps[m]->data.nNumb)
			{
				m = j;
			}
			j++;
		}
		if (m != i)//��ָ�������ڲ�������Ҳ����ֱ����ָ�����������н���
		{
			SNode* t = ps[i];
			ps[i] = ps[m];
			ps[m] = t;
		}
		i++;
	}
	PrintS(ps);
}
void SortByMath2()//���ɼ�������������������
{
	if (g_pHead == NULL || g_pHead->pNext == NULL)
	{
		return;
	}
	SNode* p = g_pHead;
	SNode* ps[100] = { 0 };//����ṹ��ָ������
	int n = 0, i = 0;//n��������ڵ�������������i������������
	while (p != NULL)//��������
	{
		ps[n] = p;//�������ϵ�ÿһ���ڵ��ָ�붼�ŵ��ṹ��ָ��������
		p = p->pNext;
		n++;
	}
	while (i < n - 1)//��ѡ������
	{
		int m = i;
		int j = i + 1;//j����һ��Ҫ����ѭ���ڶ���Ϊi+1��д���ʹ��
		while (j < n)
		{
			if (ps[j]->data.fMath < ps[m]->data.fMath)
			{
				m = j;
			}
			j++;
		}
		if (m != i)//��ָ�������ڲ�������Ҳ����ֱ����ָ�����������н���
		{
			SNode* t = ps[i];
			ps[i] = ps[m];
			ps[m] = t;
		}
		i++;
	}
	PrintS(ps);
}
void SortByName2()//��ѧ��������������������
{
	if (g_pHead == NULL || g_pHead->pNext == NULL)
	{
		return;
	}
	SNode* p = g_pHead;
	SNode* ps[100] = { 0 };//����ṹ��ָ������
	int n = 0, i = 0;//n��������ڵ�������������i������������
	while (p != NULL)//��������
	{
		ps[n] = p;//�������ϵ�ÿһ���ڵ��ָ�붼�ŵ��ṹ��ָ��������
		p = p->pNext;
		n++;
	}
	while (i < n - 1)//��ѡ������
	{
		int m = i;
		int j = i + 1;//j����һ��Ҫ����ѭ���ڶ���Ϊi+1��д���ʹ��
		while (j < n)
		{
			if (strcmp(ps[j]->data.sName,ps[m]->data.sName) > 0)
			{
				m = j;
			}
			j++;
		}
		if (m != i)//��ָ�������ڲ�������Ҳ����ֱ����ָ�����������н���
		{
			SNode* t = ps[i];
			ps[i] = ps[m];
			ps[m] = t;
		}
		i++;
	}
	PrintS(ps);
}
int SortMenu()//������
{
	system("cls");
	puts("1����ѧ������");
	puts("2������������");
	puts("3������������");
	puts("4����ѧ�����������⣩");
	puts("5�����������������⣩");
	puts("6�����������������⣩");
	puts("7���������ӡ");
	puts("0���������˵�");
	int i = 0;
	scanf_s("%d", &i);
	switch (i)
	{
	case 1:
		SortByNumb();
		break;
	case 2:
		SortByName();
		break;
	case 3:
		SortByMath();
		break;
	case 4:
		SortByNumb2();
		return i;
		break;
	case 5:
		SortByName2();
		return i;
		break;
	case 6:
		SortByMath2();
		return i;
		break;
	case 7:
		Print();
	default:
		return i;
	}
	Print();
	return i;
}
void Modify()
{
	Print();
	int nNumb;
	printf("������Ҫ�޸ĵ�ѧ��");
	scanf_s("%d", &nNumb);
	SNode* p = g_pHead;
	while (p != NULL)
	{
		if (p->data.nNumb == nNumb)
		{
			break;
		}
		p = p->pNext;
	}
	if (p == NULL)
	{
		puts("�������ѧ�Ų�����");
		return;
	}
	printf("%d\t%s\t%0.1f\n", p->data.nNumb, p->data.sName, p->data.fMath);
	printf("�����������ͳɼ���");
	scanf_s("%s", p->data.sName, sizeof(p->data.sName));
	scanf_s("%f", &p->data.fMath);
	Save();
	Print();
}
void Delete()
{
	Print();
	int nNumb;
	SNode* p = g_pHead, *p1 = NULL;
	printf("������Ҫɾ����ѧ��");
	scanf_s("%d", &nNumb);
	if (g_pHead == NULL)
	{
		printf("����Ϊ��");
		return;
	}
	if (p->data.nNumb == nNumb)
	{
		g_pHead = p->pNext;
		free(p);
		Save();
		Print();
		return;
	}
	while (p != NULL)
	{
		if (p->data.nNumb == nNumb)
		{
			break;
		}
		p1 = p;
		p = p->pNext;
	}
	if (p == NULL)
	{
		puts("�������ѧ�Ų�����");
		return;
	}
	p1->pNext = p->pNext;
	free(p);
	Save();
	Print();
}
void Serch()
{
	int nNumb;
	printf("������Ҫ���ҵ�ѧ�ţ�");
	scanf_s("%d", &nNumb);
	SNode* p = g_pHead;
	while (p != NULL)
	{
		if (p->data.nNumb == nNumb)
		{
			printf("%d\t%s\t%f\n", p->data.nNumb, p->data.sName, p->data.fMath);
			return;
		}
		p = p->pNext;
	}
	puts("û�ҵ�");
	return;
}
int Menu()//�˵�����
{
	system("cls");
	puts("\n1�����������Ϣ");
	puts("2�������Ϣ");
	puts("3��ɾ����Ϣ");
	puts("4���޸���Ϣ");
	puts("5��������Ϣ");
	puts("6����ɫ����");
	puts("0���˳�");
	printf("��ѡ��");
	int i = 0;
	scanf_s("%d",&i);
	switch (i)
	{
	case 1:
		while (SortMenu())
		{

		}
		break;
	case 2:
		while (AddMenu())
		{

		}
		break;
	case 3:
		Delete();
		break;
	case 4:
		Modify();
		break;
	case 5:
		Serch();
		break;
	default:
		break;
	}
	return i;
}
void Lord()//��ȡ����
{
	FILE* pf = fopen("stud.lv", "r");
	if (pf == NULL)
	{
		puts("�ļ���ʧ��");
		return;
	}
	DATA data;
	while (fread(&data, 1, sizeof(data), pf) > 0)
	{
		AddTail(data);
	}
	fclose(pf);
}
int main()
{
	Lord();
	while (Menu())
	{

	}
}