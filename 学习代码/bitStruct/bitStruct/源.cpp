#include <stdio.h>
//用为结构体可以大大减少内存占用
struct SDate
{
	unsigned int nYear : 8;//位结构体，冒号后面表示数值换算成二进制所能占的最大位数
	unsigned int nMonth : 3;//3位，最大数字为2 ^ 3 - 1 = 7
	unsigned int nDay : 4;
	unsigned int nHour : 5;
	unsigned int nMin : 6;
	unsigned int nSec : 6;
};
struct STest//普通结构体，串型存储
{
	char c;
	short sh;
	int i;
};
union UTest//联合,使用并型储存,所有变量都占用相同的四个字节
{
	char c;
	short sh;
	int i;
};
enum ETest//枚举,相当于用define定义常量，不用标明类型，用逗号间隔
{
	T = 1,
	AAA,
	BBB,
	CCC,
};
void Test()
{
	STest t = { -1,0,-1 };
	printf("%d\n", sizeof(t));
}
void Test2()
{
	UTest t = {0x11223344};
	printf("%d",t.c);
}
int main()
{
	SDate t = {2018 - 1900, 3, 3, 12, 16, 30};//如果数值大于位数所能装载的数据上限就会丢掉多余位数里的数据
	printf("%d\n", sizeof(t));//只需四个字节保存年月日时分秒
	printf("%d年%d月%d日%d时%d分%d秒\n",t.nYear+1900,t.nMonth,t.nDay,t.nHour,t.nMin,t.nSec);
	//Test();
	Test2();
	return 0;
}