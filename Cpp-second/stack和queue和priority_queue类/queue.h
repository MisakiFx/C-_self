#pragma once
#include <iostream>
#include <deque>
template<class T, class Container = std::deque<T>>
class Queue
{
public:
    void Push(const T& data)
    {
        _con.push_back(data);
    }
    void Pop()
    {
        _con.pop_front();
    }
    size_t Size()
    {
        return _con.size();
    }
    bool Empty()
    {
        return _con.empty();
    }
    T& Back()
    {
        return _con.back();
    }
    const T& Back() const
    {
        return _con.back();
    }
    T& Front()
    {
        return _con.front();
    }
    const T& Front() const
    {
        return _con.front();
    }
private:
    Container _con;
};