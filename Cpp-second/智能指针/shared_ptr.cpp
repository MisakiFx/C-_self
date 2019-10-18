#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <mutex>
#include <vector>
template<class T>
class Shared_ptr
{
public:
    //构造函数，应该初始化引用计数为1，并且初始化互斥锁
    Shared_ptr(T* ptr)
        :_ptr(ptr)
        ,_refCount(new int(1))
        ,_mtx(new std::mutex)
    {
        std::cout << "construct" << std::endl;
    }
    //拷贝构造
    Shared_ptr(const Shared_ptr<T>& temp)
        :_ptr(temp._ptr)
        ,_refCount(temp._refCount)
        ,_mtx(temp._mtx)
    {
        std::cout << "copy construct" << std::endl;
        AddRefCount();
    }
    //赋值运算符重载
    Shared_ptr& operator=(const Shared_ptr<T>& temp)
    {
        std::cout << "operator=" << std::endl;
        if(&temp != this)
        {
            Release();
            _ptr = temp._ptr;
            _refCount = temp._refCount;
            _mtx = temp._mtx;
            AddRefCount();
        }
        return *this;
    }
    //析构函数
    ~Shared_ptr()
    {
        std::cout << "destroy" << std::endl;
        Release();
    }
    //返回当前引用计数
    int RefCount()
    {
        return *_refCount;
    }
    //像指针一样使用
    T& operator*()
    {
        return *_ptr;
    }
    T* operator->()
    {
        return _ptr;
    }
private:
    //指针不再指向当前资源
    void Release()
    {
        //操作临界资源，加锁
        bool isRelease = false;
        _mtx->lock();
        //已经没有指针在控制当前资源
        if(--(*_refCount) <= 0)
        {
            //释放资源以及引用计数
            std::cout << "free resouce" << std::endl;
            delete _ptr;
            delete _refCount;
            isRelease = true;
        }
        _mtx->unlock();
        //锁不能在加锁中释放，因此要在锁中判断是否需要释放
        //最后在锁外释放锁的资源
        if(isRelease == true)
        {
            delete _mtx;
        }
    }
    //有新的智能指针指向当前资源，增加引用计数
    void AddRefCount()
    {
        //同样操作临界资源加锁
        _mtx->lock();
        ++(*_refCount);
        _mtx->unlock();
    }
private:
    T* _ptr;
    int* _refCount;
    std::mutex* _mtx;//互斥锁
};
void Test1()
{
    std::cout << "Test1:" << std::endl;
    std::string* str = new std::string("Hello");
    std::string* str2 = new std::string("World");
    Shared_ptr<std::string> sharedPtr(str);
    Shared_ptr<std::string> sharedPtr2(sharedPtr);
    sharedPtr2 = Shared_ptr<std::string>(str2);
    std::cout << *sharedPtr << std::endl;
    std::cout << *sharedPtr2 << std::endl;
}

void thr_start()
{
    std::string* str = new std::string("Hello");
    std::vector<Shared_ptr<std::string>> sharedPtr(10, str);
    std::cout << sharedPtr[0].RefCount() << std::endl;
}
void Test2()
{
    std::cout << "Test2:" << std::endl;
    std::thread thr1(thr_start);
    std::thread thr2(thr_start);
    thr1.join();
    thr2.join();
}
int main()
{
    //std::string* ptr = new std::string("Hello");
    //std::string* ptr2 = new std::string("World");
    //std::shared_ptr<std::string> sharedptr(ptr);
    ////拷贝构造
    //std::shared_ptr<std::string> copy(sharedptr);
    //std::shared_ptr<std::string> copy2(ptr2);
    //std::cout << *copy2 << std::endl;
    ////赋值
    //copy2 = copy;
    //std::cout << *sharedptr << std::endl;
    //std::cout << copy->size() << std::endl;
    //std::cout << *copy2 << std::endl;
    Test1();
    Test2();
}