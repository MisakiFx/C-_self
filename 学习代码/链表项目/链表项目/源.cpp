#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct SUser//数据区结构体
{
	int nNumb;
	char sName[20];
	float fMath;
};
typedef SUser DATA;
struct SNode//节点
{
	DATA data;//数据区
	SNode* pNext;//地址区
};
SNode* g_pHead = NULL;//头节点
void AddHead(DATA data)//头部插入
{
	SNode* p = (SNode*)malloc(sizeof(SNode));
	p->data = data;
	p->pNext = g_pHead;
	g_pHead = p;
}
void AddTail(DATA data)//尾部插入
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
void Save()//保存函数
{
	FILE* pf = fopen("stud.lv", "w");
	if (pf == NULL)
	{
		puts("打开文件失败");
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
void Print()//打印函数
{
	SNode* p = g_pHead;
	puts("学号\t姓名\t成绩");
	int i = 0;
	while (p != NULL)
	{
		printf("%d\t%s\t%0.1f\n",p->data.nNumb,p->data.sName,p->data.fMath);
		p = p->pNext;
		i++;
	}
	printf("共有%d条记录\n", i);
	system("pause");
}
void Input(int nDirect)//增加函数
{
	DATA data;
	puts("请输入学号");
	scanf_s("%d", &data.nNumb);
	puts("请输入姓名");
	scanf_s("%s", data.sName,sizeof(data.sName));
	puts("请输入成绩");
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
int AddMenu()//增加菜单
{
	system("cls");
	puts("1、头部插入");
	puts("2、尾部插入");
	puts("0、返回主菜单");
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
void SortByNumb()//按学号排序
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
			DATA t = p->data;//利用指针进行交换
			p->data = m->data;
			m->data = t;
		}
		p = p->pNext;
	}
}
void SortByName()//按名字排序
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
			DATA t = p->data;//利用指针进行交换
			p->data = m->data;
			m->data = t;
		}
		p = p->pNext;
	}
}
void PrintS(SNode** ps)
{
	puts("学号\t姓名\t成绩");
	int i = 0;
	while (ps[i] != NULL)
	{
		SNode* p = ps[i];
		printf("%d\t%s\t%0.f\n", p->data.nNumb, p->data.sName, p->data.fMath);
		i++;
	}
	printf("共有%d条记录\n", i);
	system("pause");
}
void SortByMath()//按成绩排序
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
			DATA t = p->data;//利用指针进行交换
			p->data = m->data;
			m->data = t;
		}
		p = p->pNext;
	}
}
void SortByNumb2()//按学号排序函数（链表外排序）
{
	if (g_pHead == NULL || g_pHead->pNext == NULL)
	{
		return;
	}
	SNode* p = g_pHead;
	SNode* ps[100] = { 0 };//定义结构体指针数组
	int n = 0, i = 0;//n用来计算节点总数方便排序，i用来进行排序
	while (p != NULL)//遍历链表
	{
		ps[n] = p;//将链表上的每一个节点的指针都放到结构体指针数组中
		p = p->pNext;
		n++;
	}
	while (i < n - 1)//用选择排序
	{
		int m = i;
		int j = i + 1;//j定义一定要在外循环内定义为i+1，写错的痛苦
		while (j < n)//找到最小数
		{
			if (ps[j]->data.nNumb < ps[m]->data.nNumb)
			{
				m = j;
			}
			j++;
		}
		if (m != i)//在指针数组内部交换，也可以直接用指针操作链表进行交换
		{
			SNode* t = ps[i];
			ps[i] = ps[m];
			ps[m] = t;
		}
		i++;
	}
	PrintS(ps);
}
void SortByMath2()//按成绩排序函数（链表外排序）
{
	if (g_pHead == NULL || g_pHead->pNext == NULL)
	{
		return;
	}
	SNode* p = g_pHead;
	SNode* ps[100] = { 0 };//定义结构体指针数组
	int n = 0, i = 0;//n用来计算节点总数方便排序，i用来进行排序
	while (p != NULL)//遍历链表
	{
		ps[n] = p;//将链表上的每一个节点的指针都放到结构体指针数组中
		p = p->pNext;
		n++;
	}
	while (i < n - 1)//用选择排序
	{
		int m = i;
		int j = i + 1;//j定义一定要在外循环内定义为i+1，写错的痛苦
		while (j < n)
		{
			if (ps[j]->data.fMath < ps[m]->data.fMath)
			{
				m = j;
			}
			j++;
		}
		if (m != i)//在指针数组内部交换，也可以直接用指针操作链表进行交换
		{
			SNode* t = ps[i];
			ps[i] = ps[m];
			ps[m] = t;
		}
		i++;
	}
	PrintS(ps);
}
void SortByName2()//按学号排序函数（链表外排序）
{
	if (g_pHead == NULL || g_pHead->pNext == NULL)
	{
		return;
	}
	SNode* p = g_pHead;
	SNode* ps[100] = { 0 };//定义结构体指针数组
	int n = 0, i = 0;//n用来计算节点总数方便排序，i用来进行排序
	while (p != NULL)//遍历链表
	{
		ps[n] = p;//将链表上的每一个节点的指针都放到结构体指针数组中
		p = p->pNext;
		n++;
	}
	while (i < n - 1)//用选择排序
	{
		int m = i;
		int j = i + 1;//j定义一定要在外循环内定义为i+1，写错的痛苦
		while (j < n)
		{
			if (strcmp(ps[j]->data.sName,ps[m]->data.sName) > 0)
			{
				m = j;
			}
			j++;
		}
		if (m != i)//在指针数组内部交换，也可以直接用指针操作链表进行交换
		{
			SNode* t = ps[i];
			ps[i] = ps[m];
			ps[m] = t;
		}
		i++;
	}
	PrintS(ps);
}
int SortMenu()//排序函数
{
	system("cls");
	puts("1、按学号排序");
	puts("2、按姓名排序");
	puts("3、按分数排序");
	puts("4、按学号排序（链表外）");
	puts("5、按姓名排序（链表外）");
	puts("6、按分数排序（链表外）");
	puts("7、不排序打印");
	puts("0、返回主菜单");
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
	printf("请输入要修改的学号");
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
		puts("你输入的学号不存在");
		return;
	}
	printf("%d\t%s\t%0.1f\n", p->data.nNumb, p->data.sName, p->data.fMath);
	printf("请输入姓名和成绩：");
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
	printf("请输入要删除的学号");
	scanf_s("%d", &nNumb);
	if (g_pHead == NULL)
	{
		printf("数据为空");
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
		puts("你输入的学号不存在");
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
	printf("请输入要查找的学号：");
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
	puts("没找到");
	return;
}
int Menu()//菜单函数
{
	system("cls");
	puts("\n1、浏览所有信息");
	puts("2、添加信息");
	puts("3、删除信息");
	puts("4、修改信息");
	puts("5、查找信息");
	puts("6、颜色设置");
	puts("0、退出");
	printf("请选择：");
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
void Lord()//读取函数
{
	FILE* pf = fopen("stud.lv", "r");
	if (pf == NULL)
	{
		puts("文件打开失败");
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