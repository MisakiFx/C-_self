#pragma once
#include <iostream>
#include <utility>
#include <assert.h>
//结点
template<class K, class V>
struct AVLTreeNode
{
    AVLTreeNode(const std::pair<K, V>& kv)
        :_kv(kv)
        ,_left(nullptr)
        ,_right(nullptr)
        ,_parent(nullptr)
        ,_bf(0)
    {}
    std::pair<K, V> _kv;
    AVLTreeNode<K, V>* _left;
    AVLTreeNode<K, V>* _right;
    AVLTreeNode<K, V>* _parent;
    int _bf; //平衡因子 = 右子树高度 - 左子树高度
};
template<class K, class V>
class AVLTree
{
    typedef AVLTreeNode<K, V> Node;
public:
    bool Insert(const std::pair<K, V>& kv)
    {
        //插入结点，思路与BSTree一致，额外需要加入更新平衡因子
        //插入的为第一个结点
        if(_root == nullptr)
        {
            _root = new Node(kv);
            _root->_bf = 0;
            return true;
        }
        Node* cur = _root;
        Node* parent = nullptr;
        while(cur)
        {
            if(cur->_kv.first < kv.first)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if(cur->_kv.first > kv.first)
            {
                parent = cur;
                cut = cur->_left;
            }
            else
            {
                return false;
            }
        }
        cur = new Node(kv);
        if(parent->_kv.first < kv.first)
        {
            cur->_parent = parent;
        }
        else
        {
            cur->_parent = parent;
            parent->_left = cur;
        }
        //调整平衡
        //1、更新平衡因子
        //新增在左，父亲bf - 1，新增在右，父亲bf + 1
        //如果父亲的更新后|bf|:
        //|bf| == 0 || 父结点为空时停止更新
        //因为bf更新为0则说明父亲所在子树此时的高度并未发生变化，父结点为空说明此时更新完了整棵树
        //|bf| == 2也停止更新，及时调整，旋转处理
        //|bf| == 1则继续向上更新
        while(parent)
        {
            if(cur == parent->_right)
            {
                parent->_bf++;
            }
            else
            {
                parent->_bf--;
            }
            //|bf| == 0
            if(parent->_bf == 0)//更新完成
            {
                break;
            }
            else if(abs(parent->_bf) == 1)//继续向上更新
            {
                cur = parent;
                parent = parent->_parent;
            }
            else if(abs(parent->_bf) == 2)//及时旋转调整
            {
                
            }
            else//在三种情况外，说明出现问题
            {
                assert(flase);
            }
            
            
        }
        return ture;
    }
private:
    Node* _root = nullptr;
};