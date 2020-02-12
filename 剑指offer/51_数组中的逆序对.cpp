#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.size() <= 0)
        {
            return 0;
        }
        vector<int> copy(data.begin(), data.end());
        long long res = InversePairs(data, copy, 0, data.size() - 1);
        return res % 1000000007;
    }
    long long InversePairs(vector<int>& data, vector<int>& copy, int start, int end)
    {
        if(start == end)
        {
            //copy[start] = data[start];
            return 0;
        }
        int length = (end - start) >> 1;
        long long left = InversePairs(copy, data, start, start + length);
        long long right = InversePairs(copy, data, start + length + 1, end);
        int i = start + length;
        int j = end;
        int copyIndex = end;
        long long count = 0;
        while(i >= start && j >= (start + length + 1))
        {
            if(data[i] > data[j])
            {
                copy[copyIndex--] = data[i--];
                count += (j - start - length);
            }
            else 
            {
                copy[copyIndex--] = data[j--];
            }
        }
        for(; i >= start; i--)
        {
            copy[copyIndex--] = data[i];
        }
        for(; j >= start + length + 1; j--)
        {
            copy[copyIndex--] = data[j];
        }
        return left + right + count;
    }
};