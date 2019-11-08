//普通解法
#include <iostream>
class Solution
{
public:
    int NumberOf1(int n)
    {
        int count = 0;
        int num = 1;
        for (int i = 0; i < 32; i++)
        {
            if (n & num)
            {
                count++;
            }
            num <<= 1;
        }
        return count;
    }
};
//牛逼解法
class Solution2
{
public:
    int NumberOf1(int n)
    {
        int count = 0;
        while (n)
        {
            count++;
            n = (n - 1) & n; //这一步可以将数中最右边的1置0
        }
        return count;
    }
};