#include <iostream>
using namespace std;
//抽象类
class Abstract
{
public:
    virtual void BuyTicket() = 0;
    virtual void Ticket()
    {

    }
};
class Person : public Abstract
{
public:
    //重写纯虚函数
    virtual void BuyTicket()
    {
        cout << "full ticket!" << endl;
    }
    virtual ~Person()
    {
        cout << "~Person()" << endl;
    }
};
class Student: public Abstract
{
    virtual void BuyTicket()
    {
        cout << "student ticket!" << endl;
    }
    virtual ~Student()
    {
        cout << "~Student()" << endl;
    }
};
int main()
{
    //Abstract* pt = new Abstract();//报错，抽象类不能实例化对象
    //之后所有的继承自抽象类的派生类就可以使用抽象类作为统一接口
    Abstract* p = new Person();
    p->BuyTicket();
    Abstract* p2 = new Student();//切割，将子类对象指针赋值给父类指针
    p2->BuyTicket();
    delete p;//调用Person析构函数
    delete p2;//调用Student析构函数，由于Student继承于Person所以还会再调用基类析构函数
}