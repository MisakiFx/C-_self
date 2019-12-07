//https://www.nowcoder.com/questionTerminnal/296c2c18037843a7b719cf4c9c0144e4

#include <iostream>
#include <vector>
using namespace std;

//这个是一个背包问题的变形，
//相当于物体的体积和价值都为arr
//背包总容量为最大组成和
//我们就求出背包问题最终状态下各个容量下可以获得的最大价值
//从最小组成和开始往后遍历，找到第一个最大价值不等于背包容量的，就是解
//因为按理来说物体容量和价值相等情况下，如果一个背包可以刚好塞满（及用完全部容量），其最大价值 == 容量
int getFirstUnFormedNum(vector<int> arr, int len)
{
    int i, j;
    int min = arr[0], max = 0;
    for (i = 0; i < len; i++)
    {
        max += arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    vector<int> dp(max + 1, 0);
    for (i = 0; i < len; i++)
        for (j = max; j >= arr[i]; j--)
        {
            if (dp[j - arr[i]] + arr[i] > dp[j])
                dp[j] = dp[j - arr[i]] + arr[i];
            else
                dp[j] = dp[j];
        }
    for (i = min; i <= max; i++)
    {
        if (i != dp[i])
            return i;
    }
    return i;
}
//还有一种解法就是利用set存储求出的所有子集的和，然后再从最小的网上找，这种方法如果数组元素过多时间是不够的
//复杂度过大
