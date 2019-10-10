#include <iostream>
#include <string>
#include <memory>
template<class T>
class SmartPtr
{
public:
    //资源管理
    SmartPtr(T* ptr)
        :_ptr(ptr)
    {
        std::cout << "construct smartptr" << std::endl;
    }
    ~SmartPtr()
    {
        delete _ptr;
        std::cout << "destory smartptr" << std::endl;
    }
    //使其可以像指针一样使用
    T& operator*()
    {
        return *_ptr;
    }
    T* operator->()
    {
        return _ptr;
    }
private:
    T* _ptr;
};
void Func()
{
    std::string* ptr = new std::string("Hello");
    SmartPtr<std::string> smartPtr(ptr);
    std::cout << *smartPtr << std::endl;
    std::cout << smartPtr->size() << std::endl;
}
int main()
{
    Func();
}