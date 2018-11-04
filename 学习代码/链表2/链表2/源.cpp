#include <stdio.h>
#include <stdlib.h>
typedef int DATA;
struct SNode//�ڵ�
{
	DATA data;
	SNode* pNext;//βָ��
};
SNode* g_pHead = NULL;//ͷָ��
void AddHead(DATA data)//��ͷ�����
{
	SNode* p = (SNode*)malloc(sizeof(SNode));
	p->data = data;
	p->pNext = g_pHead;
	g_pHead = p;
}
void AddTail(DATA data)//��β�����
{
	SNode* pf = (SNode*)malloc(sizeof(SNode));
	pf->data = data;
	pf->pNext = NULL;
	SNode* p = g_pHead;
	if (g_pHead == NULL)
	{
		g_pHead = pf;
		return;
	}
	while (p->pNext != NULL)
	{
		p = p->pNext;
	}
	p->pNext = pf;
}
int Delete(DATA data)//ɾ��
{
	SNode* p = g_pHead,*p1 = NULL;//�ҵ�ͷ
	if (p = NULL)//����ǿ�����ֱ��ɾ��ʧ��
	{
		return 0;
	}
	if (p->data == data)//���ɾ������ͷ�ڵ�Ҫ���⴦��
	{
		g_pHead = p->pNext;
		free(p);
		return 1;
	}
	while (p != NULL)//��������
	{
		if (p->data == data)
		{
			p1->pNext = p->pNext;//��ɾ���ڵ��ǰһ���ڵ����һ���ڵ���������
			free(p);//�����ͷ��ڴ治�У�����Ͷ���
			return 1;
		}
		p1 = p;//��p1��¼�ڵ��ǰһ���ڵ�
		p = p->pNext;
	}
	return 0;
}
void Print()//��ӡ
{
	SNode* p = g_pHead;//�ҵ�ͷ
	while (p != NULL)//��������
	{
		printf("%d\t", p->data);
		p = p->pNext;
	}
	printf("\n");
}
void Modfx(DATA data, DATA newData)//�޸�
{
	SNode* p = g_pHead;//�ҵ�ͷ
	while (p != NULL)//��������
	{
		if (p->data == data)
		{
			p->data = newData;
		}
		p = p->pNext;//�ҵ���һ�ڵ�
	}
}
int Find(DATA data)//����
{
	SNode* p = g_pHead;//�ҵ�ͷ
	while (p != NULL)//��������
	{
		if (p->data == data)
		{
			return 1;
		}
		p = p->pNext;
	}
	return 0;
}
int main()
{
	AddHead(3);
	AddHead(2);
	AddHead(1);
	puts("�޸�ǰ");
	Print();
	Modfx(2, 888);//��2�޸�Ϊ888
	puts("�޸ĺ�");
	Print();
	if (Find(56))
	{
		puts("�ҵ���");
	}
	else
	{
		puts("û�ҵ�");
	}
	if (Delete(888) == 0)
	{
		puts("ɾ��ʧ�ܣ�");
	}
	puts("ɾ����");
	Print();
}