#include <stdio.h>
//��Ϊ�ṹ����Դ������ڴ�ռ��
struct SDate
{
	unsigned int nYear : 8;//λ�ṹ�壬ð�ź����ʾ��ֵ����ɶ���������ռ�����λ��
	unsigned int nMonth : 3;//3λ���������Ϊ2 ^ 3 - 1 = 7
	unsigned int nDay : 4;
	unsigned int nHour : 5;
	unsigned int nMin : 6;
	unsigned int nSec : 6;
};
struct STest//��ͨ�ṹ�壬���ʹ洢
{
	char c;
	short sh;
	int i;
};
union UTest//����,ʹ�ò��ʹ���,���б�����ռ����ͬ���ĸ��ֽ�
{
	char c;
	short sh;
	int i;
};
enum ETest//ö��,�൱����define���峣�������ñ������ͣ��ö��ż��
{
	T = 1,
	AAA,
	BBB,
	CCC,
};
void Test()
{
	STest t = { -1,0,-1 };
	printf("%d\n", sizeof(t));
}
void Test2()
{
	UTest t = {0x11223344};
	printf("%d",t.c);
}
int main()
{
	SDate t = {2018 - 1900, 3, 3, 12, 16, 30};//�����ֵ����λ������װ�ص��������޾ͻᶪ������λ���������
	printf("%d\n", sizeof(t));//ֻ���ĸ��ֽڱ���������ʱ����
	printf("%d��%d��%d��%dʱ%d��%d��\n",t.nYear+1900,t.nMonth,t.nDay,t.nHour,t.nMin,t.nSec);
	//Test();
	Test2();
	return 0;
}