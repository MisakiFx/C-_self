#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> sta;
        int pushi = 0, popi = 0;
        while(popi < popV.size())
        {
            if(sta.empty() || sta.top() != popV[popi])
            {
                if(pushi < pushV.size())
                {
                    sta.push(pushV[pushi]);
                    pushi++;
                }
                else 
                {
                    return false;
                }
            }
            else 
            {
                sta.pop();
                popi++;
            }
        }
        return true;
    }
};