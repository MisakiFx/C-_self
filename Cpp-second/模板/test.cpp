//#include <iostream>
//#include <vector>
//#include <cstring>
// 
//using namespace std;
// 
////整型模板
//template<unsigned N, unsigned M>
//bool compare (const char (&p1)[N], const char (&p2)[M])
//{
//	std::cout << "size : " << N << " " << M << std::endl;
//	return strcmp(p1, p2);
//}
// 
////指针
//template<const char* C>
//void pointerT(const char* str){
//	std::cout << C << " " << str << std::endl;
//}
// 
////引用
//template<const char (&ra)[9]>
//void referenceT(const char* str){
//	std::cout << ra << " " << str << std::endl;
//}
//
// 
//void f(const char* c) {std::cout << c << std::endl; }
// 
////函数指针
//template<void (*F)(const char*)>
//void fpointerT(const char* c) {
//	F(c);
//}
//
//extern const char ca[] = "Caroline";  //初始化指针
//extern const char cr[9] = "Caroline"; //初始化引用, 包含一个结尾符号
//int main(void)
//{
//    if(compare("Caroline", "Wendy")) {
//		std::cout << "Caroline is long." << std::endl;
//	} else {
//		std::cout << "Wendy is long." << std::endl;
//	}
// 
//	//无法使用局部变量或者动态变量作为模板参数
//	pointerT<ca>("Wendy"); //指针
// 
//	referenceT<cr>("Wendy"); //引用
// 
//	fpointerT<f>("Caroline Wendy"); //函数指针
// 
//	return 0;
//}
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
// 
//enum COLOR{WHITE,BLACK};
//template<COLOR name>//OK
//int process (double v)
//{
//    return v*name;
//}
//template <const char* s>
//class Myclass
//{
//};
//extern const char s1[] = "hello";
//extern const char s2[] = "hello";
//int main()
//{
//    Myclass<s1> m1; //ERROR 指向内部链接对象的指针
//    //Myclass<"hello"> m2;
//    Myclass<s2> m3; //OK指向外部链接对象的指针
//    return 0;
//}
//#include <iostream>
//#include <assert.h>
//using namespace std;
//template<class T, size_t L>
//class Array
//{
//public:
//    Array()
//    :_arr({0})
//    ,_size(0)
//    {}
//    size_t Size() const
//    {
//        return _size;
//    }
//    T& operator[](size_t pos)
//    {
//        assert(pos < _size);
//        return _arr[pos];
//    }
//    void Push_Back(T data)
//    {
//        if(_size < L)
//        {
//            _arr[_size] = data;
//            _size++;
//        }
//        else
//        {
//            cout << "Array is full" << endl;
//        }
//    }
//    void Pop_Back()
//    {
//        if(!Empty())
//        {
//            _size--;
//        }
//        else
//        {
//            cout << "Array is empty" << endl;
//        }
//        
//    }
//    bool Empty() const
//    {
//        return _size == 0;
//    }
//private:
//    T _arr[L];
//    size_t _size;
//};
//int main()
//{
//    const int n = 20;
//    Array<int, n> arr;
//    arr.Push_Back(1);
//    arr.Push_Back(2);
//    arr.Push_Back(2);
//    arr.Push_Back(5);
//    arr.Push_Back(7);
//    arr.Push_Back(5);
//    arr.Pop_Back();
//    arr.Pop_Back();
//    arr.Pop_Back();
//    for(int i = 0; i < arr.Size(); i++)
//    {
//        cout << arr[i] << endl;
//    }
//}
//#include "test.h"
//#include <iostream>
//using namespace std;
//extern int a;
//int main()
//{
//    Print();
//    cout << a << endl;
//}
#include <iostream>
using namespace std;
//为了验证函数模板与类模板
//先写一个函数模板
//template<class T>
//T Add(T a, T b)
//{
//    return a + b;
//}
////特化处理
//template<>
//int Add<int>(int a, int b)
//{
//    cout << "specialization" << endl;
//    return a + b;
//}
//int main()
//{
//    cout << Add(1, 2) << endl;
//}
//template<class T, class T2>
//T Add(T& a, T2& b)
//{
//    return a + b;
//}
//template<class T, class T2>
//T Add(T*& a, T2*& b)
//{
//    cout << "specialization" << endl;
//    return *a + *b;
//}
//int Add(int a, int b)
//{
//    cout << "overload" << endl;
//    return a + b;
//}
template<class T1, class T2>
class Data
{
public:
    Data()
    {
        cout << "Data<T1, T2>" << endl;
    }
private:
    T1 _data1;
    T2 _data2;
};
//这样的把所有的模板参数都进行实例特化的就叫全特化
template<>
class Data<int, char>
{
public:
    Data()
    {
        cout << "Data<int, char>" << endl;
    }
private:
    int _data1;
    char _data2;
};
//这里就是一个部分特化，只将第一个参数进行实例化的情况
template<class T>
class Data<int, T>
{
public:
    Data()
    {
        cout << "Data<int, T>" << endl;
    }
};
//将两个参数类型限制为指针类型，如果两个参数都是指针类型则调用这个特化
template<class T1, class T2>
class Data<T1*, T2*>
{
public:
    Data()
    {
        cout << "Data<T1*, T2*>" << endl;
    }
};
int main()
{
    //double a = 1;
    //double* ap = &a;
    //int b = 2;
    //int* bp = &b;
    //cout << Add(ap, bp) << endl;//调用重载的Add
    //cout << Add<int>(a, b) << endl;//调用特化的Add
    Data<int, int> data1;//这里会调用部分特化
    Data<int, char> data2;//这里调用全特化
    Data<int*, char*> data3;//这里调用类型限制的特化
}