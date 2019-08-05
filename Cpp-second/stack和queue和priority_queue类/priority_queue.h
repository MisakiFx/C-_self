#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
template<class T>
struct Less
{
    bool operator()(const T& obj1, const T& obj2)
    {
        return obj1 < obj2;
    }
};
template<class T>
struct Greater
{
    bool operator()(const T& obj1, const T& obj2)
    {
        return obj1 > obj2;
    }
};

template<class T, class Container = std::vector<T>, class Compare = Less<T>>
class Priority_queue
{
public:
    //向下调整
    void AdjustDown(size_t parent)
    {
        size_t child = parent * 2 + 1;
        Compare com;
        while(child < _con.size())
        {
            if(child + 1 < _con.size() && com(_con[child], _con[child + 1]))
            {
                child++;    
            }
            if(com(_con[parent], _con[child]))
            {
                std::swap(_con[parent], _con[child]);
                parent = child;
                child = parent * 2 + 1;    
            }
            else
            {
                break;
            }
        }
    }
    //向上调整
    void AdjustUp(size_t child)
    {
        size_t parent = (child - 1) / 2;
        Compare com;
        while(child > 0)
        {
            if(com(_con[parent], _con[child]))
            {
                std::swap(_con[parent], _con[child]);
                child = parent;
                parent = (child - 1) / 2;
            }
            else
            {
                break;
            }
        }
    }
    void Push(const T& data)
    {
        _con.push_back(data);
        //模拟push_heap()的功能
        AdjustUp(_con.size() - 1);
    }
    void Pop()
    {
        //模拟pop_heap()的功能
        std::swap(_con[0], _con[_con.size() - 1]);
        _con.pop_back();
        AdjustDown(0);
    }
    size_t Size()
    {
        return _con.size();
    }
    bool Empty()
    {
        return _con.empty();
    }
    T& Top()
    {
        return _con.front();
    }
    const T& Top() const
    {
        return _con.front();
    }
//private:
    Container _con;
};
