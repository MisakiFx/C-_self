#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main() {
    double values[] = { 1.23, 35.36, 653.7, 4358.24 };
    string names[] = { "Zoot", "Jimmy", "Al", "Stan" };
    cout << setiosflags(ios_base::fixed/*fixed*/);   //指定以定点方式输出 
    for (int i=0;i<4;i++)
      cout << setiosflags(ios_base::left)
        << setw(6) << names[i]
        << resetiosflags(ios_base::left)//清除左对齐设置
        << setw(10) << setprecision(2) << values[i] << endl;//此时设置精度就是小数点后的有效位数 
    return 0;
}
