#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Strcmp(const char* s1, const char* s2)//字符指针就是常量指针 
{
	unsigned char* p1 = (unsigned char*)s1;
	unsigned char* p2 = (unsigned char*)s2;//用unsigned char*重新定义凉意字符串的指针，这样就可以让汉字大于字母 
	while(*p1 && *p2 && *p1 == *p2)//当*s1!=*s2或者两者其中一个出现空字符时跳出循环 
	{
		p1++;
		p2++;
	}
	int n = *p1 - *p2;////让出现的第一个不相同的字符用第一个减掉第二个判断字符串大小 ,'c' - 'b' = 1;
	if(n > 0)
	{
		printf("前面大");
	}
	else if (n < 0)
	{
		printf("后面大");
	}
	else
	{
		printf("一样大");
	}
}
char* Strcpy(char* pDest,const char* pSrc)
{
	char* p = pDest;
	while (*p++ = *pSrc)//将第二个字符串里的数据一个一个给第一个字符串 
	{
		
	}
	return pDest;
}
char Strcat(char* pDest, const char* pSrc)
{
	char*p = pDest;
	while(*p)//找到被拼接函数的连接尾 
	{
		p++;
	}

}
int main()
{
	//可以更改数值可以移动的字符串需要用malloc一个一个赋值进行制作；
	Strcmp("abc","abb");
	
}
