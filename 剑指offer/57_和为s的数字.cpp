#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        if(array.size() <= 0 || sum < 0)
        {
            return res;
        }
        int start = 0, end = array.size() - 1;
        while(end > start)
        {
            int temp = array[start] + array[end];
            if(temp < sum)
            {
                start++;
            }
            else if(temp > sum)
            {
                end--;
            }
            else 
            {
                res.push_back(array[start]);
                res.push_back(array[end]);
                break;
            }
        }
        return res;
    }
};