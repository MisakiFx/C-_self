#include <iostream>
#include <vector>
class Test
{
public:
    Test(int a, int b)
        :_a(a)
        ,_b(b)
    {
    }
    void Print()
    {
        std::cout << _a << " " << _b << std::endl;
    }
private:
    int _a;
    int _b;
};
template<class T>
class Vector
{
public:
    Vector(size_t n = 0)
        :_start(new T[n])
        ,_finish(_start + n)
        ,_endOfStorge(_start + n)
    {
    }
    //我们想要使用初始化列表初始化vector多亏下面这样的构造函数
    Vector(const std::initializer_list<T>& list)//初始化列表容器
        :_start(new T[list.size()])
        ,_finish(_start + list.size())
        ,_endOfStorge(_start + list.size())
    {
        //std::initializer_list容器有三个公有接口，start(), end()提供返回迭代器提供遍历，size()提供大小
        int index = 0;
        for(auto e : list)
        {
            _start[index] = e;
            index++;
        }   
    }
    void Print()
    {
        T* start = _start;
        while(start != _finish)
        {
            std::cout << *start << " ";
            start++;
        }
        std::cout << std::endl;
    }
private:
    T* _start;
    T* _finish;
    T* _endOfStorge;
};
int main()
{
    //内置类型的初始化列表初始化
    //int a = {10};
    //int b = {3 + 4};
    //std::cout << a << " " << b << std::endl;
    //int arr[] = {1, 2, 3, 4};
    //for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    //{
    //    std::cout << arr[i] << " ";
    //}
    //std::cout << std::endl;
    ////自定义类型初始化列表初始化
    //std::vector<int> arr2 = {4, 3, 2, 1};
    //for(auto e : arr2)
    //{
    //    std::cout << e << " ";
    //}
    //std::cout << std::endl;
    //Test test = {7, 8};
    //test.Print();
    Vector<int> vec = {1, 2, 3, 4, 5};//这里会将初始化列表隐式转换为initializer_list
    vec.Print();
}