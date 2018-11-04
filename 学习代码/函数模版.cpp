#include <iostream>
using namespace std;
/** 书写模版函数 */
//相当于定义一个可以供多个类型使用的函数，在定义时用一个自己定义的类型T来代替数据类型
//结果相似于函数重载 
template<typename T> void Sort(T tArray[], int len);//类型T只在次函数内部有效 
template<typename T> void Show(T tArray[], int len);
int main()
{
	int iNums[] = {56,54,55,89,43};
	float fNums[] = {56.0f,54.8f,55.5f,89.4f,43.3f};
	double dNums[] = {57.0,58.9,99.1,55.4,12.1};
	string sNums[] = {"Misaki","傻逼","脑残"}; 
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
	cout << endl;
	Show(sNums,3);
} 
template<typename T> 
void Sort(T tArray[], int len)
{
	T temp;
	for(int i = 0;i < len - 1; i++)
	{
		for(int j = 0; j < len - i - 1; j++)
		{
			if(tArray[j] > tArray[j+1])
			{
				temp = tArray[j];
				tArray[j] = tArray[j+1];
				tArray[j+1] = temp;
			}
		}
	}
}
template<typename T> 
void Show(T tArray[], int len)
{
	for(int i; i < len; i++)
	{
		cout << tArray[i] << '\t';
	}
	cout << endl;
	cout << endl;
}
