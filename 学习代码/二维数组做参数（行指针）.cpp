#include <stdio.h>
void Test(double (*ar)[12])//二维数组做参数，参数类型是一个行指针(二维数组里每一行的数组指针) ，大小为这一行给所有元素大小之和 
{
	printf("%d\n",sizeof(ar));
	printf("%d\n",sizeof(ar[0]));
	int i = 0;
	while (i < 3)
	{
		int j = 0;
		while(j < 12)
		{
			printf("%d\t",(int)ar[i][j]);
			j++;
		}
		printf("\n");
		i++;
	 } 
}
int main()
{
	double ar[3][12] = {
	{1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1},
	};//定义和使用行指针完全不同，就和定义和使用指针完全不同一样 
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 12; j++)
		{
			printf("%d\t",(int)ar[i][j]);//强制类型转换 
		}
		printf("\n");
	}
	printf("%d\n",sizeof((*ar)[12])); //二维数组的数组名对应的是第一个行指针，所以取值是去的也是第一个行指针 
	Test(ar);
} 
