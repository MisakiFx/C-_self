#include <functional>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool g(int x, int y) {
    return x > y;
}

int main() {
    int intArr[] = { 30, 90, 10, 40, 70, 50, 20, 80 };
    const int N = sizeof(intArr) / sizeof(int);
    vector<int> a(intArr, intArr + N);
    vector<int>::iterator p;
    p = find_if(a.begin(), a.end(), bind2nd(ptr_fun(g), 40));//ptr_fun���ڽ���ͨ��������Ϊ�������� 
    if (p == a.end())
        cout << "no element greater than 40" << endl;
    else
        cout << "first element greater than 40 is: " << *p << endl;
    //STL���ṩ��not1��not2����������Ӧ�ĺ�������ʵ�����ֱ�����һԪν�ʺͶ�Ԫν�ʵ��߼�ȡ����
    p = find_if(a.begin(), a.end(), not1(bind2nd(greater<int>(), 15)));//����෴��not1�����һԪν�� 
    if (p == a.end())
        cout << "no element is not greater than 15" << endl;
    else
        cout << "first element that is not greater than 15 is: " << *p << endl;

    p = find_if(a.begin(), a.end(), bind2nd(not2(greater<int>()), 15));//����෴��not2����ڶ�Ԫν�ʣ�Ч������ͬ 
    if (p == a.end())
        cout << "no element is not greater than 15" << endl;
    else
        cout << "first element that is not greater than 15 is: " << *p << endl;
    return 0;
}
