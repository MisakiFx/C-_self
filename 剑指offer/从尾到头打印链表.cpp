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
};
int main()
{

}