//#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//public:
//    //如果我们设计一个类考虑到它会被继承那么最好用protected成员取代private成员
//    //protected成员在类外部仍然是无法使用的，但是在派生类中它是可见的也就是可以使用的
//    //Person()
//    //{
//    //    cout << "im a Person" << endl;
//    //}
//    void Print()
//    {
//        cout << "Person::Print()" << endl;
////        cout << "age = " << _age << endl;
////        cout << "name = " << _name << endl;
//    }
//    static int _count;
//protected:
//    int _age = 20;
//    string _name = "Misaki"; 
//};
//int Person::_count = 1;
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
//class Teacher: public Person
//{
//public:
//    void Print()
//    {
//        cout << "Teacher::Print()" << endl;
//    }
//    void PrintAge()
//    {
//        cout << "Teacher::_age:" << _age << endl;//重名成员构成隐藏
//        cout << "Person::_age:" << Person::_age << endl;//显示调用基类成员
//    }
//    static int _count;
//protected:
//    int _age = 19;
//};
//int Teacher::_count = 2;
//#include <iostream>
//#include <string>
//using namespace std;
////基类
//class Person
//{
//public:
//    //这里构造函数就不选择传参了方便起见我都初始化为定值
//    Person()
//        :_age(20)
//        ,_name("Misaki")
//    {
//        cout << "Person()" << endl;
//    }
//    Person(const Person& person)
//        :_age(person._age)
//        ,_name(person._name)
//    {
//        cout << "Person(const Person&)" << endl;
//    }
//    Person& operator=(const Person& person)
//    {
//        if(&person != this)
//        {
//            _age = person._age;
//            _name = person._name;
//        }
//        cout << "Person::operator=(const Person&)" << endl;
//        return *this;
//    }
//    ~Person()
//    {
//        cout << "~Person()" << endl;
//    }
//    void Print()
//    {
//        cout << "age = " << _age << endl;
//        cout << "name = " << _name << endl;
//    }
//protected:
//    int _age;
//    string _name;
//};
////派类
//class Teacher: public Person
//{
//public:
//    //派生类构造函数，先调用基类构造函数，在初始化派生类成员
//    //默认生成的构造函数也是这样实现的
//    Teacher()
//        :Person()
//        ,_teachyear(3)
//    {
//        cout << "Teacher()" << endl;
//    }
//    //拷贝构造函数，先调用基类构造函数对基类成拷贝构造，再拷贝构造派生类成员
//    //默认生成的拷贝构造也是这样的实现方法
//    Teacher(const Teacher& teacher)
//        :Person(teacher)//这里利用派生类对象可以隐式转换为基类对象来调用基类拷贝构造
//        ,_teachyear(3)
//    {
//        cout << "Teacher(const Teacher&)" << endl;
//    }
//    //赋值运算符重载，先调用基类的赋值运算符重载对基类成员进行赋值，再赋值派生类成员
//    //默认生成的赋值运算符重载也是这样的实现方法
//    Teacher& operator=(const Teacher& teacher)
//    {
//        if(&teacher != this)
//        {
//            Person::operator=(teacher);//调用基类的赋值运算符重载，并且用隐式类型转换传参
//            _teachyear = teacher._teachyear;
//        }
//        cout << "Teacher::operator=(const Teacher&)" << endl;
//        return *this;
//    }
//    //要注意派生类析构函数不需要显示调用基类的析构函数，在调用派生类析构函数释放派生类成员后
//    //会自动调用基类的析构函数，来满足先释放派生类成员再释放基类成员的顺序
//    ~Teacher()
//    {
//        cout << "~Teacher()" << endl;
//        //Person::~Person();这样调用会报错
//    }
//    void Print()
//    {
//        Person::Print();
//        cout << "teachyear = " << _teachyear << endl;
//    }
//    static int _count;
//protected:
//    int _teachyear;
//};
//int Teacher::_count = 2;
//#include <iostream>
//#include <string>
//using namespace std;
//class Test;
////基类
//class Person
//{
//    friend class Test;
//public:
//    void Print()
//    {
//        cout << "age = " << _age << endl;
//        cout << "name = " << _name << endl;
//    }
//protected:
//    int _age = 20;
//    string _name = "Misaki";
//};
////派生类
//class Teacher: public Person
//{
//public:
//    void Print()
//    {
//        Person::Print();
//        cout << "teachyear = " << _teachyear << endl;
//    }
//protected:
//    int _teachyear = 3;
//};
//class Test
//{
//public:
//    void Print()
//    {
//        cout << "age = " << person._age << endl;
//        cout << "name = " << person._name << endl;
//    }
//    void Print2()
//    {
//        cout << "age = " << teacher._age << endl;
//        cout << "name = " << teacher._name << endl;
//        //cout << "teachyear = " << teacher._teachyear << endl;//无法访问
//    }
//private:
//    Person person;
//    Teacher teacher;
//};
//#include <iostream>
//#include <string>
//using namespace std;
////基类
//class Person
//{
//public:
//    static void Print()
//    {
//        cout << "Person::_count = " << _count << endl;
//    }
//    static int _count;
//protected:
//    int _age = 20;
//    string _name = "Misaki"; 
//};
//int Person::_count = 1;
////派生类
//class Teacher: public Person
//{
//public:
//    static void Print()
//    {
//        //cout << "Teacher::_count = " << _count << endl;//编不过了，因为静态函数中只能调用静态成员，而此时_count隐藏已经不是静态成员
//        cout << "Person::_count = " << Person::_count << endl;
//    }
//    int _count = 5;
//protected:
//    int _age = 19;
//};
#include <iostream>
using namespace std;
class A
{
public:
    char _a = 'A';
};
//使用虚拟继承使B继承于A
class B: public virtual A
{
public:
    //char _b = 'B';
};
//使用虚拟继承使C继承于A
class C: public virtual A
{
public:
    char _c = 'C';
};
//D继承于B,C
class D: public B, public C
{
public:
    char _d = 'D';
};
int main()
{
    //一旦使用虚拟继承那么D类中就只存在一份A的成员变量
    D d;
    ////无论用什么作用域进行访问都只能访问到同一份
    //d.B::_a = 'E';
    //cout << d._a << endl;
    //cout << d.B::_a << endl;
    //cout << d.C::_a << endl;
    //d.C::_a = 'F';
    cout << d._a << endl;
    d._a = 'B';
    cout << d.B::_a << endl;
    cout << d.C::_a << endl;
    //cout << d.A::_a << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    cout << sizeof(D) << endl;
    int* ptr;
    std::cout << sizeof(ptr) << std::endl;
    //Person::_count = 3;
    //Person::Print();
    //Teacher::Print();
    //Teacher teacher;
    //cout << teacher._count << endl;//可以访问了
    //Test test;
    //test.Print2();
    //Teacher teacher;
    //Teacher teacher1;
    //Teacher teacher2;
    //teacher2 = teacher1;
    //teacher2.Print();
    //Teacher teacher1;
    //Teacher teacher2 = teacher1;
    //teacher2.Print();
    //Teacher teacher;
    //teacher.Print();
    //cout << Person::_count << endl;
    //cout << Teacher::_count << endl;
    //cout << Teacher::Person::_count << endl;
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