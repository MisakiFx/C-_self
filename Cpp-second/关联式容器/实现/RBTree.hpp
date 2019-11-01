#pragma once
#include <iostream>
#include <utility>
enum Color
{
    RED,
    BLACK
};
template<class K, class V>
struct RBTNode
{
    RBTNode(const std::pair<K, V>& data = std::pair<K, V>())
        :_data(data)
        ,_left(nullptr)
        ,_right(nullptr)
        ,_parent(nullptr)
        ,_color(RED)
    {
    }
    std::pair<K, V> _data;
    RBTNode<K, V>* _left;
    RBTNode<K, V>* _right;
    RBTNode<K, V>* _parent;
    Color _color;
};

template<class K, class V>
class RBTree
{
    typedef RBTNode<K, V> Node;
public:
    RBTree(const std::pair<K, V>& data = std::pair<K, V>())
        :_header(new Node(data))
    {
        _header->_left = _header;
        _header->_right = _header;
        _header->_parent = nullptr;
    }
    bool Insert(const std::pair<K, V>& data)
    {
        //空树，插入的为根结点
        if(_header->_parent == nullptr)
        {
            Node* root = new Node(data);
            //根节点颜色必须为黑色
            root->_color = BLACK;
            _header->_parent = root;
            root->_parent = _header;
            _header->_left = root;
            _header->_right = root;
            return true;
        }
        Node* cur = _header->_parent;
        Node* parent = _header;
        while(cur)
        {
            if(cur->_data.first < data.first)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if(cur->_data.first > data.first)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                return false;
            }
        }
        cur = new Node(data);
        if(parent->_data.first < data.first)
        {
            parent->_right = cur;
        }
        else
        {
            parent->_left = cur;
        }
        cur->_parent = parent;
        //_header->_left = cur;
        //调整：修改颜色，旋转
        while(cur != _header->_parent && cur->_parent->_color == RED)
        {
            Node* parent = cur->_parent;
            Node* gParent = parent->_parent;
            if(gParent->_left == parent)
            {
                Node *uncle = gParent->_right;
                //情况一
                if(uncle && uncle->_color == RED)
                {
                    //更新颜色
                    parent->_color = uncle->_color = BLACK;
                    gParent->_color = RED;
                    //向上继续更新
                    cur = gParent;
                }
                //情况二/三
                else
                {
                    //叔叔不存在或者叔叔为黑色
                    //判断这里是否存在双旋的场景
                    if(cur = parent->_right)
                    {
                        //情况三
                        //此时就是一个折现的形态就需要两次旋转了
                        RotateL(parent);
                        //左旋后，父亲变子，子变父亲，重回情况er
                        std::swap(cur, parent);
                    }
                    else
                    {
                        //情况二
                        RotateR(gParent);
                        //更改颜色
                        parent->_color = BLACK;
                        gParent->_color = RED;
                        //此时这课子树的根为黑色，所以不需要再继续向上调整
                        break;
                    }
                }
            }
            else
            {
                Node* uncle = gParent->_left;
                if(uncle && uncle->_color == RED)
                {
                    parent->_color = uncle->_color = BLACK;
                    gParent->_color = RED;
                    cur = gParent;
                }
                else
                {
                    if(cur == parent->_left)
                    {
                        RotateR(parent);
                        std::swap(cur, parent);
                    }
                    else
                    {
                        RotateL(gParent);
                        parent->_color = BLACK;
                        gParent->_color = RED;
                        break;
                    }
                }
            }
        }
        //根结点的颜色必须为黑色
        _header->_parent->_color = BLACK;
        //更新头节点
        _header->_left = LeftMost();
        _header->_right = RightMost();
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
        if(ppNode == _header)
        {
            _header->_parent = subR;
            subR->_parent = _header;
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
        if(ppNode == _header)//如果子树的父结点为空则说明parent原本是整棵树的根节点
        {
            _header->_parent= subL;
            subL->_parent = _header;
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
    }
    //找到当前树的最左结点
    Node* LeftMost()
    {
        Node* cur = _header->_parent;
        while(cur && cur->_left)
        {
            cur = cur->_left;
        }
        return cur;
    }
    //找到当前树的最有结点
    Node* RightMost()
    {
        Node* cur = _header->_parent;
        while(cur && cur->_right)
        {
            cur = cur->_right;
        }
        return cur;
    }
    //中序遍历
    void Inorder()
    {
        _Inorder(_header->_parent);
    }
    void _Inorder(Node* root)
    {
        if(root == nullptr)
        {
            return;
        }
        _Inorder(root->_left);
        std::cout << root->_data.first << " ";
        _Inorder(root->_right);
    }
    //判断是否是一个红黑树
    bool IsRBTree()
    {
        Node* root = _header->_parent;
        if(root == nullptr)
        {
            return true;
        }
        if(root->_color == RED)
        {
            return false;
        }
        //统计一条路径黑结点的数量
        int blackCount = 0;
        Node* cur = root;
        while(cur)
        {
            if(cur->_color == BLACK)
            {
                blackCount++;
            }
            cur = cur->_left;
        }
        //前序遍历
        return _IsRBTree(root, blackCount, 0);
    }
    bool _IsRBTree(Node* root, int blackCount, int curBlackCount)
    {
        if(root == nullptr)
        {
            if(curBlackCount != blackCount)
            {
                return false;
            }
            return true;
        }
        //统计黑色结点的数量
        if(root->_color == BLACK)
        {
            curBlackCount++;
        }
        //判断是否有红色连续
        if(root->_parent->_color == RED && root->_color == RED)
        {
            return false;
        }
        return _IsRBTree(root->_left, blackCount, curBlackCount) 
        && _IsRBTree(root->_right, blackCount, curBlackCount);
    }
private:
    //Node* _root;
    //这里为了方便后续封装成map/set我们将其结构改造成一棵带头结点的环形树
    //这里的头和环形类似于实现过的带头双向环形链表
    //头节点的右孩子连接最右结点，左孩子连接最左结点，用头指向树真正的根结点
    //相当于这个头结点是倒过来的，和真正的根结点头连着头，连个孩子和最左最右结点构成两个环
    //封装成这种结构都是为了方便我们后续进一步封装，尽量和库中的保持一致
    Node* _header;
};
void TestRBTree()
{
    RBTree<int, int> rbt;
    rbt.Insert(std::make_pair(1, 1));
    rbt.Insert(std::make_pair(10, 1));
    rbt.Insert(std::make_pair(2, 1));
    rbt.Insert(std::make_pair(5, 1));
    rbt.Insert(std::make_pair(3, 1));
    rbt.Insert(std::make_pair(4, 1));
    rbt.Insert(std::make_pair(7, 1));
    rbt.Inorder();
    std::cout << std::endl;
    //验证
    std::cout << (rbt.IsRBTree()) << std::endl;
}