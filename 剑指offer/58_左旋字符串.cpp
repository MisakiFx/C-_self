#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    //左闭右开区间
    void Reverse(string& str, int start, int end)
    {
        if(str.size() <= 1)
        {
            return;
        }
        while(start < end)
        {
            swap(str[start++], str[end--]);
        }
    }
    string LeftRotateString(string str, int n) {
        if(n <= 0 || str.size() <= 0 || n >= str.size())
        {
            return str;
        }
        Reverse(str, 0, n - 1);
        Reverse(str, n, str.size() - 1);
        Reverse(str, 0, str.size() - 1);
        return str;
    }
};