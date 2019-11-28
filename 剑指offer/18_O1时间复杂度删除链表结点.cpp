#include <iostream>

template<class T>
struct ListNode
{
    ListNode()
        :_data(T())
        ,_next(nullptr)
    {
    }
    T _data;            //值域
    ListNode* _next;    //地址域
};

//不带头单向不循环链表
template<class T>
class List
{
public:
    List()
        :_head(nullptr)
    {
    }
    //尾插
    void Push_Back(const T& data)
    {
        ListNode<T>* node = new ListNode<T>;
        node->_data = data;
        node->_next = nullptr;
        if(_head == nullptr)
        {
            _head = node;
            return;
        }
        ListNode<T>* head = _head;
        while(head->_next)
        {
            head = head->_next;
        }
        head->_next = node;
    }
    //删除，要求O1的时间复杂度
    //接口是给一个肯定在链表中存在的结点的指针
    //将后一个结点覆盖要删除的结点，删除后一个结点
    //如果不存在后一个结点则要遍历整个链表，常规解法
    //如果只有一个结点要注意将头结点置空
    void Erase(ListNode<T>* node)
    {
        if(_head == nullptr || node == nullptr)
        {
            return;
        }
        if(node->_next != nullptr)
        {
            ListNode<T>* del = node->_next;
            node->_data = del->_data;
            node->_next = del->_next;
            delete del;
            del = nullptr;
        }
        else if(_head == node)
        {
            delete node;
            node = nullptr;
            _head = nullptr;
        }
        else 
        {
            ListNode<T>* head = _head;
            while(head != nullptr)
            {
                if(head->_next == node)
                {
                    head->_next = head->_next->_next;
                    delete node;
                    node = nullptr;
                    break;
                }
                head = head->_next;
            }
        }
    }
    ListNode<T>* Find(const T& data)
    {
        ListNode<T>* head = _head;
        while(head)
        {
            if(head->_data == data)
            {
                break;
            }
            head = head->_next;
        }
        return head;
    }
    void Print()
    {
        ListNode<T>* head = _head;
        while(head != nullptr)
        {
            std::cout << head->_data << " ";
            head = head->_next;
        }
        std::cout << std::endl;
    }
private:
    ListNode<T>* _head;
};

int main()
{
    List<int> list;
    list.Push_Back(1);
    //list.Push_Back(2);
    //list.Push_Back(3);
    //list.Push_Back(4);
    list.Print();
    ListNode<int>* node = list.Find(1);
    if(node != nullptr)
    {
        list.Erase(node);
    }
    list.Print();
}