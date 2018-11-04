#include <iostream>
using namespace std;
/** 重载决议 */ 
void Swap(int a, int b)//Swap_int_int 
{
	cout << a << b << '1' << endl;
}
void Swap(double a, double b)//Swap_double_double
{
	cout << a << b << '2' <<endl;
} 
void Sort(int[],int);
void Sort(float[],int);
void Sort(double[],int); 
void Show(int[],int);
void Show(float[],int);
void Show(double[],int);
int main()
{
	//函数名相同参数列表不同，函数重载
	//引用和非引用之间不能重载，引用类型和对应的非引用类型的特征标相同 
	int iNums[] = {56,54,55,89,43};
	float fNums[] = {56.0f,54.8f,55.5f,89.4f,43.3f};
	double dNums[] = {57.0,58.9,99.1,55.4,12.1};
	cout << "排序前：";
	Show(iNums,sizeof(iNums)/sizeof(iNums[0]));
	Sort(iNums,sizeof(iNums)/sizeof(iNums[0]));
	cout << "排序后：";
	Show(iNums,sizeof(iNums)/sizeof(iNums[0]));
	cout << "排序前：";
	Show(fNums,sizeof(fNums)/sizeof(fNums[0]));
	Sort(fNums,sizeof(fNums)/sizeof(fNums[0]));
	cout << "排序后：";
	Show(fNums,sizeof(fNums)/sizeof(fNums[0]));
} 
void Sort(int nums[],int len)
{
	int temp;
	for(int i = 0;i < len - 1; i++)
	{
		for(int j = 0; j < len - i - 1; j++)
		{
			if(nums[j] > nums[j+1])
			{
				temp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = temp;
			}
		}
	}
}
void Sort(float nums[],int len)
{
	float temp;
	for(int i = 0;i < len - 1; i++)
	{
		for(int j = 0; j < len - i - 1; j++)
		{
			if(nums[j] > nums[j+1])
			{
				temp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = temp;
			}
		}
	}
}
void Sort(double nums[],int len)
{
	double temp;
	for(int i = 0;i < len - 1; i++)
	{
		for(int j = 0; j < len - i - 1; j++)
		{
			if(nums[j] > nums[j+1])
			{
				temp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = temp;
			}
		}
	}
}
void Show(int nums[],int len)
{
	for(int i; i < len; i++)
	{
		cout << nums[i] << '\t';
	}
	cout << endl;
}
void Show(float fNums[],int len)
{
	for(int i; i < len; i++)
	{
		cout << fNums[i] << '\t';
	}
	cout << endl;
}
void Show(double dNums[],int len)
{
	for(int i; i < len; i++)
	{
		cout << dNums[i] << '\t';
	}
	cout << endl;
}
