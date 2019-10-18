#include <iostream>
#include <memory>
#include <string>
//自定义删除器
template<class T>
class FreeDeleter
{
public:
    void operator()(T* ptr)
    {
        free(ptr);
    }
};
template<class T>
class ArrayDeleter
{
public:
    void operator()(T* ptr)
    {
        delete[] ptr;
    }
};
int main()
{
    //ArrayDeleter<std::string> ad;
    std::shared_ptr<std::string> sp1(new std::string[10]{"123", "456"}, ArrayDeleter<std::string>());
    std::cout << sp1.get()[1] << std::endl;
    //FreeDeleter<std::string> fd;
    std::shared_ptr<std::string> sp2((std::string*)malloc(sizeof(std::string)), FreeDeleter<std::string>());
}