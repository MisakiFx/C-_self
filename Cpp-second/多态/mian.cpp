#include <iostream>
using namespace std;
class Person
{
public:
    virtual Person* BuyTicket()
    {
        cout << "full ticket!" << endl;
        return new Person;
    }

    
};
//Student类继承于
class Student: public Person
{
    //参数不同无法构成重写
    virtual Student* BuyTicket()
    {
        cout << "student ticket!" << endl;
        return new Student;
    }
};
int main()
{
    //这里肯定会造成内存泄露，这里为了演示暂时不考虑内存泄露的问题
    Person* p = new Person();
    p->BuyTicket();
    Person* p2 = new Student();//切割，将子类对象指针赋值给父类指针
    p2->BuyTicket();
}