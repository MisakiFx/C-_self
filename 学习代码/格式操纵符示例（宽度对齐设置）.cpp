#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
/*
setiosflags�Ĳ��������ĸ�ʽ��ʶ��
ios_base::skipws �������������հ� ��
ios_base::left �����ֵ��������ַ�����ұߡ�
ios_base::right �Ҷ���ֵ��������ַ������ߣ�Ĭ�϶��뷽ʽ����
ios_base::internal �ڹ涨�Ŀ���ڣ�ָ��ǰ׺����֮����ֵ֮ǰ������ָ��������ַ���
ios_base::dec ��ʮ������ʽ��ʽ����ֵ��Ĭ�Ͻ��ƣ���
ios_base::oct �԰˽�����ʽ��ʽ����ֵ ��
ios_base::hex ��ʮ��������ʽ��ʽ����ֵ��
ios_base::showbase ����ǰ׺�����Ա������������ơ�
ios_base::showpoint �Ը�����ֵ��ʾС�����β����0 ��
ios_base::uppercase ����ʮ��������ֵ��ʾ��д��ĸA��F�����ڿ�ѧ��ʽ��ʾ��д��ĸE ��
ios_base::showpos ���ڷǸ�����ʾ���ţ���+������
ios_base::scientific �Կ�ѧ��ʽ��ʾ������ֵ��
ios_base::fixed �Զ����ʽ��ʾ������ֵ��û��ָ�����֣� ��
ios_base::unitbuf ��ÿ�β���֮��ת����������������ݡ�
*/
int main() {
    double values[] = { 1.23, 35.36, 653.7, 4358.24 };
    string names[] = { "Zoot", "Jimmy", "Al", "Stan" };
    for (int i=0;i<4;i++)
      cout << setiosflags(ios_base::left)//�����
           << setw(6) << names[i]
           << resetiosflags(ios_base::left)//�ر������ 
           << setw(10) << values[i] << endl;
    return 0;
}
