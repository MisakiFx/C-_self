#include <iostream>
using namespace std;
/** ��дģ�溯�� */
//�൱�ڶ���һ�����Թ��������ʹ�õĺ������ڶ���ʱ��һ���Լ����������T��������������
//��������ں������� 
template<typename T> void Sort(T tArray[], int len);//����Tֻ�ڴκ����ڲ���Ч 
template<typename T> void Show(T tArray[], int len);
int main()
{
	int iNums[] = {56,54,55,89,43};
	float fNums[] = {56.0f,54.8f,55.5f,89.4f,43.3f};
	double dNums[] = {57.0,58.9,99.1,55.4,12.1};
	string sNums[] = {"Misaki","ɵ��","�Բ�"}; 
	cout << "����ǰ��";
	Show(iNums,sizeof(iNums)/sizeof(iNums[0]));
	Sort(iNums,sizeof(iNums)/sizeof(iNums[0]));
	cout << "�����";
	Show(iNums,sizeof(iNums)/sizeof(iNums[0]));
	cout << "����ǰ��";
	Show(fNums,sizeof(fNums)/sizeof(fNums[0]));
	Sort(fNums,sizeof(fNums)/sizeof(fNums[0]));
	cout << "�����";
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
