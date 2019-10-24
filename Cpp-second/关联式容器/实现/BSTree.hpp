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
        ,_parent(nullptr)
        ,_kv(kv)
    {

    }
    std::pair<K, V> _kv;
    BSTreeNode<K, V>* _left;
    BSTreeNode<K, V>* _right;
    BSTreeNode<K, V>* _parent;
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
        if(_root == nullptr)
        {
            _root = new Node(kv);
            return true;
        }
        Node* parent = nullptr;
        Node* cur = _root;
        while(cur)
        {
            //记录上一个结点
            parent = cur;
            //比当前结点小，插在左边
            if(cur->_kv.first > kv.first)
            {
                cur = cur->_left;
            }
            //比当前结点大，插在右边
            else if(cur->_kv.first < kv.first)
            {
                cur = cur->_right;
            }
            //相等则说明已存在，插入失败
            else
            {
                return false;
            }
        }
        cur = new Node(kv);
        cur->_parent = parent;
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
    NOde* Find(const K& key)
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
    tree.Insert(std::make_pair(1, 1));
    tree.Insert(std::make_pair(3, 1));
    tree.Insert(std::make_pair(4, 1));
    tree.Insert(std::make_pair(1, 1));
    tree.Insert(std::make_pair(7, 1));
    tree.Insert(std::make_pair(8, 1));
    tree.Insert(std::make_pair(2, 1));
    tree.InOrder();
}