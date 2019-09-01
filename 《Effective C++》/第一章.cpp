//#include <iostream>
//#include <vector>
//using namespace std;
//class GamePlayer
//{
//public:
//    //static const int NumTurns;
//    enum Enum
//    {
//        NumTurns = 5
//    };
//    int scores[NumTurns];//编译器要求在编译时就能确定数组的大小
//};
//const int GamePlayer::NumTurns = 5; 
//int main()
//{
//    cout << GamePlayer::NumTurns << endl;
//}
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//    vector<int> vec = {1, 2, 3, 4};
//    //我们给接下来这个迭代器加上const
//    //其类似于T* const指针，注意不是const T*虽然const写在前面，但这里const强调的是迭代器自身的不可变
//    //迭代器也不过是一个typedef类型而已
//    const vector<int>::iterator iter = vec.begin();
//    *iter = 5;//合法，迭代器所指对象可变
//    //iter++;//不合法，迭代器自身不可变
//    cout << vec[0] << endl;
//    //这里相当于一个const T*指针，指向内容不可改，自身可改
//    vector<int>::const_iterator const_iter = vec.begin();
//    //*const_iter = 1;//不合法，指向内容不可改
//    const_iter++;//合法，自身可变
//    cout << *const_iter << endl;
//}
//#include <iostream>
//using namespace std;
//int Add(int a, int b)
//{
//    return a + b;
//}
//int Add(const int a, const int b)
//{
//    return a + b;
//}
//int main()
//{
//    int a = 1, b = 2;
//    int& ra = a;
//    //cout << Add(ra, b) << endl;
//}
#include <iostream>
#include <string>
using namespace std;
class TextBook
{
public:
    //重载operator[]
    //这里返回值加const是为了让const对象自身不被修改不造成错误
    const char& operator[](size_t position) const
    {
        return text[position];
    }
    char& operator[](size_t position)
    {
        return text[position];
    }
private:
    string text = "123456";
};
void Print(const TextBook& book1, TextBook& book2)
{
    cout << book1[0] << endl;//合法
    cout << book2[0] << endl;//合法
    book2[0] = '5';//合法，普通对象调用普通成员函数，返回值课改
    cout << static_cast<const TextBook&>(book2)[0] << endl;
    //static_cast<const TextBook&>(book2)[0] = '1';//非法这里我们将其转换为const类型对象发现可以主动调用常成员函数
    //book1[0] = '5';//非法，常量对象调用常成员函数而其返回值是const修饰的因此不可改
}
int main()
{
    TextBook book;
    Print(book, book);
}