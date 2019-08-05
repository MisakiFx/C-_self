#pragma once
#include <iostream>
#include <deque>
template<class T, class Container = std::deque<T>>
class Stack
{
public:
    void Push(const T& data)
    {
        _con.push_back(data);
    }
    void Pop()
    {
        _con.pop_back();
    }
    bool Empty()
    {
        return _con.empty();
    }
    size_t Size()
    {
        return _con.size();
    }
    T& Top()
    {
        return _con.back();
    }
    const T& Top() const
    {
        return _con.back();
    }
private:
    Container _con;
};