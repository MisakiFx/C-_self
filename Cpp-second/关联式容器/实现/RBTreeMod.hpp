#pragma once
#include <iostream>
#include <utility>
//为了方便封装进行的修改版本的红黑树
enum Color
{
    RED,
    BLACK
};
template<class V>
struct RBTNode
{
    RBTNode(const V& data = V())
        :_data(data)
        ,_left(nullptr)
        ,_right(nullptr)
        ,_parent(nullptr)
        ,_color(RED)
    {
    }
    V _data;
    RBTNode<V>* _left;
    RBTNode<V>* _right;
    RBTNode<V>* _parent;
    Color _color;
};

//每个容器都有自己的迭代器，我们的Map/Set也必须有！
//在这里封装实现迭代器，Map/Set结构都是一致的，所以是现在RBTree的头文件中
template<class V>
class _RBTreeIterator
{
    //封装红黑树的结点
    typedef RBTNode<V> Node;
    typedef _RBTreeIterator<V> Self;
public:
    _RBTreeIterator(Node* node)
        :_node(node)
    {
    }
    V& operator*()
    {
        return _node->_data;
    }
    V* operator->()
    {
        return &_node->_data;
    }
    bool operator!=(const Self& it)
    {
        return _node != it._node;
    }
    bool operator==(const Self& it)
    {
        return _node == it._node;
    }
    //我们之前更改红黑树的结构使其变成带头的就是为这里迭代器的遍历做铺垫
    //1、_node->_right存在，走到右子树的最左结点
    //2、_node->_right不存在，向上回溯，只要_node == parent->_right就继续向上回溯，不满足条件则停止回溯，更新_node的值为parent
    Self& operator++()
    {
        if(_node->_right)
        {
            //找到右子树最左结点
            _node = _node->_right;
            while(_node->_left)
            {
                _node = _node->_left;
            }
        }
        else
        {
            Node* parent = _node->_parent;
            while(_node == parent->_right)
            {
                _node = parent;
                parent = parent->_parent;
            }
            //这个判断是为了避免树中没有右子树导致死循环的情况
            if(_node->_right != parent)
            {
                _node = parent;
            }
        }
        return *this;
    }
    //1、_node->_left存在，找左子树的最有结点
    //2、_node->_left不存在，只要_node != parent->_right，向上回溯，条件不满足则更新_node为parent
    Self& operator--()
    {
        if(_node->_left)
        {
            _node = _node->_left;
            while(_node->_right)
            {
                _node = _node->_right;
            }
        }
        else
        {
            Node* parent = _node->_parent;
            while(_node != parent->_right)
            {
                _node = parent;
                parent = parent->_parent;
            }
            _node = parent;
        }
        return *this;
    }
private:
    Node* _node;
};
//此时的结构仿照STL中的内容，K依然代表Key，而V代表节点中data的类型
//如果是map则V->std::pair<K, V>，如果是set则V->K
//这样实现的原因是为了方便红黑树更为灵活的可以分别实现map和set
template<class K, class V, class KeyOfValue>
class RBTree
{
    typedef RBTNode<V> Node;
public:
    typedef _RBTreeIterator<V> iterator;
    //中序遍历的头即树中的最左结点
    iterator begin()
    {
        return iterator(_header->_left);
    }
    //尾注意是它本身
    iterator end()
    {
        return iterator(_header);
    }
    RBTree(const V& data = V())
        :_header(new Node(data))
    {
        _header->_left = _header;
        _header->_right = _header;
        _header->_parent = nullptr;
    }
    std::pair<iterator, bool> Insert(const V& data)
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
            return std::make_pair(iterator(root), true);
        }
        Node* cur = _header->_parent;
        Node* parent = _header;
        KeyOfValue kov;
        while(cur)
        {
            //修改
            if(kov(cur->_data) < kov(data))
            {
                parent = cur;
                cur = cur->_right;
            }
            else if(kov(cur->_data) > kov(data))
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                //return false;
                return std::make_pair(iterator(cur), false);
            }
        }
        cur = new Node(data);
        if(kov(parent->_data) < kov(data))
        {
            parent->_right = cur;
        }
        else
        {
            parent->_left = cur;
        }
        cur->_parent = parent;
        Node* newNode = cur;
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
        //return true;
        return std::make_pair(iterator(newNode), true);
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
//void TestRBTree()
//{
//    RBTree<int, int> rbt;
//    rbt.Insert(std::make_pair(1, 1));
//    rbt.Insert(std::make_pair(10, 1));
//    rbt.Insert(std::make_pair(2, 1));
//    rbt.Insert(std::make_pair(5, 1));
//    rbt.Insert(std::make_pair(3, 1));
//    rbt.Insert(std::make_pair(4, 1));
//    rbt.Insert(std::make_pair(7, 1));
//    rbt.Inorder();
//    std::cout << std::endl;
//    //验证
//    std::cout << (rbt.IsRBTree()) << std::endl;
//}