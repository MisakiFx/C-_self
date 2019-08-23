#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
    //如果我们设计一个类考虑到它会被继承那么最好用protected成员取代private成员
    //protected成员在类外部仍然是无法使用的，但是在派生类中它是可见的也就是可以使用的
    //Person()
    //{
    //    cout << "im a Person" << endl;
    //}
    void Print()
    {
        cout << "Person::Print()" << endl;
//        cout << "age = " << _age << endl;
//        cout << "name = " << _name << endl;
    }
    static int _count;
protected:
    int _age = 20;
    string _name = "Misaki"; 
};
int Person::_count = 1;
//Programer类，这里让其公有继承Person类
//这时继承产生的新类被称为子类，也叫派生类
//被继承的旧类被称为父类，也叫基类
//继承方式为公有(public)，其会让基类中的public成员成为派生类中的public成员
//基类中的protected成员成为派生类中的protected成员，基类中的private成员在派生类中不可见
//关于继承方式也在下文讲解
//class Programer: public Person
//{
//    //这里我们不再重写几个默认生成的成员函数，他们默认会完成他们应有的功能
//    //具体派生类的默认成员函数会在下文讲解
//protected:
//    int _workyear;
//};
//派生类
class Teacher: public Person
{
public:
    void Print()
    {
        cout << "Teacher::Print()" << endl;
    }
    void PrintAge()
    {
        cout << "Teacher::_age:" << _age << endl;//重名成员构成隐藏
        cout << "Person::_age:" << Person::_age << endl;//显示调用基类成员
    }
    static int _count;
protected:
    int _age = 19;
};
int Teacher::_count = 2;
int main()
{
    cout << Person::_count << endl;
    cout << Teacher::_count << endl;
    cout << Teacher::Person::_count << endl;
    //Person person;
    //person.Print();//Person::Print()
    //Programer programer;
    //Teacher teacher;
    //teacher.Print();//Teacher::Print()
    //teacher.PrintAge();
    //person.Print();
    //programer.Print();
    //teacher.Print();
    //teacher是派生类对象，person是基类对象，这样的隐式类型转换是允许的
    //person = teacher;
    ////也可以用派生类对象来拷贝构造基类对象
    //Person person2 = teacher;
    //person.Print();
    //person2.Print();
}