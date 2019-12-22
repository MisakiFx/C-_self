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
        int i = 0;
        _head = CreateBPreOrder(preOrder, i);
    }
    //前序遍历
    void PreOrder()
    {
        PreOrderCore(_head);
    }
private:
    void PreOrderCore(BinaryTreeNode<T>* root)
    {
        if(root == nullptr)
        {
            std::cout << "#";
            return;
        }
        std::cout << (char)('A' + root->_data);
        PreOrderCore(root->_left);
        PreOrderCore(root->_right);
    }
    BinaryTreeNode<T>* CreateBPreOrder(const std::string& preOrder, int& i)
    {
        if(preOrder[i] != '#')
        {
            BinaryTreeNode<T>* root = new BinaryTreeNode<T>(preOrder[i] - 'A');
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


int main()
{
    BinaryTree<int> tree("ABD##E#H##CF##G##");
    tree.PreOrder();
}