#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minNumber(const vector<int> &rotateArray)
    {
        int min = rotateArray[0];
        for (int i = 1; i < rotateArray.size(); i++)
        {
            if (rotateArray[i] < min)
            {
                min = rotateArray[i];
            }
        }
        return min;
    }
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if (rotateArray.size() <= 0)
        {
            return 0;
        }
        int start = 0, end = rotateArray.size() - 1;
        if (rotateArray[start] < rotateArray[end])
        {
            return rotateArray[start];
        }
        while ((end - start) > 1)
        {
            int mid = (start + end) / 2;
            if (rotateArray[start] == rotateArray[end] && rotateArray[start] == rotateArray[mid])
            {
                return minNumber(rotateArray);
            }
            if (rotateArray[mid] >= rotateArray[start])
            {
                start = mid;
            }
            else if (rotateArray[mid] <= rotateArray[end])
            {
                end = mid;
            }
        }
        return rotateArray[end];
    }
};