#pragma once
template<class T>
//定义结点类
struct ListNode
{
    ListNode<T>* _prev;
    ListNode<T>* _next;
    T _data;
    ListNode(const T& data = T())
        :_prev(nullptr)
        ,_next(nullptr)
        ,_data(data)
    {}
};
//由于const_iterator与iterator除了在迭代器返回值上不一样外其他要求完全一样
//因此这里要进行实现时可以考虑定义两个类
//但是这里使用一种取巧的方法我们将返回值类型当作模板参数传入模板中
template<class T, class Ref, class Ptr>
struct ListIterator
{
    typedef ListNode<T> Node;
    typedef ListIterator<T, Ref, Ptr> Self;
    //构造函数
    ListIterator(Node* node)
        :_node(node)
    {}
    //operator* 为了让其可以和指针一样使用，返回引用
    Ref operator*()
    {
        return _node->_data;
    }
    //operator-> 为了让其可以和指针一样使用，返回指针
    //这里实际调用it->只能取到数据的指针，所以正常来说得写成it->->
    //但是经过编译器优化，只用写it->就可以取到值了
    Ptr operator->()
    {
        return &(_node->_data);
    }
    Self operator++()
    {
        _node = _node->_next;
        return _node;    
    }
    Self operator++(int)
    {
        Self temp(_node);
        _node = _node->_next;
        return temp;
    } 
    Self operator--()
    {
        _node = _node->_prev;
        return _node;    
    }
    Self operator--(int)
    {
        Self temp(_node);
        _node = _node->_prev;
        return temp;
    } 
    bool operator!=(Self it)
    {
        return _node != it._node;
    }
    Node* _node;
};
//构建一个带头结点双向循环链表来模拟实现list
template<class T>
class List
{
    typedef ListNode<T> Node;
public:
    typedef ListIterator<T, T&, T*> iterator;
    typedef ListIterator<T, const T&, const T*> const_iterator;
    //构造函数
    List()
    {
        _head = new Node();
        _head->_next = _head;
        _head->_prev = _head;
    }
    iterator begin()
    {
        return _head->_next;
    }
    const_iterator begin() const
    {
        return _head->_next;
    }
    iterator end()
    {
        return _head;
    }
    const_iterator end() const
    {
        return _head;
    }
private:
    Node* _head;
};