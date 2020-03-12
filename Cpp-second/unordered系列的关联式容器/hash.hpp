#include <iostream>
#include <vector>
#include <utility>
template<class K, class V>
struct HashNode
{
    //为了方便我们找到对应映射，我们散列表中结点往往是一个K-V结构的
    std::pair<K, V> _data;
};
template<class K, class V>
class HashTable
{
public:
    typedef HashNode<K, V> Node;
    HashTable(const size_t n = 10)
        :_size(0)
    {
        _ht.resize(n);
    }
    bool Insert(const std::pair<K, V>& data)
    {
        //计算索引，进行散列，这里采用除留余数法
        int index = data.first % _ht.size();
        _ht[index]
    }
private:
    //散列表
    std::vector<Node> _ht;
    size_t _size;
};