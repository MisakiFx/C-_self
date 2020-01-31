#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
    {
        vector<int> res;
        if(k <= 0 || input.size() <= 0 || input.size() < k)
        {
            return res;
        }
        res.resize(k);
        priority_queue<int> priQue;
        for(const auto& e : input)
        {
            if(priQue.size() < k)
            {
                priQue.push(e);
                continue;
            }
            if(priQue.top() > e)
            {
                priQue.pop();
                priQue.push(e);
            }
        }
        for(int i = k - 1; i >= 0; i--)
        {
            res[i] = priQue.top();
            priQue.pop();
        }
        return res;
    }
};