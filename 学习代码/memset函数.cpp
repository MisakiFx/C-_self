#include <stdio.h>
#include <memory.h>
int main()
{
	char string[] = "Misaki";
	printf("之前：%s",string);
	memset(string,'*',6);//内存设置函数，第一个参数是修改的目标内存位置，第二个参数是修改为什么，第三个是修改几个,返回值是void型 
	printf("修改后：%s",string); 
} 
