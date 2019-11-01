#include "RBTreeMod.hpp"
template<class K, class V>
class Map
{
    //为了让红黑树可以根据调用它的不同类型得以确定比较条件
    //我们这里用内部类创建一个反函数用域返回当前结构下的Key值
    struct MapKeyOfValue
    {
        const K& operator()(const std::pair<K, V>& data)
        {
            return data.first;
        }
    };
public:
    //这里为了能够动态识别这是一个类型要在前面加上typename关键字
    typedef typename RBTree<K, std::pair<K, V>, MapKeyOfValue>::iterator iterator;
    std::pair<iterator, bool> Insert(const std::pair<K, V>& data)
    {
       return  _rbt.Insert(data);
    }

    //实现迭代器
    iterator begin()
    {
        return _rbt.begin();
    }

    iterator end()
    {
        return _rbt.end();
    }
    
    V& operator[](const K& key)
    {
        std::pair<iterator, bool> ret = _rbt.Insert(std::make_pair(key, V()));
        return ret.first->second;
    }
private:
    RBTree<K, std::pair<K, V>, MapKeyOfValue> _rbt;
};