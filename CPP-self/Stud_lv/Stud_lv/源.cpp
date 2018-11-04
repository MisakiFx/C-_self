#include <stdio.h>
struct SUser
{
	int nNumb;//学号
	char sName[20];//姓名
	float fMath;//成绩
};
SUser g_user[10000];
void Add()//增加函数
{
	int i = 0;
	while (g_user[i].nNumb)
	{
		i++;//通过循环找到第一个空的结构体数组的下标i
	}
	printf("请输入学号：");
	scanf_s("%d", &g_user[i].nNumb);
	printf("请输入姓名：");
	scanf_s("%s", g_user[i].sName, sizeof(g_user[i].sName));
	printf("请输入成绩：");
	scanf_s("%f", &g_user[i].fMath);
}
void Print()//打印函数
{
	puts("学号\t姓名\t\t成绩");
	int i = 0,sum = 0;
	while (g_user[i].nNumb)
	{
		if (g_user[i].nNumb > -1)//当学号为-1时跳过循环
		{
			printf("%d\t%s\t\t%0.1f\n", g_user[i].nNumb, g_user[i].sName, g_user[i].fMath);
			sum++;
		}
		i++;
	}
	printf("总共有%d个学生\n\n",sum);
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
		puts("请输入正确的选项");
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