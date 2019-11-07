#include <iostream>
#include <vector>
#include <string>
#include "BitSet.hpp"
struct HFun1
{
    size_t operator()(const std::string& str)
    {
        size_t hash = 0;
        for(auto& ch : str)
        {
            hash = hash * 131 + ch;
        }
        return hash;
    }
};
struct HFun2
{
    size_t operator()(const std::string& str)
    {
        size_t hash = 0;
        for(auto& ch : str)
        {
            hash = hash * 65599 + ch;
        }
        return hash;
    }
};
struct HFun3
{
    size_t operator()(const std::string& str)
    {
        size_t hash = 0;
        size_t magic = 63689;
        for(auto& ch : str)
        {
            hash = hash * magic + ch;
            magic *= 378551;
        }
        return hash;
    }
};
//HFun为3个自定义的哈希函数
template<class T, class HFun1, class HFun2, class HFun3>
class BloomFilter
{
public:
    //k = (m / n) * ln2
    //k:哈希函数数量
    //m:位图大小
    //n:元素个数
    //m = k * n / ln2
    //number表示元素个数，布隆这里不用元素最大上限作为位图的大小，因为可能会造成大量数据浪费
    //这里利用二次哈希，节省空间
    BloomFilter(size_t number)
        :_bitCount(5 * number)
        ,_bs(_bitCount)
    {
    }
    void Set(const T& data)
    {
        int index1 = HFun1()(data) % _bitCount;
        int index2 = HFun2()(data) % _bitCount;
        int index3 = HFun3()(data) % _bitCount;
        _bs.Set(index1);
        _bs.Set(index2);
        _bs.Set(index3);
    }
    bool Find(const T& data)
    {
        int index1 = HFun1()(data) % _bitCount;
        int index2 = HFun2()(data) % _bitCount;
        int index3 = HFun3()(data) % _bitCount;
        if(!_bs.Find(index1) || !_bs.Find(index2) || !_bs.Find(index3))
        {
            return false;
        }
        return true;//可能会有误判
    }
    //布隆为了防止误判不提供删除操作

private:
    BitSet _bs;
    size_t _bitCount;
};
int main()
{
    BloomFilter<std::string, HFun1, HFun2, HFun3> bf(1000);
    std::string str1 = "https://misakifx.github.io/";
    std::string str2 = "https://blog.csdn.net/qq_41669298";
    std::string str3 = "https://space.bilibili.com/14406161/#/fans/follow";
    std::string str4 = "https://space.bilibili.com/#/fans/follow";
    std::string str5 = "https://space.bilibili.com/4406161/#/fans/follow";
    std::string str6 = "https://space.bilibili.com/146161/#/fans/follow";
    bf.Set(str1);
    bf.Set(str2);
    bf.Set(str3);
    bool ret = bf.Find(str1);
    std::cout << ret << std::endl;
    ret = bf.Find(str2);
    std::cout << ret << std::endl;
    ret = bf.Find(str3);
    std::cout << ret << std::endl;
    ret = bf.Find(str4);
    std::cout << ret << std::endl;
    ret = bf.Find(str5);
    std::cout << ret << std::endl;
    ret = bf.Find(str6);
    std::cout << ret << std::endl;
}