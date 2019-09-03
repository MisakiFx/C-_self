#include <iostream>
using namespace std;
class Person
{
public:
    virtual void BuyTicket()
    {
        cout << "full ticket!" << endl;
    }
};
//Student类继承于
class Student: public Person
{
    virtual void BuyTicket()
    {
        cout << "student ticket!" << endl;
    }
};
int main()
{
    Person* p = new Person();
    p->BuyTicket();
    Person* p2 = new Student();//切割，将子类对象指针赋值给父类指针
    p2->BuyTicket();
}