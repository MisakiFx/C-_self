#include <iostream>
int main()
{
    const int i = 10;
    std::cout << i << std::endl;
    int& r = const_cast<int&>(i); 
    r = 11;
    std::cout << i << std::endl;
    std::cout << r << std::endl;
    const int a = 2;
    int *p = const_cast<int *>(&a);
    *p = 3;

    std::cout << a << std::endl;
    std::cout << *p << std::endl;
}