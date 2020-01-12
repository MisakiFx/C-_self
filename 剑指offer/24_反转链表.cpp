#include <iostream>
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* ReverseList1(ListNode* pHead) {
        if(pHead == nullptr)
        {
            return nullptr;
        }
        ListNode* reverseHead = pHead;
        ListNode* node = pHead->next;
        while(node != nullptr)
        {
            ListNode* next = node->next;
            node->next = reverseHead;
            reverseHead = node;
            pHead->next = next;
            node = next;
        }
        return reverseHead;
    }
    ListNode* ReverseList2(ListNode* pHead) {
        if(pHead == nullptr)
        {
            return nullptr;
        }
        ListNode* node = pHead;
        ListNode* prev = nullptr;
        ListNode* reverseHead = nullptr;
        while(node != nullptr)
        {
            ListNode* next = node->next;
            if(node->next == nullptr)
            {
                reverseHead = node;
            }
            node->next = prev;
            prev = node;
            node = next;
        }
        return reverseHead;
    }
};