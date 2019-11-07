#include <iostream>

int fun()
{
    return 10;
}
int main()
{
    //auto a;//这是不合法的，因为编译器此时无法判断它的类型
    decltype(3 + 1) b;//decltype可以通过推导括号中表达式的类型来定义变量
    std::cout << typeid(b).name() << std::endl;//typeid可以识别变量类型，它也以RTTI的思想来实现的
    decltype(fun()) c;
    std::cout << typeid(c).name() << std::endl;//typeid可以识别变量类型，它也以RTTI的思想来实现的
}