#include <iostream>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr) {
    }
};
class Solution {
public:
    bool IsCircle(ListNode* pHead, ListNode** meet)
    {
        ListNode* ptr1 = pHead, *ptr2 = pHead;
        while(ptr2->next != nullptr)
        {
            if(ptr2->next != nullptr && ptr1->next != nullptr)
            {
                ptr2 = ptr2->next;
                ptr1 = ptr1->next;
            }
            else 
            {
                return false;
            }
            if(ptr2->next != nullptr)
            {
                ptr2 = ptr2->next;
            }
            else 
            {
                return false;
            }
            if(ptr1 == ptr2)
            {
                *meet = ptr1;
                return true;
            }
        }
        return false;
    }
    int Count(ListNode* meet)
    {
        ListNode* temp = meet->next;
        int count = 1;
        while(temp != meet)
        {
            //std::cout << temp->val << std::endl;
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == nullptr)
        {
            return nullptr;
        }
        ListNode* meet = nullptr;
        if(IsCircle(pHead, &meet) == false)
        {
            return nullptr;
        }
        //
        //std::cout << meet->val << std::endl;
        //
        int count = Count(meet);
        //std::cout << count << std::endl;
        ListNode* ptr1 = pHead, *ptr2 = pHead;
        for(int i = 0; i < count; i++)
        {
            ptr2 = ptr2->next;
        }
        while(ptr1 != ptr2)
        {
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }
        return ptr1;
    }
};
void PushBack(ListNode** pHead, int value)
{
    if(*pHead == nullptr)
    {
        ListNode *newNode = new ListNode(value);
        *pHead = newNode;
        return;
    }
    ListNode* temp = *pHead;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    ListNode* newNode = new ListNode(value);
    temp->next = newNode;
    temp = *pHead;
}

int main()
{
    ListNode* pHead = nullptr;
    PushBack(&pHead, 1);
    PushBack(&pHead, 2);
    PushBack(&pHead, 3);
    PushBack(&pHead, 4);
    PushBack(&pHead, 5);
    ListNode* temp = pHead;
    ListNode* temp2 = pHead;
    for(int i = 0; i < 2; i++)
    {
        temp2 = temp2->next;
    }
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = temp2;
    Solution sol;
    temp = sol.EntryNodeOfLoop(pHead);
    std::cout << temp->val << std::endl;
}