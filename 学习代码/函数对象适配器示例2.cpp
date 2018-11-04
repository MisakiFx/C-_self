#include <functional>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool g(int x, int y) {
    return x > y;
}

int main() {
    int intArr[] = { 30, 90, 10, 40, 70, 50, 20, 80 };
    const int N = sizeof(intArr) / sizeof(int);
    vector<int> a(intArr, intArr + N);
    vector<int>::iterator p;
    p = find_if(a.begin(), a.end(), bind2nd(ptr_fun(g), 40));//ptr_fun用于将普通函数构造为函数对象 
    if (p == a.end())
        cout << "no element greater than 40" << endl;
    else
        cout << "first element greater than 40 is: " << *p << endl;
    //STL还提供了not1和not2辅助生成相应的函数对象实例，分别用于一元谓词和二元谓词的逻辑取反。
    p = find_if(a.begin(), a.end(), not1(bind2nd(greater<int>(), 15)));//真假相反，not1针对于一元谓词 
    if (p == a.end())
        cout << "no element is not greater than 15" << endl;
    else
        cout << "first element that is not greater than 15 is: " << *p << endl;

    p = find_if(a.begin(), a.end(), bind2nd(not2(greater<int>()), 15));//真假相反，not2针对于二元谓词，效果与上同 
    if (p == a.end())
        cout << "no element is not greater than 15" << endl;
    else
        cout << "first element that is not greater than 15 is: " << *p << endl;
    return 0;
}
