#include <iostream>

class A
{
public:
    A()
        :A(10, 20)//无参构造中调用带参构造
    {

    }
    A(int a, int b)
        :A()//带参构造中调用无参构造
    {
        _a = a;
        _b = b;
    }
private:
    int _a;
    int _b;
};
int main()
{
    A a;
    std::cout << "finish" << std::endl;//这里调用就会出现死递归调用，从而崩掉
}