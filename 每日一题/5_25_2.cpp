//将字符串转为数字
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    int StrToInt(string str) {
        int num = 0;
        if(str[0] == '-')
        {
            for(int i = 1; i < str.size(); i++)
            {
                if(str[i] < '0' || str[i] > '9')
                {
                    return 0;
                }
                num *= 10;
                num -= str[i] - '0';
            }
        }
        else if(str[0] == '+')
        {
            for(int i = 1; i < str.size(); i++)
            {
                if(str[i] < '0' || str[i] > '9')
                {
                    return 0;
                }
                num *= 10;
                num += str[i] - '0';
            }
        }
        else
        {
            for(int i = 0; i < str.size(); i++)
            {
                if(str[i] < '0' || str[i] > '9')
                {
                    return 0;
                }
                num *= 10;
                num += str[i] - '0';
            }
        }
        return num;
    }
};
int main()
{
    string str;
    cin >> str;
    Solution sol;
    int num = sol.StrToInt(str);
    cout << num << endl;
}