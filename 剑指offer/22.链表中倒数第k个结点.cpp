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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* ptr1 = pListHead, *ptr2 = pListHead;
        if(k <= 0 || pListHead == nullptr)
        {
            return nullptr;
        }
        for(unsigned int i = 0; i < k - 1; i++)
        {
            if(ptr1->next == nullptr)
            {
                return nullptr;
            }
            ptr1 = ptr1->next;
        }
        while(ptr1->next != nullptr)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr2;
    }
};