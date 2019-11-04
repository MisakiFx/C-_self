#pragma once
#include <iostream>
#include <utility>
#include <vector>
//这里现在存的就是链表结点
//这里我们使用单链表就行了
//这里依然为了更好的封装对原有的哈希桶进行了修改
template<class V>
struct HashNode
{
    HashNode(const V& data = V())
        :_data(data)
        ,_next(nullptr)
    {
    }
    V _data;
    HashNode<V>* _next;
};
template<class K, class V, class KeyOfCalue>
class HashTable;
template<class K, class V, class KeyOfValue>
class _HashIterator
{
public:
    typedef HashNode<V> Node;
    typedef _HashIterator<K, V, KeyOfValue> Self;
    typedef HashTable<K, V, KeyOfValue> HTable;
    _HashIterator(Node* node, HTable* pht)
        :_node(node)
        ,_pht(pht)
    {
    }
    V& operator*()
    {
        return _node->_data;
    }
    V* operator->()
    {
        return &_node->_data;
    }
    bool operator!=(const Self& it)
    {
        return _node != it._node;
    }
    Self& operator++()
    {
        if(_node->_next)
        {
            _node = _node->_next;
        }
        else
        {
            KeyOfValue kov;
            //找到下一个非空链表头
            //1、首先确定当前迭代器在哈希表中的位置
            int index = kov(_node->_data) % _pht->_ht.size();
            ++index;
            while(index < _pht->_ht.size())
            {
                if(_pht->_ht[index])
                {
                    _node = _pht->_ht[index];
                    break;
                }
                ++index;
            }
            if(index == _pht->_ht.size())
            {
                _node = nullptr;
            }
        }
        return *this;
    }
private:
    Node* _node;
    HTable* _pht;
};
template<class K, class V, class KeyOfValue>
class HashTable
{
    friend class _HashIterator<K, V, KeyOfValue>;
public:
    typedef HashNode<V> Node;
    typedef _HashIterator<K, V, KeyOfValue> iterator;
    //迭代器相关
    iterator begin()
    {
        for(int i = 0; i < _ht.size(); i++)
        {
            if(_ht[i] != nullptr)
            {
                return iterator(_ht[i], this);
            }
        }
        return iterator(nullptr, this);
    }
    iterator end()
    {
        return iterator(nullptr, this);
    }
    HashTable(size_t n = 10)
        :_size(0)
    {
        _ht.resize(n, nullptr);
    }
    //插入
    std::pair<iterator, bool> Insert(const V& data)
    {
        //检查负载因子，超过阈值进行扩容
        CheckCapacity();
        //计算位置
        KeyOfValue kov;
        int index = kov(data) % _ht.size();
        //遍历单链表
        Node* cur = _ht[index];
        while(cur)
        {
            if(kov(cur->_data) == kov(data))
            {
                return std::make_pair(iterator(cur, this), false);
            }
            cur = cur->_next;
        }
        //插入，这里用头插其实比较方便，尾插也可以
        cur = new Node(data);
        cur->_next = _ht[index];
        _ht[index] = cur;
        ++_size;
        return std::make_pair(iterator(cur, this), true);
    }
    //查找
    Node* Find(const K& key)
    {
        KeyOfValue kov;
        int index = key % _ht.size();
        Node* cur = _ht[index];
        while(cur)
        {
            if(kov(cur->_data) == key)
            {
                return cur;
            }
            cur = cur->_next;
        }
        return nullptr;
    }
    //删除
    bool Erase(const K& key)
    {
        int index = key % _ht.size();
        Node* cur = _ht[index];
        Node* parent = nullptr;
        KeyOfValue kov;
        while(cur)
        {
            if(kov(cur->_data) == key)
            {
                //删除
                if(parent == nullptr)
                {
                    _ht[index] = cur->_next;
                }
                else
                {
                    parent->_next = cur->_next;
                }
                delete cur;
                --_size;
                return true;
            }
            parent = cur;
            cur = cur->_next;
        }
        return false;
    }
    void CheckCapacity()
    {
        //这里的阈值可以设置的稍微高一些，毕竟哈希桶的冲突不会像闭散列呢样严重
        //这里我们设定为插入元素数 >= 哈希表总长度时扩容
        if(_size >= _ht.size())
        {
            //扩容
            size_t newC = _ht.size() == 0 ? 10 : 2 * _ht.size();
            std::vector<Node*> newHt;
            newHt.resize(newC);
            KeyOfValue kov;
            //搬运数据，将原哈希表中的结点连接到新哈希表上
            for(int i = 0; i < _ht.size(); i++)
            {
                Node* cur = _ht[i];
                while(cur)
                {
                    int index = kov(cur->_data) % newHt.size();
                    Node* next = _ht[i]->_next;
                    //头插进新表
                    cur->_next = newHt[index];
                    newHt[index] = cur;
                    cur = next;
                }
                _ht[i] = nullptr;
            }
            //_ht = newHt;   //这里会进行深拷贝，消耗很大，为了防止深拷贝我们直接交换
            std::swap(_ht, newHt);
        }
    }

private:
    //此时哈希表就相当于一个链表指针数组
    std::vector<Node*> _ht;
    size_t _size;
};