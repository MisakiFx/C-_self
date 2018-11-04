#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
/*
绑定适配器：bind1st、bind2nd
将n元函数对象的指定参数绑定为一个常数，得到n-1元函数对象
组合适配器：not1、not2
将指定谓词的结果取反
函数指针适配器：ptr_fun
将一般函数指针转换为函数对象，使之能够作为其它函数适配器的输入。
在进行参数绑定或其他转换的时候，通常需要函数对象的类型信息，例如bind1st和bind2nd要求函数对象必须继承于binary_function类型。但如果传入的是函数指针形式的函数对象，则无法获得函数对象的类型信息。
成员函数适配器：ptrfun、ptrfun_ref
对成员函数指针使用，把n元成员函数适配为n + 1元函数对象，该函数对象的第一个参数为调用该成员函数时的目的对象
也就是需要将“object->method()”转为“method(object)”形式。将“object->method(arg1)”转为二元函数“method(object, arg1)”。
*/
int main() {
    int intArr[] = { 30, 90, 10, 40, 70, 50, 20, 80 };
    const int N = sizeof(intArr) / sizeof(int);
    vector<int> a(intArr, intArr + N);
    vector<int>::iterator p = find_if(a.begin(), a.end(), bind2nd(greater<int>(), 40));
	//binder2nd的实例构造通常比较冗长，bind2nd函数用于辅助构造binder2nd，产生它的一个实例。
	//binder1st和bind1st，将一个具体值绑定到二元函数的第一个参数。
    if (p == a.end())
        cout << "no element greater than 40" << endl;
    else
        cout << "first element greater than 40 is: " << *p << endl;
    return 0;
}
