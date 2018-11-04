#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//打开文件(fopen)、关闭文件(fclose)、读文件(fread)、写文件(fwrite)
int main()
{
	//fopen函数第一个参数是文件名,读取文件一定要确定文件存在，不然程序会崩溃
	//第二个参数表示执行的命令,"r"表示读写
	//函数执行后返回一个文件指针，指向被操作文件
	//如果单纯使用fopen要使用不安全版本
	//安全版本要多加一个指向文件指针的指针
	//FILE是一个结构体，实际上是创建了一个结构体指针，这样的东西叫句柄
	FILE* pf = fopen("C:\\Users\\dell\\Desktop\\exercise\\vs2015 c++\\FILE\\test\\1.txt","r");
	//如果把mode换成"w",表示打开空文件,那么如果不存在这个文件，程序也会自动创建一个文件
	//如果文件存在且有内容则会自动清空这个文件
	FILE* df = fopen("C:\\Users\\dell\\Desktop\\exercise\\vs2015 c++\\FILE\\test\\2.txt", "w");
	if (!pf)//返回空指针，文件打开失败
	{
		puts("文件打开失败");
		return -1;
	}
	//fread函数表示读取文件内容
	//第一个参数是缓冲区的首地址，将读取的内容放在这个内存上
	//第二个参数是读取多少块内容
	//第三个参数表示一块有多少个字节
	//第四个参数是目标操作文件的指针
	//函数执行后返回若是非0则表示读取成功
	char s[100] = { 0 };//缓冲区，存放fread函数读取的文件的内容,读取的时候不会自动在结尾添加空字符，会导致字符串不可用，最好一开始将字符串初始化为空
	fread(s,1 ,sizeof(s) ,pf);
	puts(s);
	//fwrite表示写入文件
	//参数和fread函数一样
	//函数返回若是非0表示读取成功
	char d[100] = { 0 };
	gets_s(d);
	fwrite(d,1,strlen(d),df);//将d中的数据输入到df指针所指的文件中
	fclose(pf);
	fclose(df);
}