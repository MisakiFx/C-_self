#include <iostream>
class Parent
{
public:
    virtual void Func()
    {

    }
    int s = 10;
};
class Son : public Parent
{
public:
    int s = 11;
};
int main()
{
    Parent* p = new Parent;
    std::cout << p->s << std::endl;
    Son* s = dynamic_cast<Son*>(p);
    if(s == nullptr)
    {
        std::cout << "change error" << std::endl;
        return -1;
    }
    std::cout << s->s << std::endl;
}