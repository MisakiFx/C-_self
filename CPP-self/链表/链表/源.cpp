#include <stdio.h>
#include <stdlib.h>
//#define DATA int//�궨��
//��������������һ�����ṹ�壨�ڵ㣩��ɣ�һ���ڵ��β����ָ����һ���ڵ��ָ��
typedef int DATA;//���Ͷ���
struct SNode//�ڵ�ṹ�壺1����������2����ַ��
{
	DATA data;//��ȷ���������ͣ���������
	SNode* pNext;//β���ĸ��ֽڣ���ַ����
};
SNode* g_pHead = NULL;//ͷָ��
void AddHead(DATA data)//��ͷ������
{
	SNode* p = (SNode*)malloc(sizeof(SNode));//�ڶ��ڴ�������һ���½ڵ���ڴ�ռ�
	p->data = data;//�Ѵ�������ݷŵ��µĽڵ���
	p->pNext = g_pHead;//��βָ��ָ��ͷ
	g_pHead = p;//ͷָ������µ��ڴ�ռ��ָ�룬�������ͷ������
}
void AddTail(DATA data)//��β������
{
	SNode* pNew = (SNode*)malloc(sizeof(SNode));//�����½ڵ�
	pNew->data = data;//��ֵ
	pNew->pNext = NULL;//���½ڵ�β��Ϊ0
	if (g_pHead == NULL)//����ǿ�������������
	{
		g_pHead = pNew;//�����²���Ľڵ㵱ͷ�ڵ�
		return;
	}
	SNode* p = g_pHead;//����ʱ����ָ��ͷָ��
	while (p->pNext)//ͨ��ѭ������ʱָ��ָ�����һ���ڵ�
	{
		p = p->pNext;//��ʱָ��ָ�����һ���ڵ�
	}
	p->pNext = pNew;//��ԭ�������һ���ڵ��β�͵����½ڵ��ָ��
}
void Print()//��ӡ����
{
	SNode* p = g_pHead;//��������ʱ������p��������ѭ����ӡ��ͷ����������δ�ӡ
	while (p != NULL)//ֻҪͷָ�벻Ϊ�գ����нṹ����ڣ�
	{
		printf("%d\t", p->data);
		p = p->pNext;//��ӡ��һ��ͷָ�����Ϊ����ڵ����βָ�루����һ���ڵ��ͷָ�룩
	}
	
}
int main()
{
	AddHead(3);
	AddHead(2);
	AddHead(1);
	printf("��һ�δ�ӡ:");
	Print();
	AddTail(67);
	AddTail(98);
	printf("\n");
	printf("�ڶ��δ�ӡ:");
	Print();
}