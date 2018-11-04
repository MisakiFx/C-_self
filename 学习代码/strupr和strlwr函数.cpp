#include <stdio.h>
#include <string.h>
int main()
{
	char string[50];
	char* string1,*string2;
	printf("请输入字符串：");
	scanf("%s",string);
	string1 = strupr(string);//strupr函数将字符串中所有小写字母转换为大写字母，并返回字符串的指针 
	string2 = strlwr(string);//strlwr函数将字符串中所有大写字母转换为小写字母 ，并返回字符串的指针 
	printf("%s\n%s",string1,string2); 
} 
