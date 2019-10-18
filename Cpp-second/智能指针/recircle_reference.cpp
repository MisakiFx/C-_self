#include <iostream>
#include <memory>
//链表节点
struct ListNode
{
    //ListNode* _next;
    //ListNode* _prev;
    //统一交给智能指针管理，也方便后面链表节点之间互相连接
    //std::shared_ptr<ListNode> _next;
    //std::shared_ptr<ListNode> _prev;
    std::weak_ptr<ListNode> _next;
    std::weak_ptr<ListNode> _prev;
    int _data;
    ~ListNode()
    {
        std::cout << "destroy" << std::endl;
    }
};
int main()
{
    //ListNode* node1 = new ListNode;
    //ListNode* node2 = new ListNode;
    //为了防止抛异常无法释放空间，将其交给智能指针管理
    std::shared_ptr<ListNode> node1(new ListNode);
    std::shared_ptr<ListNode> node2(new ListNode);
    node1->_next = node2;
    node2->_prev = node1;
    //异常抛出操作
    //...
    //delete node1;
    //delete node2;
    std::cout << "program will over" << std::endl;
}