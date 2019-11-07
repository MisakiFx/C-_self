#include <iostream>
using namespace std;
class Base
{
    public:
        void Func()
        {
            cout << "123" << endl;
        }
};
class Deriver : public Base
{
    protected:
        void Func()
        {
            cout << "456" << endl;
        }
};
int main()
{
    Base* b = new Deriver();
    b->Func();
}