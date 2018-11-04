#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
/*
����������bind1st��bind2nd
��nԪ���������ָ��������Ϊһ���������õ�n-1Ԫ��������
�����������not1��not2
��ָ��ν�ʵĽ��ȡ��
����ָ����������ptr_fun
��һ�㺯��ָ��ת��Ϊ��������ʹ֮�ܹ���Ϊ�������������������롣
�ڽ��в����󶨻�����ת����ʱ��ͨ����Ҫ���������������Ϣ������bind1st��bind2ndҪ�����������̳���binary_function���͡������������Ǻ���ָ����ʽ�ĺ����������޷���ú��������������Ϣ��
��Ա������������ptrfun��ptrfun_ref
�Գ�Ա����ָ��ʹ�ã���nԪ��Ա��������Ϊn + 1Ԫ�������󣬸ú�������ĵ�һ������Ϊ���øó�Ա����ʱ��Ŀ�Ķ���
Ҳ������Ҫ����object->method()��תΪ��method(object)����ʽ������object->method(arg1)��תΪ��Ԫ������method(object, arg1)����
*/
int main() {
    int intArr[] = { 30, 90, 10, 40, 70, 50, 20, 80 };
    const int N = sizeof(intArr) / sizeof(int);
    vector<int> a(intArr, intArr + N);
    vector<int>::iterator p = find_if(a.begin(), a.end(), bind2nd(greater<int>(), 40));
	//binder2nd��ʵ������ͨ���Ƚ��߳���bind2nd�������ڸ�������binder2nd����������һ��ʵ����
	//binder1st��bind1st����һ������ֵ�󶨵���Ԫ�����ĵ�һ��������
    if (p == a.end())
        cout << "no element greater than 40" << endl;
    else
        cout << "first element greater than 40 is: " << *p << endl;
    return 0;
}
