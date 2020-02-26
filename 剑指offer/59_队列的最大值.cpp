#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        if(num.size() < size || size <= 0)
        {
            return res;
        }
        deque<int> index;
        for(int i = 0; i < size; i++)
        {
            while(!index.empty() && num[index.back()] <= num[i])
            {
                index.pop_back();
            }
            index.push_back(i);
        }
        for(int i = size; i < num.size(); i++)
        {
            res.push_back(num[index.front()]);
            while(!index.empty() && num[index.back()] <= num[i])
            {
                index.pop_back();
            }
            if(!index.empty() && ((i - index.front()) >= (int)(size)))
            {
                index.pop_front();
            }
            index.push_back(i);
        }
        res.push_back(num[index.front()]);
        return res;
    }
};