#include <iostream>
#include <thread>
#include <mutex>
#include <Windows.h>
#include <condition_variable>

int flag = 0;
std::mutex mutex;
std::condition_variable cv1;
std::condition_variable cv2;

void PrintCHar()
{
    while(1)
    {
        std::unique_lock<std::mutex> uniLock(mutex);
        while(flag == 1)
        {
            cv1.wait(uniLock);
        }
        std::cout << 'A' << std::endl;
        Sleep(1000);
        flag = 1;
        cv2.notify_all();
    }
}
void PrintCHar2()
{
    while(1)
    {
        std::unique_lock<std::mutex> uniLock(mutex);
        while(flag == 0)
        {
            cv2.wait(uniLock);
        }
        std::cout << 'B' << std::endl;
        Sleep(1000);
        flag = 0;
        cv1.notify_all();
    }
}
int main()
{
    std::thread thr1(PrintCHar);
    std::thread thr2(PrintCHar2);
    thr1.join();
    thr2.join();
}