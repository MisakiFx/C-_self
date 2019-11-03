#include <iostream>
#include <vector>
#include <utility>

//定义三种状态，DELETE状态是为了方便我们对结点进行删除
enum STATE
{
    EMPTY,
    EXIST,
    DELETE
};

template<class K, class V>
struct HashNode
{
    //为了更好的可以找到映射，哈希表往往存的是一个K-V结构
    std::pair<K, V> _data;
    //状态默认为空
    STATE _state = EMPTY;
};

template<class K, class V>
class HashTable
{
public:
    typedef HashNode<K, V> Node;
    HashTable(const size_t n = 10)
        :_size(n)
    {
        _ht.resize(n);
    }
    bool Insert(const std::pair<K, V>& data)
    {
        //检查容量
        checkCapacity();
        //计算索引，进行散列
        int index = data.first % _ht.size();
        //1、判断当前地方是否有元素，没有直接插入
        //元素可以放在EMPTY和DELETE
        while(_ht[index]._state == EXIST)
        {
            //2、如果有，判断当前位置的元素的key是否和插入的相同，如果相同则插入失败直接返回
            if (_ht[index]._data.first == data.first)
            {
                //插入失败
                return false;
            }
            //3、如果有，且key不同则利用哈希冲突解决方法解决哈希冲突
            ++index;
            if(index == _ht.size())
            {
                index = 0;
            }
        }
        //元素插入
        _ht[index]._data = data;
        _ht[index]._state = EXIST;
        ++_size;
        return true;
    }
    //检查容量，负载因子超过阈值则扩容
    void checkCapacity()
    {
        //这里选取负载因子大于等于0.8扩容
        if(_ht.size() == 0 || _size * 10 / _ht.size() >= 8)
        {
            //增容
            int newC = _ht.size() == 0 ? 10 : 2 * _ht.size();
            HashTable<K, V> newHt(newC);
            //旧元素插入到新表
            for(int i = 0; i < _ht.size(); i++)
            {
                if(_ht[i]._state == EXIST)
                {
                    newHt.Insert(_ht[i]._data);
                }
            }
            //_ht = newHt._ht;深拷贝，太慢了，直接交换值比较快
            std::swap(_ht, newHt._ht);
        }
    }
    //搜索
    Node* Find(const K& key)
    {
        int index = key % _ht.size();
        while(_ht[index]._state != EMPTY)
        {
            if(_ht[index]._state == EXIST)
            {
                if(_ht[index]._data.first == key)
                {
                    return &_ht[index];
                }
            }
            index++;
            if(index == _ht.size())
            {
                index = 0;
            }
        }
        return nullptr;
    }
    //删除
    bool Erase(const K& key)
    {
        Node* pos = find(key);
        if(pos)
        {
            pos->_state = DELETE;
            --_size;
            return true;
        }
        return false;
    }
private:
    //散列表
    std::vector<Node> _ht;
    size_t _size;
};