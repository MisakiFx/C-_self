#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
/*
浮点数输出精度的默认值是6，例如：3466.98。
要改变精度：setprecision操纵符（定义在头文件iomanip中）。
如果不指定fixed或scientific，精度值表示有效数字位数。
如果设置了iosbase::fixed或iosbase::scientific精度值表示小数点之后的位数。
*/
int main() {
    double values[] = { 1.23, 35.36, 653.7, 4358.24 };
    string names[] = { "Zoot", "Jimmy", "Al", "Stan" };
    for (int i=0;i<4;i++)
      cout << setiosflags(ios_base::left)
        << setw(6) << names[i]
        << resetiosflags(ios_base::left)//清除左对齐设置
        << setw(10) << setprecision(1) << values[i] << endl;
    return 0;
}
