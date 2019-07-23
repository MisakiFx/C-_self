#include <assert.h>
#include <string.h>
#include <cstdio>
#include <algorithm>
class String
{
    friend std::ostream &operator<<(std::ostream &os, String str);
public:
    //迭代器
    typedef char* iterator;
    typedef const char* const_iterator;
    iterator begin()
    {
        return _str;
    }
    const_iterator begin() const
    {
        return _str;
    }
    iterator end()
    {
        return _str+_size;
    }
    const_iterator end() const
    {
        return _str+_size;
    }
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
    //注意：拷贝构造和operator=重载都是不拷贝容量大小的
    //传统写法：创建新的独立内存，销毁原来的内存空间，更新_size, _capacity的值
    //String(const String& str)
    //    :_str(nullptr)
    //    ,_size(0)
    //    ,_capacity(0)
    //{
    //    Resize(str.Size());
    //    strcpy(_str, str._str);
    //}
    ////operator=重载和拷贝构造类似，先用传统写法实现
    //String& operator=(const String& str)
    //{
    //    if(this != &str)
    //    {
    //        Resize(str.Size());
    //        strcpy(_str, str._str);
    //    }
    //}
    //现代写法，另外创建对象让其等于要拷贝的对象，交换两个对象即可
    String(const String& str)
        :_str(nullptr)
        ,_size(0)
        ,_capacity(0)
    {
        String temp(str._str);
        Swap(temp);
    }
    //现代写法，利用拷贝构造函数创建临时对象，交换两个对象，临时对象在函数结束时也会自动释放
    String& operator=(String str)
    {
        Swap(str);
    }
    //交换两个字符串，浅拷贝，不另申请内存空间
    void Swap(String& str)
    {
        std::swap(_str, str._str);
        std::swap(_size, str._size);
        std::swap(_capacity, str._capacity);
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
    size_t Size() const
    {
        return _size;
    }
    //返回_capacity
    size_t Capacity() const
    {
        return _capacity;
    }
    //在某个下标插入一个字符
    void Insert(size_t pos, char ch)
    {
        assert(pos <= _size);
        //容量满了，扩容
        if(_size == _capacity)
        {
            Reserve(2 * _capacity);
        }
        for(int i = _size; i > pos; i--)
        {
            _str[i] = _str[i - 1];
        }
        _str[pos] = ch;
        _size++;
        _str[_size] = '\0';
    }
    //在某个下标处插入一个字符串
    void Insert(size_t pos, const char* str)
    {
        assert(pos <= _size);
        int len = strlen(str);
        //容量不够扩容
        if(_size + len > _capacity)
        {
            Reserve(len + _size);
        }
        for(int i = len + _size - 1; i > pos + len - 1; i--)
        {
            _str[i] = _str[i - len];        
        }
        for(int i = pos; i < pos + len; i++)
        {
            _str[i] = str[i - pos];
        }
        _size += len;
    }
    //+=运算符重载
    String& operator+=(char ch)
    {
        Push_back(ch);
    }
    String& operator+=(const char* str)
    {
        Append(str);
    }
    //删除pos下标开始的npos个字符
    void Erase(size_t pos, size_t npos)
    {
        assert(pos < _size);
        for(int i = pos; i < _size - npos; i++)
        {
            _str[i] = _str[i + npos];
        }
        _size -= npos;
        _str[_size] = '\0';
    }
    //从pos开始找第一个字符为ch返回其下标
    size_t Find(const char ch, size_t pos = 0)
    {
        assert(pos < _size);
        for(size_t i = pos; i < _size; i++)
        {
            if(_str[i] == ch)
            {
                return i;
            }
        }
        return npos;
    }
    //从pos开始找第一个子串为str返回其下标
    size_t Find(const char* str, size_t pos = 0)
    {
        assert(pos < _size);
        for(size_t i = pos; i < _size; i++)
        {
            if(_str[i] == str[0])
            {
                int j = i;
                while (j < i + strlen(str) && _str[j] != '\0')
                {
                    if (_str[j] != str[j - i])
                    {
                        break;
                    }
                    j++;
                }
                //子串遍历完毕,子串与要查找的串完全匹配
                if (j == i + strlen(str))
                {
                    return i;
                }
                //主串遇到结尾，长度不够不用继续查找了
                else if(_str[j] == '\0')
                {
                    break;
                }
                //其他情况本次子串与要查找的串匹配不上，继续下一次子串查找
            }
        }
        return npos;
    }
    //在尾部插入字符
    void Push_back(char ch)
    {
        Insert(_size, ch);
    }
    //字符串拼接
    void Append(const char* str)
    {
        Insert(_size, str);
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
            //释放旧空间
            delete[] _str;
            _str = newStr;
            _capacity = newCapacity - 1;
            return;
        }
    }
    void Resize(size_t size, char ch = '\0')
    {
        if(size < _size)
        {
            _size = size;
            _str[_size] = '\0';
        }
        else
        {
            Reserve(size);
            for(size_t i = _size; i < size; i++)
            {
                _str[i] = ch;
            }
            _size = size;
            _str[_size] = '\0';
        }
    }
    //>运算符重载
    bool operator>(const String& str)
    {
        if(strcmp(_str, str._str) > 0)
        {
            return true;
        }
        return false;
    }
    bool operator==(const String& str)
    {
        if(strcmp(_str, str._str) == 0)
        {
            return true;
        }
        return false;
    }
    bool operator>=(const String& str)
    {
        if(*this > str || *this == str)
        {
            return true;
        }
        return false;
    }
    bool operator<(const String& str)
    {
        if(*this >= str)
        {
            return false;
        }
        return true;
    }
    bool operator<=(const String& str)
    {
        if(*this < str || *this == str)
        {
            return true;
        }
        return false;
    }
    bool operator!=(const String& str)
    {
        if(*this == str)
        {
            return false;
        }
        return true;
    }
    //+运算符重载
    String operator+(char ch)
    {
        String temp(*this);
        temp.Push_back(ch);
        return temp;
    }
    String operator+(const char* str)
    {
        String temp(*this);
        temp.Append(str);
        return temp;
    }
    //取类中的字符串
    char* c_str()
    {
        return _str;    
    }
    //operator[]重载
    char& operator[](size_t pos)
    {
        assert(pos < _size);
        return _str[pos];
    }
    //operator[]重载
    const char& operator[](size_t pos) const
    {
        assert(pos < _size);
        return _str[pos];
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