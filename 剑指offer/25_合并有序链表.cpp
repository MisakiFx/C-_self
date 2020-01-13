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
    //迭代版本
    ListNode* Merge1(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == nullptr)
        {
            return pHead2;
        }
        if(pHead2 == nullptr)
        {
            return pHead1;
        }
        ListNode* newHead = nullptr;
        ListNode* newHeadTemp = nullptr;
        while(pHead1 != nullptr || pHead2 != nullptr)
        {
            if(pHead1 == nullptr)
            {
                newHeadTemp->next = pHead2;
                break;
            }
            if(pHead2 == nullptr)
            {
                newHeadTemp->next = pHead1;
                break;
            }
            if(pHead1->val <= pHead2->val)
            {
                if(newHead == nullptr)
                {
                    newHead = pHead1;
                    newHeadTemp = newHead;
                }
                else
                {
                    newHeadTemp->next = pHead1;
                    newHeadTemp = newHeadTemp->next;
                }
                pHead1 = pHead1->next;
            }
            else if(pHead1->val > pHead2->val)
            {
                if(newHead == nullptr)
                {
                    newHead = pHead2;
                    newHeadTemp = newHead;
                }
                else
                {
                    newHeadTemp->next = pHead2;
                    newHeadTemp = newHeadTemp->next;
                }
                pHead2 = pHead2->next;
            }
        }
        return newHead;
    }
};
    //非递归版本
    ListNode* Merge2(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == nullptr)
        {
            return pHead2;
        }
        if(pHead2 == nullptr)
        {
            return pHead1;
        }
        ListNode* newHead = nullptr;
        if(pHead1->val <= pHead2->val)
        {
            newHead = pHead1;
            newHead->next = Merge(pHead1->next, pHead2);
        }
        if(pHead1->val > pHead2->val)
        {
            newHead = pHead2;
            newHead->next = Merge(pHead1, pHead2->next);
        }
        return newHead;
    }
};