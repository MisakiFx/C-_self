#include <stdio.h>
int main()
{
	int a[10] = {10,2,5,6,32,22,6,7,8,1};
	int i = 0;
	int temp;
	int nMin = 0;//��С�������±� 
	while (i < 10)//���ѭ�����ƽ��� 
	{
		nMin = i;
		int j = i + 1;
		while(j < 10)//�ڲ�ѭ��Ѱ��ʣ��������С�� 
		{
			if(a[j] < a[nMin])
			{
				nMin = j;
			}
			j++;
		}
		if(nMin != i)//�����һ����������С��������С�Ľ��н��� 
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
