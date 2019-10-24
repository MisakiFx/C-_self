#include <iostream>
#include <thread>
#include <mutex>
//懒汉模式
class Singleton1
{
public:
    //外留接口
    static Singleton1* GetInstence()
    {
        return &_singleton;
    }
private:
    //防拷贝，禁用构造，拷贝构造和赋值
    Singleton1()
    {

    }
    Singleton1(const Singleton1&);
    Singleton1& operator=(const Singleton1&);
    static Singleton1 _singleton;
};
Singleton1 Singleton1::_singleton;
class Singleton2
{
public:
    static Singleton2* GetInstence()
    {
        //双重判断避免不必要的锁竞争
        if(_pSingleton == nullptr)
        {
            //为了线程安全需要加锁
            _mtx.lock();
            if (_pSingleton == nullptr)
            {
                _pSingleton = new Singleton2;
            }
            _mtx.unlock();
        }
        return _pSingleton;
    }
private:
    Singleton2(){}
    Singleton2(const Singleton2&);
    Singleton2& operator=(const Singleton2&);
    static std::mutex _mtx;
    static Singleton2* _pSingleton;
};
std::mutex Singleton2::_mtx;
Singleton2* Singleton2::_pSingleton = nullptr;
int main()
{

}