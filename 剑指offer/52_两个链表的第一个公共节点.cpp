#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    int GetLengthOfList(ListNode* pHead)
    {
        ListNode* temp = pHead;
        int length = 0;
        while(temp != nullptr)
        {
            length++;
            temp = temp->next;
        }
        return length;
    }
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) 
    {
        int length1 = GetLengthOfList(pHead1);
        int length2 = GetLengthOfList(pHead2);
        ListNode* longList = pHead1;
        ListNode* shortList = pHead2;
        int lengthDip = length1 - length2;
        if(length1 < length2)
        {
            longList = pHead2;
            shortList = pHead1;
            lengthDip = length2 - length1;
        }
        while(lengthDip > 0)
        {
            longList = longList->next;
            lengthDip--;
        }
        while((longList != nullptr) && (shortList != nullptr) && (longList != shortList))
        {
            longList = longList->next;
            shortList = shortList->next;
        }
        return longList;
    }
};