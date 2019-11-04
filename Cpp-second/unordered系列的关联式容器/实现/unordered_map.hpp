#pragma once
#include "hash_bucketMod.hpp"
template<class K, class V>
class Unordered_Map
{
    struct MapKeyOfValue
    {
        const K& operator()(const std::pair<K, V>& data)
        {
            return data.first;
        }
    };
public:
    typedef typename HashTable<K, std::pair<K, V>, MapKeyOfValue>::iterator iterator;
    iterator begin()
    {
        return _ht.begin();
    }
    iterator end()
    {
        return _ht.end();
    }
    std::pair<iterator, bool> Insert(const std::pair<K, V>& data)
    {
        return _ht.Insert(data);
    }
    V& operator[](const K& key)
    {
        return (_ht.Insert(std::make_pair(key, V())).first)->second;
    }
private:
    HashTable<K, std::pair<K, V>, MapKeyOfValue> _ht;
};