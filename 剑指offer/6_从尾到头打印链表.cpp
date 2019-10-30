#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr)
    {
    }
};
class Solution {
public: 
    //用栈来实现
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> temp;
        ListNode* headtemp = head;
        while(headtemp != nullptr)
        {
            temp.push(headtemp->val);
            headtemp = headtemp->next;
        }
        vector<int> res;
        while(!temp.empty())
        {
            res.push_back(temp.top());
            temp.pop();
        }
        return res;
    }
    //用递归来实现
    vector<int> printListFromTailToHead_Recursively(ListNode* head)
    {
        vector<int> arr;
        if(head != nullptr)
        {
            if(head->next != nullptr)
            {
                printListFromTailToHead_Recursively(head->next);
            }
            else
            {
                arr.push_back(head->val);
            }
        }
    }
};
int main()
{
    
}