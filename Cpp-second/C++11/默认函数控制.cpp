#include <iostream>

class A
{
public:
    A(int a)
        :_a(a)
    {
    }
    A() = default;//生成默认构造
    A(const A& a) = delete;
    A& operator=(const A& a) = delete;
private:
    int _a;
};
int main()
{
    A a(1);
    A b;//合法
    //A b(a);//禁用拷贝
}