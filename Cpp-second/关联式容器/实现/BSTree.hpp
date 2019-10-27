#pragma once
#include <iostream>
#include <utility>
template<class K, class V>
//结点
struct BSTreeNode
{
    BSTreeNode(const std::pair<K, V>& kv)
        :_left(nullptr)
        ,_right(nullptr)
        //,_parent(nullptr)
        ,_kv(kv)
    {

    }
    std::pair<K, V> _kv;
    BSTreeNode<K, V>* _left;
    BSTreeNode<K, V>* _right;
    //BSTreeNode<K, V>* _parent;
};
//二叉搜索树
template<class K, class V>
class BSTree
{
    typedef BSTreeNode<K, V> Node;
public:
    BSTree()
        :_root(nullptr)
    {
    }
    //插入结点
    bool Insert(const std::pair<K, V>& kv)
    {
        //插入第一个结点
        if(_root == nullptr)
        {
            _root = new Node(kv);
            return true;
        }
        Node* parent = nullptr;
        Node* cur = _root;
        while(cur)
        {
            //比当前结点小，插在左边
            if(cur->_kv.first > kv.first)
            {
                //记录上一个结点
                parent = cur;
                cur = cur->_left;
            }
            //比当前结点大，插在右边
            else if(cur->_kv.first < kv.first)
            {
                //记录上一个结点
                parent = cur;
                cur = cur->_right;
            }
            //相等则说明已存在，插入失败
            else
            {
                return false;
            }
        }
        cur = new Node(kv);
        //cur->_parent = parent;
        if(parent->_kv.first < kv.first)
        {
            parent->_right = cur;
        }
        else
        {
            parent->_left = cur;
        }
        return true;
    }
    //查找，返回结点的指针
    Node* Find(const K& key)
    {
        Node* cur = _root;
        while(cur)
        {
            if(cur->_kv.first < key)
            {
                cur = cur->_right;
            }
            else if(cur->_kv.first > key)
            {
                cur = cur->_left;
            }
            else
            {
                return cur;
            }
        }
        return nullptr;
    }
    //删除结点
    bool Remove(const K& key)
    {
        //1、叶子结点，直接删除，父结点对应指针指向空
        //2、有一个孩子，如果左为空，父结点对应指针指向右，如果右为空，父结点对应指针指向左
        //3、找右子树最左结点或左子树最右结点替代他，然后删除替代结点
        Node* cur = _root;
        Node* parent = nullptr;
        while(cur)
        {
            if(cur->_kv.first < key)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if(cur->_kv.first > key)
            {
                parent = cur;
                cur = cur->_left;
            }
            //找到相等可以删除此结点了
            else
            {
                //只有0/1个孩子
                //对于只有一个孩子或者没有孩子的结点来说要删除的结点就是cur
                Node* del = cur;
                //要删除的结点左孩子为空
                if(cur->_left == nullptr)
                {
                    
                    //如果要删除的是根结点，父结点为空
                    if(parent == nullptr)
                    {
                        //直接改变根
                        _root = cur->_right;
                        return true;
                    }
                    //判断要删除的结点是其父结点的左孩子还是右孩子
                    if(cur == parent->_left)
                    {
                        parent->_left = cur->_right;
                    }
                    else
                    {
                        parent->_right = cur->_right;
                    }
                }
                //要删除的结点右孩子为空
                else if(cur->_right == nullptr)
                {
                    //如果要删除的是根结点，父结点为空
                    if(parent == nullptr)
                    {
                        _root = cur->_left;
                        return true;
                    }
                    //判断要删除的结点是其父结点的左孩子还是右孩子
                    if(cur == parent->_left)
                    {
                        parent->_left = cur->_left;
                    }
                    else
                    {
                        parent->_right = cur->_left;
                    }
                }
                //有两个孩子，找右树的最左结点
                else
                {
                    //找到右树的最左结点和其父结点
                    Node* rpParent = cur;
                    Node* replace = cur->_right;
                    while(replace->_left)
                    {
                        rpParent = replace;
                        replace = replace->_left;
                    }
                    //此时要释放的结点是替代结点
                    del = replace;
                    //找到后开始替换
                    cur->_kv = replace->_kv;
                    //替换结点不一定一定是其父结点的左结点，因此做一次判断
                    if(rpParent->_left == replace)
                    {
                        rpParent->_left = replace->_right;
                    }
                    else
                    {
                        rpParent->_right = replace->_right;
                    }
                    
                }
                //释放结点
                delete del;
                std::cout << "del success" << std::endl;
                return true;
            }
        }
        return false;
    }
    //中序遍历
    void InOrder()
    {
        _InOrder(_root);
        std::cout << std::endl;
    }
private:
    void _InOrder(Node* root)
    {
        if(root == nullptr)
        {
            return;
        }
        _InOrder(root->_left);
        std::cout << root->_kv.first << " ";
        _InOrder(root->_right);
    }
private:
    Node* _root;

};
void TestBsTree1()
{
    BSTree<int, int> tree;
    tree.Insert(std::make_pair(4, 4));
    tree.Insert(std::make_pair(3, 3));
    tree.Insert(std::make_pair(1, 1));
    tree.Insert(std::make_pair(1, 1));
    tree.Insert(std::make_pair(7, 7));
    tree.Insert(std::make_pair(8, 8));
    tree.Insert(std::make_pair(2, 2));
    tree.InOrder();
    tree.Remove(1);
    tree.Remove(3);
    tree.Remove(4);
    tree.Remove(7);
    tree.Remove(8);
    tree.Remove(2);
    tree.Remove(10);
    tree.InOrder();
}