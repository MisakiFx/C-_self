#include <stdio.h>
//ָ������
void Pointer()
{
	int ar[] = {32,45,89,45,78,-1,0};
	int * p = ar;
	while (*p)//��������ѭ����ӡ����һ��Ҫ�������ʼ��ʱ��֤ĩβ�и�0����Ȼ�����Խ���ӡ
	{
		printf("a[%d]:%d\t", p - ar, *p);
		p++;
	}
}
int main()
{
	const char* ar[4] = {"basic","fortran","C++"};//ar[0]..ar[19]ָ�����飬ÿ��Ԫ�ض���char*����
	printf("ָ������Ĵ�СΪ%d\n", sizeof(ar));
	int i = 0;
	while (ar[i])//��������ѭ�����д�ӡ����Ҫ����������һ��Ԫ�س�ʼ��Ϊ0����Ȼ�����Խ���ӡ����������ڴ��ڵ������������
	{
		printf("ar[%d]:%s����ַ��0x%p\t",i,ar[i],ar[i]);
		i++;
	}
	printf("\n");
	Pointer();
	printf("\n");
	//��ָ��������ָ������
	const char** p = ar;//ָ��ָ���ָ�룬Ҫ�������Ǻ�����ʾ����ָ��
	printf("%s", ar[2]);
	return 0;
}