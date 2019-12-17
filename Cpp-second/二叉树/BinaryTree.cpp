#include <iostream>

//二叉链结构
template<class T>
struct BinaryTreeNode
{
    T _data;
    BinaryTreeNode<T>* _left;
    BinaryTreeNode<T>* _right;
};

template<class T>
class BinaryTree
{
public:
    BinaryTree()
        :_head(nullptr)
        ,_size(0)
    {

    }
    
private:
    BinaryTree<T>* _head;           //与链表一样存储一个头结点即可
    size_t _size;                   //节点个数
};