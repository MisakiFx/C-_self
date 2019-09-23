#include <iostream>
using namespace std;
class Base
{
    virtual void Func()
    {
        cout << "Func1" << endl;
    }
    virtual void Func2()
    {
        cout << "Func2" << endl;
    }
    void Func3()
    {
        cout << "Func3" << endl;
    }
private:
    int _a;    
};
class Deliver: public Base
{
    virtual void Func()
    {
        cout << "Func1" << endl;
    }
    void Fun3()
    {
        cout << "Func3" << endl;
    }
private:
    int _b;    
};
int main()
{
    cout << sizeof(Base) << endl;;
    cout << sizeof(Deliver) << endl;;
}