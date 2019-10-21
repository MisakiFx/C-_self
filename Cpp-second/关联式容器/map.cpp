#include <iostream>
#include <string>
#include <map>
//template <class T1, class T2>
//struct pair
//{
//    typedef T1 first_type;
//    typedef T2 second_type;
//    
//    T1 first;
//    T2 second;
//    pair()
//        :first(T1())
//        ,second(T2()) 
//    {}
//    pair(const T1 &a, const T2 &b)
//        :first(a)
//        ,second(b) 
//    {}
//};
//template <class Key,                                  // key的类型
//          class T,                                    // value的类型
//          class Compare = less<Key>,                  // 比较器
//          class Alloc = allocator<pair<const Key, T>> // 空间配置器
//          >
//class map;
//explicit map(const key_compare &comp = key_compare(),
//             const allocator_type &alloc = allocator_type());//创建一个空map
//
//template <class InputIterator>
//map(InputIterator first, InputIterator last,
//    const key_compare &comp = key_compare(),
//    const allocator_type &alloc = allocator_type());//用一个迭代器区间中的数据构造map
//    
//map (const map& x);//拷贝构造
//bool empty() const;                         //检测map中的元素是否为空，是返回true，否则 返回false
//size_type size() const;                     //返回map中有效元素的个数
//mapped_type &operator[](const key_type &k); //返回去key对应的value
//iterator begin();                      //返回第一个元素的位置
//iterator end();                        //返回最后一个元素的下一个位置
//const_iterator begin() const;          //返回第一个元素的const迭代器
//const_iterator end() const;            //返回最后一个元素下一个位置的const迭代器
//reverse_iterator rbegin();             //返回第一个元素位置的反向迭代器即rend
//reverse_iterator rend();               //返回最后一个元素下一个位置的反向迭代器即 rbegin
//const_reverse_iterator rbegin() const; //返回第一个元素位置的const反向迭代器即rend
//const_reverse_iterator rend() const;   //返回最后一元素下一个位置的反向迭代器即rbegin
//pair<iterator, bool> insert(const value_type &x);        //在map中插入键值对x，注意x是一个键值对，返回 值也是键值对：iterator代表新插入元素的位置， bool代表释放插入成功
//iterator insert(iterator position, const value_type &x); //在position位置插入值为x的键值对，返回该键值对 在map中的位置，注意：元素不一定必须插在 position位置，该位置只是一个参考
//template <class InputIterator>
//void insert(InputIterator first, InputIterator last); //在map中插入[ﬁrst, last)区间中的元素
//void erase(iterator position);                        //删除position位置上的元素
//size_type erase(const key_type &x);                   //删除键值为x的元素
//void erase(iterator ﬁrst, iterator last);             //删除[ﬁrst, last)区间中的元素
//void swap(map<Key, T, Compare, Allocator> &mp);       //交换两个map中的元素
//void clear();                                         //将map中的元素清空
//iterator ﬁnd(const key_type &x);                      //在map中插入key为x的元素，找到返回该元素的位 置的迭代器，否则返回end
//const_iterator ﬁnd(const key_type &x) const;          //在map中插入key为x的元素，找到返回该元素的位 置的const迭代器，否则返回cend
//size_type count(const key_type &x) const;             //返回key为x的键值在map中的个数，注意map中 key是唯一的，因此该函数的返回值要么为0，要么 为1，因此也可以用该函数来检测一个key是否在 map中

int main()
{
    std::map<std::string, int> map;//空map
    //访问不存在的key值
    map["1"] = 1;
    map["2"] = 2;
    for(auto e : map)
    {
        std::cout << e.first << " " << e.second << std::endl;
    }
}