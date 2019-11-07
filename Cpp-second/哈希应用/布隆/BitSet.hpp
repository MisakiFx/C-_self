#include <iostream>
#include <vector>
class BitSet
{
public:
    //要保证每一个数据都能映射到一个唯一的位置，位图的大小与最大映射数据上限有关
    //因此这里的range代表的是映射的最大数据
    BitSet(size_t range)
    {
        _bs.resize((range >> 5) + 1);
    }
    //存储
    void Set(int num)
    {
        int index = num >> 5;
        int bitIdx = num % 32;
        _bs[index] |= (1 << bitIdx);
    }
    bool Find(int num)
    {
        int index = num >> 5;
        int bitIdx = num % 32;
        return 1 & (_bs[index] >> bitIdx);
    }
    void ReSet(int num)
    {
        int index = num >> 5;
        int bitIdx = num % 32;
        _bs[index] &= (~(1 << bitIdx));
    }
private:
    std::vector<int> _bs;
};