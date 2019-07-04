//动态规划背包问题
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	/**
	 *	正数数组中的最小不可组成和
	 *	输入：正数数组arr
	 *	返回：正数数组中的最小不可组成和
	 */
	int getFirstUnFormedNum(vector<int> arr, int len) 
    {
        if (arr.size() == 0) 
        {
            return 1;
        }
        int min = INT_MAX;
        int max = 0;
        for (int i = 0;i < arr.size();i++) 
        {
            min = std::min(min, arr[i]);
            max += arr[i];
        }
        vector<bool> dp;
        dp.resize(max + 1);
        dp[0] = true;
        dp[arr[0]] = true;
        for(int i = 1;i < arr.size(); i++) 
        {
            for(int col = dp.size() - 1; col-arr[i] >= 0; col--) 
            {
                dp[col] = dp[col - arr[i]] ? true : dp[col];
            }
        }
        for (int num = min + 1; num <= max; num++) 
        {
            if(!dp[num]) 
            {
                return num;
            }
        }
        return max + 1;
    }
};
int main()
{

}