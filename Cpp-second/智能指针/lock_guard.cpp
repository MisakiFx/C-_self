#include <iostream>
#include <mutex>
#include <thread>
template<class T>
class LockGuard
{
public:
    LockGuard(T& lock)
        :_lock(lock)
    {
        //std::cout << "lock" << std::endl;
        _lock.lock();
    }
    ~LockGuard()
    {
        //std::cout << "unlock" << std::endl;
        _lock.unlock();
    }
private:
    //禁用拷贝构造和赋值运算符重载
    LockGuard(const LockGuard& lck);
    LockGuard<T>& operator=(const LockGuard& lck);
    //这里的锁必须是引用形式的，因为要所在同一个锁上，不能拷贝
    T& _lock;
};
std::mutex mtx;
int num = 0;
void thr_start()
{
    //互斥锁力度越大越好，消耗会小很多
    //LockGuard<std::mutex> lck(mtx); //使用守卫锁
    std::unique_lock<std::mutex> lck(mtx, std::defer_lock);
    lck.lock();
    for(int i = 0; i < 1000000; i++)
    {
        ++num;
    }
}
int main()
{
    //std::mutex mtx;
    //mtx.lock();
    ////...抛异常
    //mtx.unlock();
    //交给守卫锁
    //std::mutex mtx;
    //std::lock_guard<std::mutex> guard(mtx);
    //开启两个线程分别加num一百万次
    std::thread thr1(thr_start);
    std::thread thr2(thr_start);
    thr1.join();
    thr2.join();
    std::cout << "num:" << num << std::endl;
}