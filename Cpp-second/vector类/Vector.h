#pragma once
#include <assert.h>
#include <memory.h>
template <class T>
class Vector
{
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    //构造函数
    Vector()
        :_start(nullptr)
        ,_finish(nullptr)
        ,_endOfStorge(nullptr)
    {}        
    Vector(size_t n, T val)
        :_start(nullptr)
        ,_finish(nullptr)
        ,_endOfStorge(nullptr)
    {
        Reserve(n);
        for(int i = 0; i < n; i++)
        {
            *_finish = val;
            _finish++;
        }
    }
    //拷贝构造
    Vector(const Vector<T>& vec)
        :_start(nullptr)
        ,_finish(nullptr)
        ,_endOfStorge(nullptr)
    {
        Resize(vec.Size());
        memcpy(_start, vec._start, vec.Size() * sizeof(T));
        _finish = _start + vec.Size();
    }
    //operator=重载
    Vector& operator=(Vector<T> vec)
    {
        Swap(vec);
    }
    void Swap(Vector<T>& vec)
    {
        std::swap(_start, vec._start);
        std::swap(_finish, vec._finish);
        std::swap(_endOfStorge, vec._endOfStorge);
    }
    //析构函数
    ~Vector()
    {
        delete[] _start;
        _start = nullptr;
        _finish = nullptr;
        _endOfStorge = nullptr;
    }
    //operator[]重载
    T& operator[](size_t pos)
    {
        return _start[pos];
    }
    //长度
    size_t Size() const
    {
        return _finish - _start;
    }
    //容量
    size_t Capacity() const
    {
        return _endOfStorge - _start;
    }
    //重新给容量
    void Reserve(size_t capacity)
    {
        if(capacity > Capacity())
        {
            size_t size = Size();
            //分配新的内存空间
            T* newArr = new T[capacity];
            if(_start)
            {
                memcpy(newArr, _start, size * sizeof(T));
            }
            //销毁原有内存空间
            delete[] _start;
            //注意这里更新三个指针都要进行更新，因为三个指针都还指向原来的内存空间
            _start = newArr;
            _finish = _start + size;
            _endOfStorge = _start + capacity;
        }
    }
    //重新给长度,空白部分val填充
    void Resize(size_t size, T val = 0)
    {
        Reserve(size);
        if(Size() < size)
        {
            T* ptr = _finish;
            while(ptr != _start + size)
            {
                *ptr = val;
                ptr++;
            }
        }
        _finish = _start + size;
    }
private:
    //vecotor的实现与string有所不同
    //其底层使用三个迭代器（指针）用来标记头部，尾部和总容量尾部
    iterator _start;
    iterator _finish;
    iterator _endOfStorge;
};