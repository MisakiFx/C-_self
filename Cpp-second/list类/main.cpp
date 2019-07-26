#include <iostream>
#include <vector>
using namespace std;
int main()
{
    struct Foo 
    {
        Foo(int n, double x)
            :_n(n)
            ,_x(x)
        {

        }
        int _n;
        double _x;
    };
    vector<Foo> v;
    v.emplace(v.begin(), 42, 3.1416);     // 没有临时变量产生
    v.insert(v.begin(), Foo(42, 3.1416)); // 需要产生一个临时变量
    v.insert(v.begin(), {42, 3.1416});    // 需要产生一个临时变量
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i]._n << " " << v[i]._x << endl;
    }
}