#include <iostream>
#include <set>
//template <class T,                   // value类型
//          class Compare = less<T>,   // 比较器
//          class Alloc = allocator<T> // 空间配置器
//          >
//class set;
//set(const Compare &comp = Compare(), const Allocator & = Allocator());                                         //构造空的set
//set(InputIterator ﬁrst, InputIterator last, const Compare &comp = Compare(), const Allocator & = Allocator()); //用[ﬁrst, last)区间 中的元素构造set
//set(const set<Key, Compare, Allocator> &x);                                                                    //set的拷贝构造
//iterator begin();                       //返回set中起始位置元素的迭代器
//iterator end();                         //返回set中最后一个元素后面的迭代器
//const_iterator cbegin() const;          //返回set中起始位置元素的const迭代器
//const_iterator cend() const;            //返回set中最后一个元素后面的const迭代器
//reverse_iterator rbegin();              //返回set第一个元素的反向迭代器，即end
//reverse_iterator rend();                //返回set最后一个元素下一个位置的反向迭代器，即 rbegin
//const_reverse_iterator crbegin() const; //返回set第一个元素的反向const迭代器，即cend
//const_reverse_iterator crend() const;   //返回set最后一个元素下一个位置的反向const迭代器， 即crbegin

//bool empty() const;                                      //检测set是否为空，空返回true，否则返回true
//size_type size() const;                                  //返回set中有效元素的个数
//pair<iterator, bool> insert(const value_type &x);        //在set中插入元素x，实际插入的是<x, x>构成的键值对， 如果插入成功，返回<该元素在set中的位置，true>,如果 插入失败，说明x在set中已经存在，返回<x在set中的位 置，false>
//iterator insert(iterator position, const value_type &x); //在set的position位置插入x，实际插入的是<x, x>构成的 键值对，注意：position位置只是参考，x最终不一定在该 位置
//template <class InputIterator>
//void insert(InputIterator ﬁrst, InputIterator last); //在set中插入[ﬁrst, last)区间中的元素
//void erase(iterator position);                       //删除set中position位置上的元素
//size_type erase(const key_type &x);                  //删除set中值为x的元素，返回删除的元素的个数
//void erase(iterator ﬁrst, iterator last);            //删除set中[ﬁrst, last)区间中的元素
//void swap(set<Key, Compare, Allocator> &st);         //交换set中的元素
//void clear();                                        //将set中的元素清空
//iterator ﬁnd(const key_type &x) const;               //返回set中值为x的元素的位置
//size_type count(const key_type &x) const;            //返回set中值为x的元素的个数

int main()
{
    std::set<int> set;
    set.insert(20);
    set.insert(10);
    for(auto e : set)
    {
        std::cout << e << std::endl;
    }
}