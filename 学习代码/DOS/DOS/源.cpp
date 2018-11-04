#include <stdio.h>
#include <cstdlib>
int main()
{
	char a[10];
	printf("Misaki");
	scanf_s("%s",a,_countof(a));
	//在微软c中增添了安全SDL检查，因此scanf不能使用
	//要是想要使用需要取消安全SDL检查，自行百度或者增加define _CRT_SECURE_NO_WARNINGS
	//scanf_s也更加灵活，在输入字符和字符串的时候可以使用sizeof或者_count()来测量字符串长度
	//相当于增加了一个参数，多了一道安全机制,防止数组越界，一旦超过要求的大小会取消字符串的赋值
	//一旦中间赋值出现问题，那么后面所有赋值都会取消
}