//一个数组中，有一个数只出现了一次，其他数均出现了两次，返回这个只出现了一次的数
//要求线性时间，不分配其他内存空间
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //1、0 ^ n = n
        //2、n ^ n = 0
        int result = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            result ^= nums[i];
        }
        return result;
    }
};
int main()
{

}