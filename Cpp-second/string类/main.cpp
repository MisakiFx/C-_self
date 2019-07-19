#include <iostream>
#include <string>
#include "String.h"
//#include "String_mod.h"
using namespace std;
int main()
{
    String a = "123";
    a.Reserve(10);
    //a.Resize(5);
    cout << a << " " << a.Capacity() << " " << a.Size() << endl;
    String b;
    b = a;
    cout << b << " " << b.Capacity() << " " << b.Size() << endl;
}
