//#include "BSTree.hpp"
//#include "AVLTree.hpp"
//#include "RBTree.hpp"
#include "Map.hpp"
#include "Set.hpp"
void TestMapSet()
{
    Map<int, int> M;
    M.Insert(std::make_pair(10, 1));
    M.Insert(std::make_pair(3, 1));
    M.Insert(std::make_pair(9, 1));
    M.Insert(std::make_pair(2, 1));
    M.Insert(std::make_pair(1, 1));
    for(auto e : M)
    {
        std::cout << e.first << " " << e.second << std::endl;
    }
    M[1] = 100;
    M[500] = 50;
    std::cout << std::endl;
    for(auto e : M)
    {
        std::cout << e.first << " " << e.second << std::endl;
    }
    //Set<int> S;
    //S.Insert(1);
    //S.Insert(3);
    //S.Insert(5);
    //S.Insert(6);
    //S.Insert(2);
    //S.Insert(6);
    //std::cout << std::endl;
    //for(auto e : S)
    //{
    //    std::cout << e << " ";
    //}
}
int main()
{
    //TestBsTree1();
    //TestAVLTree()m
    //TestRBTree();
    TestMapSet();
}