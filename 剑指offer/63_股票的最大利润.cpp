#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int max = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] < min)
            {
                min = prices[i];
            }
            max = std::max(max, prices[i] - min);
        }
        return max;
    }
};