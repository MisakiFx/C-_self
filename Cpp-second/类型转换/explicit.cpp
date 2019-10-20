#include <iostream>
class Test
{
public:
    explicit Test(int test)
        :_test(test)
    {
        std::cout << "construct" << std::endl;
    }
private:
    int _test;
};
int main()
{
    Test test = 10;//编译不过
}