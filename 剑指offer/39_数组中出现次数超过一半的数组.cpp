#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size() <= 0)
        {
            return 0;
        }
        int mid = numbers.size() >> 1;
        int begin = 0, end = numbers.size();
        int index = Partition(numbers, begin, end);
        while(index != mid)
        {
            if(index < mid)
            {
                begin = index + 1;
                index = Partition(numbers, begin, end);
            }
            else
            {
                end = index;
                index = Partition(numbers, begin, end);
            }
        }
        //检测是否符合要求
        bool isTrue = IsTrue(numbers, numbers[mid]);
        if(isTrue == true)
        {
            return numbers[mid];
        }
        else 
        {
            return 0;
        }
    }
    int MoreThanHalfNum_Solution2(vector<int> numbers) {
        if(numbers.size() <= 0)
        {
            return 0;
        }
        int num = numbers[0];
        int times = 1;
        for(const auto& e : numbers)
        {
            if(times == 0)
            {
                num = e;
                times = 1;
            }
            if(e == num)
            {
                times++;
            }
            else
            {
                times--;
            }
        }
        //检测是否符合要求
        bool isTrue = IsTrue(numbers, num);
        if(isTrue == true)
        {
            return num;
        }
        else 
        {
            return 0;
        }
    }
    //左闭右开区间
    int Partition(vector<int>& nums, int start, int end)
    {
        if(end <= start)
        {
            return start;
        }
        int i = start, j = end - 1;
        int temp = nums[i];
        while(i < j)
        {
            while(i < j && nums[j] >= temp)
            {
                j--;
            }
            if(i >= j)
            {
                break;
            }
            nums[i] = nums[j];
            while(i < j && nums[i] <= temp)
            {
                i++;
            }
            if(i >= j)
            {
                break;
            }
            nums[j] = nums[i];
        }
        nums[i] = temp;
        return i;
    }
    bool IsTrue(const vector<int>& nums, int num)
    {
        int times = 0;
        for(auto e : nums)
        {
            if(e == num)
            {
                times++;
            }
        }
        if((times * 2) > nums.size())
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
};