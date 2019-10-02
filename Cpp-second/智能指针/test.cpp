#include <iostream>
using namespace std;
void Func()
{
    int* ptr = new int[10];
    //...假设这其中有很多代码
    throw "error!";
    // delete[] ptr;
}
int main()
{
    try
    {
        Func();
    }
    catch(const char* str)
    {
        cout << str;
    }
}