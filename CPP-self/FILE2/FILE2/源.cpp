#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
struct SUser
{
	int nNumb;//学号
	char sName[20];//姓名
	float fMath;//成绩
};
SUser g_user[10000];//结构体数组存放数据
void Print()//打印函数
{
	puts("学号\t姓名\t\t成绩");
	int i = 0, sum = 0;
	while (g_user[i].nNumb)
	{
		if (g_user[i].nNumb > -1)//当学号为-1时跳过循环
		{
			printf("%d\t%s\t\t%0.1f\n", g_user[i].nNumb, g_user[i].sName, g_user[i].fMath);
			sum++;
		}
		i++;
	}
	printf("总共有%d个学生\n\n", sum);
}
void Save()//保存函数，从第一个结构体开始找，只要有一个数据不为0，就存储这个数据
{
	FILE* pf = fopen("data.lv", "w");//使用相对路径
	if (!pf)
	{
		puts("文件打开失败");
		return;
	}
	int i = 0;
	while (g_user[i].nNumb)
	{
		if (g_user[i].nNumb != -1)
		{
			fwrite(&g_user[i], 1, sizeof(SUser), pf);//第一个参数一定要是一个指针
		}
		i++;
	}
	fclose(pf);
}
void Add()//增加函数
{
	int i = 0;
	int j = 0;
	while (g_user[i].nNumb)
	{
		i++;//通过循环找到第一个空的结构体数组的下标i
	}
	printf("请输入学号：");
	scanf_s("%d", &g_user[i].nNumb);
	while (g_user[j].nNumb > 0)
	{
		if (g_user[j].nNumb == g_user[i].nNumb && j != i)
		{
			puts("学号已存在，请重新输入");
			g_user[i].nNumb = 0;
			return;
		}
		j++;
	}
	printf("请输入姓名：");
	scanf_s("%s", g_user[i].sName, sizeof(g_user[i].sName));
	printf("请输入成绩：");
	scanf_s("%f", &g_user[i].fMath);
	Save();
	Print();
}
void Delete()//删除函数
{
	Print();
	printf("请输入要删除的学号：");
	int nNumb;
	scanf_s("%d", &nNumb);
	int i = 0;
	while (g_user[i].nNumb)
	{
		if (g_user[i].nNumb == nNumb)
		{
			g_user[i].nNumb = -1;//等于-1是因为while(-1)表示跳过本次循环，while(0)表示终止循环
			break;
		}
		i++;
	}
	if (g_user[i].nNumb == 0)
	{
		puts("学号不存在");
	}
	else
	{
		Save();
		Print();
	}
}
void Modify()//修改函数
{
	Print();
	printf("请输入要修改的学号：");
	int nNumb;
	scanf_s("%d", &nNumb);
	int i = 0;
	while (g_user[i].nNumb)
	{
		if (g_user[i].nNumb == nNumb)
		{
			printf("请输入学号：");
			scanf_s("%d", &g_user[i].nNumb);
			printf("请输入姓名：");
			scanf_s("%s", g_user[i].sName, sizeof(g_user[i].sName));
			printf("请输入成绩：");
			scanf_s("%f", &g_user[i].fMath);
			break;
		}
		i++;
	}
	if (g_user[i].nNumb == 0)
	{
		puts("学号不存在");
	}
	else
	{
		Print();
		Save();
	}
}
void SortByNumb()//按学号排序
{
	int i = 0, n = 0;//n是总数
	while (g_user[n].nNumb)//冒泡排序
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
void SortByName()//按名字排序
{
	int i = 0, n = 0;//n是总数
	while (g_user[n].nNumb)//冒泡排序
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
void SortByMath()//按成绩排序
{
	int i = 0, n = 0;//n是总数
	while (g_user[n].nNumb)//冒泡排序
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
	puts("1、按学号排序");
	puts("2、按姓名排序");
	puts("3、按成绩排序");
	puts("0、返回主菜单");
	puts("请选择：");
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
int Menu()//主菜单
{
	puts("1、浏览所有信息");
	puts("2、添加信息");
	puts("3、删除信息");
	puts("4、修改信息");
	puts("5、查找信息");
	puts("0、退出");
	puts("请选择：");
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
		puts("请输入正确的选项");
		break;
	}
	return i;
}
void Load()
{
	FILE* pf = fopen("data.lv","r");
	if (!pf)
	{
		puts("文件打开失败");
		return;
	}
	int i = 0;
	SUser u;//临时缓冲区
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