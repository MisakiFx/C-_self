#include <stdio.h>
#include <stdlib.h> 
//在堆空间上申请变量 
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
	int n = 10;//在栈内存储变量
	int i = 0;
	int* p = (int*)malloc(sizeof(int) * 10);//堆内申请空间，4个整形空间，16个字节
	int ar[10];//在栈内定义 
	*(p + 1) = n;//将栈内数据转存到堆内 
	*(p + 2) = -1;
	Test(p,10);//通过函数修改堆内的数据 
	Test(ar,10);//通过函数修改栈内的数据
	SStud st = {1024,"Misaki",5};//在栈内申请的数据 
	SStud* pt = (SStud*)malloc(sizeof(SStud));//在堆内申请的数据
	*pt = st;
	char* ss[] = {"abc","scf","adc","159"};//在栈上申请4个指针变量的数组 
	char** ps = (char**)malloc(sizeof(char*)*4); //在堆上申请4个指针变量的数组 
	while(i < 4)//将栈上的数据转存到堆上 
	{
		ps[i] = ss[i];
		i++;
	} 
} 
