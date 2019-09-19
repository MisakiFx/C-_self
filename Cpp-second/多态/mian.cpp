#include <iostream>
using namespace std;
class Abstract
{
public:
    virtual void BuyTicket() = 0;
    virtual void Ticket() = 0;
};
class Person : public Abstract
{
public:
    virtual void BuyTicket()
    {
        cout << "full ticket!" << endl;
    }
    virtual void Ticket()
    {

    }
    virtual ~Person()
    {
        cout << "~Person()" << endl;
    }
};
//Student类继承于
class Student: public Abstract
{
    virtual void BuyTicket()
    {
        cout << "student ticket!" << endl;
    }
    virtual void Ticket()
    {

    }
    virtual ~Student()
    {
        cout << "~Student()" << endl;
    }
};
int main()
{
    //这里肯定会造成内存泄露，这里为了演示暂时不考虑内存泄露的问题
    Abstract* p = new Person();
    p->BuyTicket();
    Abstract* p2 = new Student();//切割，将子类对象指针赋值给父类指针
    p2->BuyTicket();
    delete p;//调用Person析构函数
    delete p2;//调用Student析构函数，由于Student继承于Person所以还会再调用基类析构函数
}