#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <limits.h>

class Solution {
public:
    int StrToInt(std::string str) {
        if(str == "" || str.size() > 11)
        {
            return 0;
        }
        if(str[0] == '+')
        {
            std::string num = str.substr(1);
            //判断是否合法
            for(auto e : num)
            {
                if(e > '9' || e < '0')
                {
                    return 0;
                }
            }
            //判断越界
            if(num.size() >= 10)
            {
                for(int i = 0; i < num.size(); i++)
                {
                    if((num[i] - '0') > ((int)(INT_MAX / pow(10, 9 - i)) % 10))
                    {
                        return 0;
                    }
                }
            }
            int realNum = 0;
            for(int i = num.size() - 1; i >= 0; i--)
            {
                realNum += (num[i] - '0') * (pow(10, num.size() - 1 - i)); 
            }
            return realNum;
        }
        else if(str[0] == '-')
        {
            std::string num = str.substr(1);
            //判断是否合法
            for(auto e : num)
            {
                if(e > '9' || e < '0')
                {
                    return 0;
                }
            }
            //判断越界
            if(num.size() >= 10)
            {
                for(int i = 0; i < num.size(); i++)
                {
                    if(((num[i] - '0') * -1) < ((int)(INT_MIN / pow(10, 9 - i)) % 10))
                    {
                        return 0;
                    }
                }
            }
            int realNum = 0;
            for(int i = num.size() - 1; i >= 0; i--)
            {
                realNum += (num[i] - '0') * (pow(10, num.size() - 1 - i)); 
            }
            return (realNum * -1);
        }
        else
        {
            std::string num = str.substr(0);
            //判断是否合法
            for(auto e : num)
            {
                if(e > '9' || e < '0')
                {
                    return 0;
                }
            }
            //判断越界
            if(num.size() >= 10)
            {
                for(int i = 0; i < num.size(); i++)
                {
                    if((num[i] - '0') > ((int)(INT_MAX / pow(10, 9 - i)) % 10))
                    {
                        return 0;
                    }
                }
            }
            int realNum = 0;
            for(int i = num.size() - 1; i >= 0; i--)
            {
                realNum += (num[i] - '0') * (pow(10, num.size() - 1 - i)); 
            }
            return realNum;
        }
    }
};
int main()
{
    Solution sol;
    std::string str;
    std::cin >> str;
    int num = sol.StrToInt(str);
    std::cout << num << std::endl;
}