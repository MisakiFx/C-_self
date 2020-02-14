#include <iostream>
#include <vector>

int GetMissingNumber(const std::vector<int>& numbers)
{
    int start = 0;
    int end = numbers.size() - 1;
    while(start <= end)
    {
        int mid = (start + end) >> 1;
        if(numbers[mid] != mid)
        {
            if(mid == 0 || numbers[mid - 1] == (mid - 1))
            {
                return mid;
            }
            else 
            {
                end = mid - 1;
            }
        }
        else 
        {
            start = mid + 1;
        }
    }
    return -1;
}
int main()
{
    std::cout << GetMissingNumber({1, 2, 3, 4, 5, 6, 7, 8}) << std::endl;
}
