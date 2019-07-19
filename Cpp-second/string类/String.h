#include <assert.h>
#include <string.h>
#include <cstdio>
class String
{
    friend std::ostream &operator<<(std::ostream &os, String str);
public:
    static size_t npos;
    //构造函数
    String(const char* str = "")//要进行深拷贝
        :_str(nullptr)
        ,_capacity(0)
    {
        _size = strlen(str);
        //重新给容量Reserve()
        Reserve(_size);
        //strcpy()拷贝给成员变量
        strcpy(_str, str);
    }
    //拷贝构造，要使用深拷贝
    //所谓深拷贝就是创立独立的内存空间并将目标对象中的值拷贝过来
    //而不是单纯的让指针等于目标拷贝对象中的指针
    //传统写法：创建新的独立内存，销毁原来的内存空间，更新_size, _capacity的值
    String(const String& str)
        :_str(nullptr)
        ,_size(str._size)
        ,_capacity(str._capacity)   
    {
        char* newpstr = new char[str._capacity + 1];
        strcpy(newpstr, str._str);
        delete[] _str;
        _str = newpstr;
    }
    //operator=重载和拷贝构造类似，先用传统写法实现
    String& operator=(String& str)
    {
        if(this != &str)
        {
            _capacity = str._capacity;
            _size = str._size;
            char* newpstr = new char[_capacity + 1];
            strcpy(newpstr, str._str);
            _str = newpstr;
        }
    }
    //析构函数
    ~String()
    {
        if(_str)
        {
            delete[] _str;
            _str = nullptr;
            _size = _capacity = 0;
        }
    }
    //返回_size
    size_t Size()
    {
        return _size;
    }
    //返回_capacity
    size_t Capacity()
    {
        return _capacity;
    }
    //重新给容量，并且要求容量永远为8的整数倍
    void Reserve(size_t n)
    {
        if(n > _capacity || (n == 0 && _capacity == 0))
        {
            size_t newCapacity = n;
            if(newCapacity % 8 != 0)
            {
                newCapacity = (((newCapacity / 8) + 1) * 8);
            }
            else
            {
                newCapacity += 8;
            }
            char* newStr = new char[newCapacity];
            if(newStr && _str)
            {
                strcpy(newStr, _str);
            }
            _str = newStr;
            _capacity = newCapacity - 1;
            return;
        }
    }
private:
    char* _str;
    size_t _size;
    size_t _capacity;
};
std::ostream& operator<<(std::ostream& os, String str)
{
	os << str._str;
	return os;
}
size_t String::npos = -1;