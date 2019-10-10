#include <iostream>
#include <memory>
#include <string>
template<class T>
class Unique_Ptr
{
public:
    Unique_Ptr(T* ptr)
        :_ptr(ptr)
    {
        std::cout << "construct Unique_ptr" << std::endl;
    }
    ~Unique_Ptr()
    {
        if(_ptr)
        {
            delete _ptr;
        }
        std::cout << "destroy Unique_ptr" << std::endl;
    }
    //使其可以像指针一样使用
    T* operator->()
    {
        return _ptr;
    }
    T& operator*()
    {
        if(_ptr)
        {
            return *_ptr;
        }
    }
private:
    //禁用拷贝构造和赋值运算符重载
    Unique_Ptr(Unique_Ptr& ptr);
    Unique_Ptr& operator=(Unique_Ptr& ptr);
    T* _ptr;
};
void Func()
{
    std::string* ptr = new std::string("Hello");
    Unique_Ptr<std::string> uniqueptr(ptr);
    std::cout << *uniqueptr << std::endl;
    std::cout << uniqueptr->size() << std::endl;
    //Unique_Ptr<std::string> copy(uniqueptr);//编译不通过
    //Unique_Ptr<std::string> copy2 = uniqueptr;//编译不通过
}
int main()
{
    Func();
    //std::string* ptr = new std::string("Hello");
    //std::unique_ptr<std::string> uniqueptr(ptr);
    //std::cout << *uniqueptr << std::endl;
    //std::cout << uniqueptr->size() << std::endl;
    ////拷贝构造和赋值被禁用，防拷贝
    //std::unique_ptr<std::string> copy(uniqueptr);//编译不通过
    //std::unique_ptr<std::string> copy = uniqueptr;//编译不通过
}