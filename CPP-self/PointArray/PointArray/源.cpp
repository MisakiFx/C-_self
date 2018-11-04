#include <stdio.h>
//指针数组
void Pointer()
{
	int ar[] = {32,45,89,45,78,-1,0};
	int * p = ar;
	while (*p)//用这样的循环打印数组一定要在数组初始化时保证末尾有个0，不然会造成越界打印
	{
		printf("a[%d]:%d\t", p - ar, *p);
		p++;
	}
}
int main()
{
	const char* ar[4] = {"basic","fortran","C++"};//ar[0]..ar[19]指针数组，每个元素都是char*类型
	printf("指针数组的大小为%d\n", sizeof(ar));
	int i = 0;
	while (ar[i])//用这样的循环进行打印则需要将数组的最后一个元素初始化为0，不然会进行越界打印，数组外的内存内的数据是随机的
	{
		printf("ar[%d]:%s，地址是0x%p\t",i,ar[i],ar[i]);
		i++;
	}
	printf("\n");
	Pointer();
	printf("\n");
	//用指针来遍历指针数组
	const char** p = ar;//指向指针的指针，要用两个星号来表示二重指针
	printf("%s", ar[2]);
	return 0;
}