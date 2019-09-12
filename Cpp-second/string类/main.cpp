#include <iostream>
#include <string>
#include "String.h"
//#include "String_mod.h"
using namespace std;
int main()
{
    String a = "213";
    a.Reserve(30);
    String b(a);
    cout << b.Size() << " " << b.Capacity() << endl;
    cout << a <<endl;
    cout << a <<endl;
    cout << a <<endl;
    //String b = "1234567";
    ////a.Push_back('8');
    ////char str[] = "123";
    ////a.Insert(7, str);
    ////a.Reserve(16);
    ////a.Resize(5);
    ////a.Erase(2, 3);
    ////int pos = a.Find("234");
    ////cout << pos << endl;
    ////a.Append("abc");
    ////cout << (a <= b) << endl;
    //cout << a << " " << a.Capacity() << " " << a.Size() << endl;
    //String a = "123";
    //a.Resize(8, 'a');
    //cout << a << " " << a.Capacity() << " " << a.Size() << endl;
    //String::iterator it = a.Begin();
    //while(it != a.End())
    //{
    //    cout << *it << endl;
    //    it++;
    //}
    //for(auto e : a)
    //{
    //    cout << e << " ";
    //}
}
