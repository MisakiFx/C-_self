#include "RBTreeMod.hpp"
template<class K>
class Set
{
    struct SetKeyOfValue
    {
        const K& operator()(const K& data)
        {
            return data;
        }
    };
public:
    typedef typename RBTree<K, K, SetKeyOfValue>::iterator iterator;
    std::pair<iterator, bool> Insert(const K& data)
    {
        return _rbt.Insert(data);
    }

    //实现迭代器
    iterator begin()
    {
        return _rbt.begin();
    }

    //实现迭代器
    iterator end()
    {
        return _rbt.end();
    }
    

private:
    RBTree<K, K, SetKeyOfValue> _rbt;
};