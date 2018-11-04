#include <stdio.h>
int main()
{
	int a[10] = {10,2,5,6,32,22,6,7,8,1};
	int i = 0;
	int temp;
	int nMin = 0;//最小的数的下标 
	while (i < 10)//外层循环控制交换 
	{
		nMin = i;
		int j = i + 1;
		while(j < 10)//内层循环寻找剩下数里最小的 
		{
			if(a[j] < a[nMin])
			{
				nMin = j;
			}
			j++;
		}
		if(nMin != i)//如果第一个数不是最小的则与最小的进行交换 
		{
			temp = a[i];
			a[i] = a[nMin];  
			a[nMin] = temp; 
		} 
		i++;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d\t",a[i]);
	}
} 
