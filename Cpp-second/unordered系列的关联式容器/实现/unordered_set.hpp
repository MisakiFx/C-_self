#pragma once
#include "hash_bucket.hpp"
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
    bool Insert(const K& data)
    {
        return _ht.Insert(data);
    }
private:
    HashTable<K, K, SetKeyOfValue> _ht;
};