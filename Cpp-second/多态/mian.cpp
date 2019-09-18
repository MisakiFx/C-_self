#include <iostream>
using namespace std;
class Person
{
public:
    virtual void BuyTicket()
    {
        cout << "full ticket!" << endl;
    }
    virtual ~Person()
    {
        cout << "~Person()" << endl;
    }
};
//Student类继承于
class Student: public Person
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
    //这里肯定会造成内存泄露，这里为了演示暂时不考虑内存泄露的问题
    Person* p = new Person();
    p->BuyTicket();
    Person* p2 = new Student();//切割，将子类对象指针赋值给父类指针
    p2->BuyTicket();
    delete p;//调用Person析构函数
    delete p2;//调用Student析构函数，由于Student继承于Person所以还会再调用基类析构函数
}