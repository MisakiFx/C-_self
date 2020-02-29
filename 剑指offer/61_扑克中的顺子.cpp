#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int countOfZero = 0;
        int blank = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] == 0)
            {
                countOfZero += 1;
            }
            else
            {
                if(nums[i] == nums[i + 1])
                {
                    return false;
                }
                blank += (nums[i + 1] - nums[i] - 1);
            }
        }
        if(countOfZero >= blank)
        {
            return true;
        }
        return false;
    }
};