#include <iostream>
#include <vector>

int GetNumberSameAsIndex(const std::vector<int>& arr)
{
    int start = 0;
    int end = arr.size() - 1;
    while(start <= end)
    {
        int mid = (start + end) >> 1;
        if(arr[mid] < mid)
        {
            start = mid + 1;
        }
        else if(arr[mid] > mid)
        {
            end = mid - 1;
        }
        else 
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    std::cout << GetNumberSameAsIndex({-3, -1, 1, 2, 4, 6}) << std::endl;
}
