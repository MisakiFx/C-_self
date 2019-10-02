#include <iostream>
#include <string>
#include <memory>
void Func()
{
    std::string* ptr = new std::string;
    std::unique_ptr<std::string> uptr(ptr);
    std::unique_ptr<std::string> uptr2(ptr);
}
int main()
{
    Func();
    std::cout << "1" << std::endl;
}