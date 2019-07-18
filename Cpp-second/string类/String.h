#include <assert.h>
#include <string.h>
#include <cstdio>
class String
{
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
                newCapacity = ((newCapacity / 8) + 1 * 8);
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
size_t String::npos = -1;