#pragma once
#include <assert.h>
//定义结点类
template<class T>
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
    //构造函数j
    List()
    {
        _head = new Node;
        _head->_next = _head;
        _head->_prev = _head;
    }
    //拷贝构造
    List(const List& list)
        :_head(new Node)
    {
        _head->_next = _head;
        _head->_prev = _head;
        const_iterator it = list.begin();
        while(it != list.end())
        {
            Push_back(*it);
            it++;
        }
    }
    //operator=重载
    List& operator=(const List& list)
    {
        List listTemp = list;
        Swap(listTemp);
    }
    //交换
    void Swap(List& list)
    {
        std::swap(_head, list._head);
    }
    //析构函数
    ~List()
    {
        
        while(_head->_next != _head)
        {
            Pop_back();
        }
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
    iterator Erase(iterator& it)
    {
        assert(it._node != nullptr);
        Node* pTemp = it._node;
        Node* pNew = pTemp->_next;
        //it->_node = pTemp->_next;
        pTemp->_prev->_next = pTemp->_next;
        pTemp->_next->_prev = pTemp->_prev;
        delete pTemp;
        return pNew;
    }
    //插入
    iterator Insert(iterator& it, const T& data = T())
    {
        assert(it._node != nullptr);
        Node* newNode = new Node(data);
        newNode->_next = it._node;
        newNode->_prev = it._node->_prev;
        it._node->_prev->_next = newNode;
        it._node->_prev  = newNode;
        return newNode;
    }
    //尾插
    void Push_back(const T& data)
    {
        assert(_head != nullptr);
        Node* tail = _head->_prev;
        Node* newNode = new Node(data);
        newNode->_next = _head;
        newNode->_prev = tail;
        tail->_next = newNode;
        _head->_prev = newNode;
    }
    //尾删
    void Pop_back()
    {
        assert(_head != nullptr);
        if(_head->_next == _head)
        {
            return;
        }
        Node* tail = _head->_prev;
        tail->_prev->_next = _head;
        _head->_prev = tail->_prev;
        delete tail;
    }
private:
    Node* _head;
};