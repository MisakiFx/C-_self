#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main() {
    double values[] = { 1.23, 35.36, 653.7, 4358.24 };
    string names[] = { "Zoot", "Jimmy", "Al", "Stan" };
    cout << setiosflags(ios_base::fixed/*fixed*/);   //ָ���Զ��㷽ʽ��� 
    for (int i=0;i<4;i++)
      cout << setiosflags(ios_base::left)
        << setw(6) << names[i]
        << resetiosflags(ios_base::left)//������������
        << setw(10) << setprecision(2) << values[i] << endl;//��ʱ���þ��Ⱦ���С��������Чλ�� 
    return 0;
}
