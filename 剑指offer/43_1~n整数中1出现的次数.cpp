#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n <= 0)
        {
            return 0;
        }
        //先将数字转换为字符串
        string str = to_string(n);
        return NumberOf1(str);
    }
    int NumberOf1(const string& str)
    {
        if(str == "" || str[0] < '0' || str[0] > '9')
        {
            return 0;
        }
        int first = str[0] - '0';
        int size = str.size();
        if(size == 1 && first == 0)
        {
            return 0;
        }
        if(size == 1 && first > 0)
        {
            return 1;
        }
        int numFirst = 0;
        if(first > 1)
        {
            numFirst = pow(10, size - 1);
        }
        else if(first == 1)
        {
            numFirst = stoi(str.substr(1)) + 1;
        }
        int numOthers = first * (size - 1) * pow(10, size - 2);
        int numRecursive = NumberOf1(str.substr(1));
        return numFirst + numOthers + numRecursive;
    }
};