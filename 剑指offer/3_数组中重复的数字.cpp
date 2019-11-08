#include <iostream>
#include <vector>
//这道题可以利用map容器，哈希，排序等很多种方法去做，但是由于限定了一个条件
//在长度为n的数组中所有的数字都是0 ~ n - 1的于是就出现了事件复杂度空间复杂度n，空间复杂度O1的做法
//题目一
int Duplicate(std::vector<int> &arr)
{
    //数组为空
    if (arr.size() <= 0)
    {
        return -1;
    }
    //不满足题意
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0 || arr[i] >= arr.size())
        {
            return -1;
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        while (arr[i] != i)
        {
            if (arr[i] == arr[arr[i]])
            {
                return arr[i];
            }
            std::swap(arr[i], arr[arr[i]]);
        }
    }
    return -1;
}
//题目二，以时间换空间，
//查找[start, end)中数在arr中出现的次数
int CountRange(std::vector<int> &arr, int start, int end)
{
    if (arr.size() <= 0)
    {
        return -1;
    }
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= start && arr[i] < end)
        {
            count++;
        }
    }
    return count;
}
int GetDuplicate(std::vector<int> &arr)
{
    //左闭右开区间
    if (arr.size() == 0)
    {
        return -1;
    }
    int start = 1;
    int end = arr.size();
    while ((end - start) >= 1)
    {
        if ((end - start) == 1)
        {
            int count = CountRange(arr, start, end);
            if (count > 1)
            {
                return start;
            }
            else //意外错误
            {
                break;
            }
        }
        int mid = (end - start) / 2 + start;
        int count = CountRange(arr, start, mid);
        if (count > (mid - start))
        {
            end = mid;
        }
        else
        {
            start = mid;
        }
    }
    return -1;
}
int main()
{
    std::vector<int> arr = {1, 2, 2, 3, 5, 4};
    std::cout << (GetDuplicate(arr)) << std::endl;
    ;
}