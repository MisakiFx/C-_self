#include <iostream>
int main()
{
    int i = 10;
    double d;
    int* p = &i;
    //将指针强转为整形
    long long address = reinterpret_cast<long long>(p);
    std::cout << p << " " << address;
}