#include <iostream>
int main()
{
    double d = 10.2;
    int i = static_cast<int>(d);
    std::cout << "d:" << d << " i:" << i << std::endl;
    //int i = 10;
    //int *p = &i;
    //int address = static_cast<int>(p);
}