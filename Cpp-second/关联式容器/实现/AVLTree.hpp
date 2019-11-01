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
                cur = cur->_left;
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
            parent->_right = cur;
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
        //因为bf更新为0则说明当前父亲所在子树此时的高度并未发生变化，父结点为空说明此时更新完了整棵树
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
            else if(abs(parent->_bf) == 2)//不满足AVLTree要求及时旋转调整
            {
                //2、旋转
                if(parent->_bf == 2)
                {
                    if(cur->_bf == 1)
                    {
                        RotateL(parent);
                    }
                    else if(cur->_bf == -1)
                    {
                        RotateRL(parent);
                    }
                }
                else if(parent->_bf == -2)
                {
                    if(cur->_bf == -1)
                    {
                        RotateR(parent);
                    }
                    else if(cur->_bf == 1)
                    {
                        RotateLR(parent);
                    }
                }
                break;//调整完一定要记着break
            }
            else//在三种情况外，说明出现问题
            {
                assert(false);
            }
        }
        return true;
    }
    //左旋
    void RotateL(Node* parent)
    {
        Node* subR = parent->_right;
        Node* subRL = parent->_right->_left;

        parent->_right = subRL;
        if(subRL)
        {
            subRL->_parent = parent;
        }
        subR->_left = parent;
        Node* ppNode = parent->_parent;
        parent->_parent = subR;
        //根
        if(ppNode == nullptr)
        {
            _root = subR;
            subR->_parent = nullptr;
        }
        else
        {
            if(ppNode->_right == parent)
            {
                ppNode->_right = subR;
            }
            else
            {
                ppNode->_left = subR;
            }
            subR->_parent = ppNode;
        }
        //更新平衡因子
        subR->_bf = parent->_bf = 0;
    }
    //右旋
    void RotateR(Node* parent)
    {
        Node* subL = parent->_left;
        Node* subLR = parent->_left->_right;

        parent->_left = subLR;
        if(subLR)//subLR可能会为空，当h == 0时subLR为空
        {
            subLR->_parent = parent;
        }

        subL->_right = parent;//subL不可能为空
        //记录下parent原来的父结点，为了方便parent移动可以找到这棵子树的父结点
        Node* ppNode = parent->_parent;
        parent->_parent = subL;
        //更新这棵子树的新父结点subL与其父结点的连接
        if(ppNode == nullptr)//如果子树的父结点为空则说明parent原本是整棵树的根节点
        {
            _root = subL;
            _root->_parent = nullptr;
        }
        else
        {
            if(ppNode->_right == parent)
            {
                ppNode->_right = subL;
            }
            else
            {
                ppNode->_left = subL;
            }
            subL->_parent = ppNode;
        }
        parent->_bf = subL->_bf = 0;
    }
    //先左旋再右旋
    void RotateLR(Node* parent)
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;
        //保存subRL的平衡因子，之后要根据这个判断parent和subR的平衡因子分别更新为多少
        int bf = subLR->_bf;

        RotateL(parent->_left);
        RotateR(parent);
        //注意这里双旋过后父结点的平衡因子不一定会为0
        if(bf == 0)
        {
            parent->_bf = subLR->_bf = subL->_bf = 0;
        }
        else if(bf == 1)
        {
            subL->_bf = -1;
            parent->_bf = 0;
            subLR->_bf = 0;
        }
        else if(bf == -1)
        {
            parent->_bf = 1;
            subL->_bf = 0;
            subLR->_bf = 0;
        }

    }
    //先右旋再左旋
    void RotateRL(Node* parent)
    {
        Node* subR = parent->_right;
        Node* subRL = subR->_left;
        //保存subRL的平衡因子，之后要根据这个判断parent和subR的平衡因子分别更新为多少
        int bf = subRL->_bf;
        RotateR(parent->_right);
        RotateL(parent);
        //注意这里双旋过后父结点的平衡因子不一定会为0
        //这里三个结点的平衡因子更新要根据新节点到底插在哪里来决定
        if(bf == 0)//此时说明subRL为新增结点
        {
            parent->_bf = subRL->_bf = subR->_bf = 0;
        }
        else if(bf == 1)//此时说明新增节点插在c树上
        {
            subR->_bf = 0;
            parent->_bf = -1;
            subRL->_bf = 0;
        }
        else if(bf == -1)//此时说明新增结点插在b树上
        {
            parent->_bf = 0;
            subR->_bf = 1;
            subRL->_bf = 0;
        }
    }
    //中序
    void InOrder()
    {
        _InOrder(_root);
        std::cout << std::endl;
    }
    //为了判定它是一棵平衡树我们写一个求树高度的函数
    int _Height(Node* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        int leftHeight = _Height(root->_left);
        int rightHeight = _Height(root->_right);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
    //判断这是否是一颗平衡二叉树
    bool IsBalance()
    {
        return _IsBalance(_root);
    }
    bool _IsBalance(Node* root)
    {
        if(root == nullptr)
        {
            return true;
        }
        int leftHeight = _Height(root->_left);
        int rightHeight = _Height(root->_right);
        //也有可能会出现平衡因子更新错误的情况，这里再做二次判断
        if(rightHeight - leftHeight != root->_bf)
        {
            std::cout << root->_kv.first << " is error" << std::endl;
        }
        return (abs(leftHeight - rightHeight) < 2) && _IsBalance(root->_left) && _IsBalance(root->_right);
    }
private:
    void _InOrder(Node* parent)
    {
        if(parent == nullptr)
        {
            return;
        }
        _InOrder(parent->_left);
        std::cout << parent->_kv.first << " ";
        _InOrder(parent->_right);
    }
    Node* _root = nullptr;
};
void TestAVLTree()
{
    AVLTree<int, int> t;
    int a[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
    int b[] = {4, 2, 6, 1, 3, 5, 15, 7, 16, 14};
    for(auto e : b)
    {
        t.Insert(std::make_pair(e, e));
    }
    t.InOrder();
    std::cout << t.IsBalance() << std::endl;
}