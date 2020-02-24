#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        int mid = (1 + sum) / 2;
        int start = 1;
        int end = 2;
        while(start < mid)
        {
            int sumTemp = 0;
            for(int i = start; i <= end; i++)
            {
                sumTemp += i;
            }
            if(sumTemp < sum)
            {
                end++;
            }
            else if(sumTemp > sum)
            {
                start++;
            }
            else 
            {
                vector<int> temp;
                for(int i = start; i <= end; i++)
                {
                    temp.push_back(i);
                }
                res.push_back(temp);
                end++;
            }
        }
        return res;
    }
};