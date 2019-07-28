#include <iostream>
#include <vector>
#include "List.h"
using namespace std;
int main()
{
    List<int> list;
    list.Push_back(1);
    list.Push_back(2);
    list.Push_back(3);
    list.Push_back(4);
    list.Push_back(5);
    List<int>::iterator it = list.begin();
    while(it != list.end())
    {
        cout << *it << endl;
        it++;
    }
    List<int> list2;
    list2 = list;
    //list.Pop_back();
    //list.Pop_back();
    //list.Pop_back();
    //list.Pop_back();
    //list.Pop_back();
    //list.Pop_back();
    it = list2.begin();
    while(it != list2.end())
    {
        cout << *it << endl;
        it++;
    }
    //struct Foo 
    //{
    //    Foo(int n, double x)
    //        :_n(n)
    //        ,_x(x)
    //    }
    //    int _n;
    //    double _x;
    //};
    //vector<Foo> v;
    //v.emplace(v.begin(), 42, 3.1416);     // 没有临时变量产生
    //v.insert(v.begin(), Foo(42, 3.1416)); // 需要产生一个临时变量
    //v.insert(v.begin(), {42, 3.1416});    // 需要产生一个临时变量
    //for(int i = 0; i < v.size(); i++)
    //{
    //    cout << v[i]._n << " " << v[i]._x << endl;
    //}
}