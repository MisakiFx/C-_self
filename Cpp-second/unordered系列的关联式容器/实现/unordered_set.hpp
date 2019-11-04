#pragma once
#include "hash_bucketMod.hpp"
template<class K>
class Unordered_set
{
    struct SetKeyOfValue
    {
        const K& operator()(const K& data)
        {
            return data;
        }
    };
public:
    typedef typename HashTable<K, K, SetKeyOfValue>::iterator iterator;
    iterator begin()
    {
        return _ht.begin();
    }
    iterator end()
    {
        return _ht.end();
    }
    std::pair<iterator, bool> Insert(const K& data)
    {
        return _ht.Insert(data);
    }
private:
    HashTable<K, K, SetKeyOfValue> _ht;
};