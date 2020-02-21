#include <iostream>
#include <vector>

int FindNumberAppendingOnce(const std::vector<int>& arr)
{
    int plus[32] = {0};
    for(int i = 0; i < arr.size(); i++)
    {
        int temp = 1;
        for(int j = 31; j >= 0; j--)
        {
            int bit = arr[i] & temp;
            if(bit != 0)
            {
                plus[j] += 1;
            }
            temp <<= 1;
        }
    }
    int res = 0;
    for(int i = 0; i < 32; i++)
    {
        res <<= 1;
        if(plus[i] % 3 != 0)
        {
            res |= 1;
        }
    }
    return res;
}

int main()
{
    std::cout << FindNumberAppendingOnce({2, 2, 3, 4, 5, 1, 1, 1, 2, 4, 4, 5, 5}) << std::endl;
}
