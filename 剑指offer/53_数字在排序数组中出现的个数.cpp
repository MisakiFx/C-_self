#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int GetFirstK(const vector<int>& data, int k)
    {
        int start = 0;
        int end = data.size() - 1;
        while(start <= end)
        {
            int mid = (start + end) >> 1;
            if(data[mid] > k)
            {
                end = mid - 1;
            }
            else if(data[mid] < k)
            {
                start = mid + 1;
            }
            else 
            {
                if(mid == 0 || data[mid - 1] != k)
                {
                    return mid;
                }
                else 
                {
                    end = mid - 1;
                }
            }
        }
        //没找到
        return -1;
    }
    int GetLastK(const vector<int>& data, int k)
    {
        int start = 0;
        int end = data.size() - 1;
        while(start <= end)
        {
            int mid = (start + end) >> 1;
            if(data[mid] > k)
            {
                end = mid - 1;
            }
            else if(data[mid] < k)
            {
                start = mid + 1;
            }
            else 
            {
                if(mid == (data.size() - 1) || data[mid + 1] != k)
                {
                    return mid;
                }
                else 
                {
                    start = mid + 1;
                }
            }
        }
        //没找到
        return -1;
    }
    int GetNumberOfK(vector<int> data ,int k) 
    {
        int first = GetFirstK(data, k);
        int last = GetLastK(data, k);
        if(first == -1 || last == -1)
        {
            return 0;
        }
        int count = last - first + 1;
        return count;
    }
};
