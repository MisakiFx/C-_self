#include <iostream>

void Fun(int& x)
{
    std::cout << "lvalue ref" << std::endl;
}
void Fun(const int& x)
{
    std::cout << "const lvalue ref" << std::endl;
}
void Fun(int&& x)
{
    std::cout << "rvalue ref" << std::endl;
}
void Fun(const int&& x)
{
    std::cout << "const rvalue ref" << std::endl;
}
template<class T>
void PerfectForward(T&& t)//在模板中这里不是右值引用，代表未定义类型
{
    Fun(std::forward<T>(t));
}
int main()
{
    PerfectForward(10);//rvalue ref
    int a = 10;
    PerfectForward(a);//lvalue refj
    PerfectForward(std::move(a));//rvalue ref
    const int b = 8;
    PerfectForward(b);//const lvalue ref
    PerfectForward(std::move(b));//const rvalue ref
}