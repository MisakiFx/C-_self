#include <iostream>
using namespace std;
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
class Solution {
public:
    void CloneNewList(RandomListNode* pHead)
    {
        RandomListNode* node = pHead;
        while(node != nullptr)
        {
            RandomListNode* newNode = new RandomListNode(node->label);
            newNode->next = node->next;
            node->next = newNode;
            node = newNode->next;
        }
    }
    void CloneRandomPtr(RandomListNode* pHead)
    {
        RandomListNode* node = pHead;
        while(node != nullptr)
        {
            RandomListNode* cloneNode = node->next;
            if(node->random != nullptr)
            {
                cloneNode->random = node->random->next;
            }
            node = cloneNode->next;
        }
    }
    RandomListNode* ResoveList(RandomListNode* pHead)
    {
        RandomListNode* node = pHead;
        RandomListNode* newCloneHead = nullptr;
        RandomListNode* newCloneNode = nullptr;
        if(node != nullptr)
        {
            newCloneHead = node->next;
            newCloneNode = node->next;
            node->next = newCloneNode->next;
            node = node->next;
        }
        while(node != nullptr)
        {
            newCloneNode->next = node->next;
            newCloneNode = newCloneNode->next;
            node->next = newCloneNode->next;
            node = node->next;
        }
        return newCloneHead;
    }
    RandomListNode* Clone(RandomListNode* pHead)
    {
        //1、在旧链表每个节点后复制新结点组成新链表
        CloneNewList(pHead);
        //2、克隆新链表中每个结点的随机结点指针
        CloneRandomPtr(pHead);
        //3、分离旧链表与新链表
        RandomListNode* newCloneHead = ResoveList(pHead);
        return newCloneHead;
    }
};