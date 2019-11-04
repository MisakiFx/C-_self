//#include "hash.hpp"

#include "unordered_map.hpp"
#include "unordered_set.hpp"
void test3()
{
    Unordered_Map<int, int> umap;
    umap.Insert(std::make_pair(1, 1));
    umap.Insert(std::make_pair(5, 5));
    umap.Insert(std::make_pair(6, 6));
    umap.Insert(std::make_pair(9, 9));
    for(auto e : umap)
    {
        std::cout << e.first << " " << e.second << std::endl;
    }
    umap[6] = 11;
    umap[10] = 10;
    umap[25] = 1;
    std::cout << std::endl;
    for (auto e : umap)
    {
        std::cout << e.first << " " << e.second << std::endl;
    }
    Unordered_set<int> uset;
    uset.Insert(1);
    uset.Insert(5);
    uset.Insert(6);
    uset.Insert(9);
    std::cout << std::endl;
    for (auto e : uset)
    {
        std::cout << e << std::endl;
    }
}
//void test1()
//{
//    HashTable<int, int> ht;
//    ht.Insert(std::make_pair(5, 5));
//    ht.Insert(std::make_pair(1, 1));
//    ht.Insert(std::make_pair(0, 0));
//    ht.Insert(std::make_pair(10, 10));
//    ht.Insert(std::make_pair(30, 30));
//    ht.Insert(std::make_pair(32, 32));
//    ht.Insert(std::make_pair(8, 8));
//    ht.Insert(std::make_pair(110, 110));
//    ht.Insert(std::make_pair(23, 23));
//    ht.Insert(std::make_pair(24, 23));
//    ht.Insert(std::make_pair(25, 23));
//    ht.Insert(std::make_pair(26, 23));
//    HashNode<int, int>* node =  ht.Find(32);
//    if(node != nullptr)
//    {
//        std::cout << (node->_data.first) << " " << node->_data.second;
//    }
//    else
//    {
//        std::cout << "nullptr" << std::endl;
//    }
//    std::cout << std::endl;
//    node =  ht.Find(110);
//    if(node != nullptr)
//    {
//        std::cout << (node->_data.first) << " " << node->_data.second;
//    }
//    else
//    {
//        std::cout << "nullptr" << std::endl;
//    }
//    
//}
//void test2()
//{
//    HashTable<int, int> ht;
//    ht.Insert(std::make_pair(1, 1));
//    ht.Insert(std::make_pair(11, 11));
//    ht.Insert(std::make_pair(12, 12));
//    ht.Insert(std::make_pair(2, 2));
//    ht.Insert(std::make_pair(10, 10));
//    ht.Insert(std::make_pair(2, 2));
//    ht.Insert(std::make_pair(3, 2));
//    ht.Insert(std::make_pair(4, 2));
//    //ht.Insert(std::make_pair(5, 2));
//    //ht.Insert(std::make_pair(6, 2));
//    ht.Erase(11);
//    ht.Erase(2);
//}
int main()
{
    test3();
}