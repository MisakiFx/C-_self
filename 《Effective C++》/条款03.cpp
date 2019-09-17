#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;
class CTextBook
{
friend ostream& operator<<(ostream &cout, const CTextBook& text);
public:
    CTextBook(const char* str)
        :_text(nullptr)
        ,_len(0)
        ,_lengthIsValid(false)
    {
        int capacity = strlen(str) + 1;
        _text = new char[capacity];
        strcpy(_text, str);
    }
    ~CTextBook()
    {
        if(_text != nullptr)
        {
            delete[] _text;
        }
    }
    //const函数
    const char& operator[](size_t position) const
    {
        //在这里加上检查，我们先少些点代码，假设这之前有更多的代码
        //......
        assert(position < length());
        return _text[position];
    }
    //non-const函数
    char& operator[](size_t position)
    {
        //这里只需要调用const版本的函数即可，但是为了调用要先进行类型转换
        //这里用到了将本身的对象转换为常对象来调用常成员函数
        const char& a = static_cast<const CTextBook&>(*this)[position];
        //这里将返回值的const限定去掉
        return const_cast<char&>(a);
    }
    size_t length() const
    {
        if(!_lengthIsValid)
        {
            //这里明显是编译不过的，因为其不是bitwiss constness的
            _len = strlen(_text);
            _lengthIsValid = true;
        }
        return _len;
    }
private:
    char* _text;
    mutable int _len;
    mutable bool _lengthIsValid;
};
ostream& operator<<(ostream &cout, const CTextBook& text)
{
    cout << text._text << endl;
    return cout;
}
int main()
{
    CTextBook text("Hello");
    const CTextBook con_text("Hello");
    //con_text[0] = 'J';//常量成员调用常成员函数，无法更改
    text[0] = 'J';
    cout << text;
    cout << text.length() << endl;
}