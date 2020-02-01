#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() <= 0)
        {
            return 0;
        }
        int max = array[0];
        int sum = array[0];
        for(int i = 1; i < array.size(); i++)
        {
            if(sum + array[i] > array[i])
            {
                sum += array[i];
            }
            else 
            {
                sum = array[i];
            }
            if(sum > max)
            {
                max = sum;
            }
        }
        return max;
    }
};
