#include <iostream>
#include <string>
#include <memory>
template<class T>
class auto_ptr
{
public:
    //资源管理
    auto_ptr(T* ptr)
        :_ptr(ptr)
    {
        std::cout << "construct smartptr" << std::endl;
    }
    ~auto_ptr()
    {
        if(_ptr)
        {
            delete _ptr;
        }
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
    //拷贝构造和赋值运算符重载
    auto_ptr(auto_ptr& ptr)
    {
        _ptr = ptr._ptr;
        ptr._ptr = nullptr;
        std::cout << "copy construct" << std::endl;
    }
    auto_ptr& operator=(auto_ptr& ptr)
    {
        if(this != &ptr)
        {
            if(_ptr)
            {
                delete _ptr;
            }
            _ptr = ptr._ptr;
            ptr._ptr = nullptr;
        }
        std::cout << "operator=()" << std::endl;
    }
private:
    T* _ptr;
};
void Func()
{
    std::string* ptr = new std::string("Hello");
    auto_ptr<std::string> autoptr(ptr);
    auto_ptr<std::string> copy(autoptr);
    std::cout << *copy << std::endl;
    std::cout << copy->size() << std::endl;
    std::cout << *autoptr << std::endl;
    std::cout << autoptr->size() << std::endl;
}
int main()
{
    Func();
}