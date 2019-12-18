#include <iostream>

//二叉链结构
template<class T>
struct BinaryTreeNode
{
    BinaryTreeNode(const T& data = T())
        :_data(data)
        ,_left(nullptr)
        ,_right(nullptr)
    {}
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
    {}
    BinaryTree(const std::string& preOrder)
    {
        _head = CreateBPreOrder(preOrder, 0);
    }
private:
    BinaryTreeNode<T> CreateBPreOrder(const std::string& preOrder, int i)
    {
        if(preOrder[i] != '#')
        {
            BinaryTreeNode<T>* root = new BinaryTreeNode<T>(preOrder[i] - '0');
            root->_left = CreateBPreOrder(preOrder, ++i);
            root->_right = CreateBPreOrder(preOrder, ++i);
            return root;
        }
        else 
        {
            return nullptr;
        }
    }
private:
    BinaryTreeNode<T>* _head;           //与链表一样存储一个头结点即可
    size_t _size;                   //节点个数
};