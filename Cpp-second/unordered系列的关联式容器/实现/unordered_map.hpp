#pragma once
#include "hash_bucket.hpp"
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
    bool Insert(const std::pair<K, V>& data)
    {
        return _ht.Insert(data);
    }
private:
    HashTable<K, std::pair<K, V>, MapKeyOfValue> _ht;
};