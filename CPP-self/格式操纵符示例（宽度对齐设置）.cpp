#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
/*
setiosflags的参数（流的格式标识）
ios_base::skipws 在输入中跳过空白 。
ios_base::left 左对齐值，用填充字符填充右边。
ios_base::right 右对齐值，用填充字符填充左边（默认对齐方式）。
ios_base::internal 在规定的宽度内，指定前缀符号之后，数值之前，插入指定的填充字符。
ios_base::dec 以十进制形式格式化数值（默认进制）。
ios_base::oct 以八进制形式格式化数值 。
ios_base::hex 以十六进制形式格式化数值。
ios_base::showbase 插入前缀符号以表明整数的数制。
ios_base::showpoint 对浮点数值显示小数点和尾部的0 。
ios_base::uppercase 对于十六进制数值显示大写字母A到F，对于科学格式显示大写字母E 。
ios_base::showpos 对于非负数显示正号（“+”）。
ios_base::scientific 以科学格式显示浮点数值。
ios_base::fixed 以定点格式显示浮点数值（没有指数部分） 。
ios_base::unitbuf 在每次插入之后转储并清除缓冲区内容。
*/
int main() {
    double values[] = { 1.23, 35.36, 653.7, 4358.24 };
    string names[] = { "Zoot", "Jimmy", "Al", "Stan" };
    for (int i=0;i<4;i++)
      cout << setiosflags(ios_base::left)//左对齐
           << setw(6) << names[i]
           << resetiosflags(ios_base::left)//关闭左对齐 
           << setw(10) << values[i] << endl;
    return 0;
}
