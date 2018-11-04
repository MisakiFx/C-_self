#include <stdio.h>
#include <string.h> 
char string[] = "A string\tof ,,tokens\nand some more tokens";
char seps[] = " ,\t\n";
char* token;
int main()
{
	printf("Tokens：");
	token = strtok(string,seps);//字符串截断函数，第一个参数是目标字符串，第二个参数是截断字符,返回值是截断后的字符串的地址 
	while (token != NULL)
	{
		printf("%s\n",token);
		token = strtok(NULL,seps);//如果是想要继续截断上次截断的字符串则把第一个参数设置为NULL即可 
	} 
	
} 
