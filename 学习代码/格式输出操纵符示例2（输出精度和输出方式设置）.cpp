#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
/*
������������ȵ�Ĭ��ֵ��6�����磺3466.98��
Ҫ�ı侫�ȣ�setprecision���ݷ���������ͷ�ļ�iomanip�У���
�����ָ��fixed��scientific������ֵ��ʾ��Ч����λ����
���������iosbase::fixed��iosbase::scientific����ֵ��ʾС����֮���λ����
*/
int main() {
    double values[] = { 1.23, 35.36, 653.7, 4358.24 };
    string names[] = { "Zoot", "Jimmy", "Al", "Stan" };
    for (int i=0;i<4;i++)
      cout << setiosflags(ios_base::left)
        << setw(6) << names[i]
        << resetiosflags(ios_base::left)//������������
        << setw(10) << setprecision(1) << values[i] << endl;
    return 0;
}
