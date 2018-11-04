#include <iostream>
using namespace std;
template <class T>//��������ģ�� 
void mySwap(T &x, T &y)
{
	T temp = x;
	x = y;
	y = temp;
}
template <class T>
void selectionSort(T a[], int n)
{
	for(int i = 0; i < n - 1; i++)
	{
		int leastIndex = i;
		for(int j = i + 1; j < n; j++)
		{
			if(a[j] < a[leastIndex])
			{
				leastIndex = j;
			}
		}
		mySwap(a[i], a[leastIndex]);
	}
}
template <class T>
void bubbleSort(T a[], int n)
{
	int i = n - 1;
	while(i > 0)
	{
		int lastExchangeIndex = 0;
		for(int j = 0; j < i; j++)
		{
			if(a[j + 1] < a[j])
			{
				mySwap(a[j], a[j + 1]);
				lastExchangeIndex = j;
			}
		}
		i = lastExchangeIndex;//�����û��������������Ӹ�Ч���ж���һ���Ƿ��Ѿ�û�н����ˣ����Ѿ������� 
	}
}
template <class T>
int binSearch(const T list[], int n, const T &key)
{
	int low = 0;
	int high = n - 1;
	while(low <= high)
	{
		int mid = (low + high) / 2;
		if(key == list[mid])
		{
			return mid;
		}
		else if(key < list[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}
int main()
{
	
}
