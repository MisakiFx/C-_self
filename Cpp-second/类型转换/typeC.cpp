#include <stdio.h>
int main()
{
    //隐式类型转换
    int i = 10;
    double d = i;
    printf("%d, %.2lf\n", i, d);
    //强制类型转换
    i = (int)d;
    printf("%d, %.2lf\n", i, d);
}