#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool Compare(const string& str1, const string& str2)
    {
        string combine1, combine2;
        combine1 += str1;
        combine1 += str2;
        combine2 += str2;
        combine2 += str1;
        int res = combine1.compare(combine2);
        if(res < 0)
        {
            return true;
        }
        return false;
    }
    string PrintMinNumber(vector<int> numbers) {
        if(numbers.size() <= 0)
        {
            return "";
        }
        int length = numbers.size();
        vector<string> strNumbers(length);
        for(int i = 0; i < length; i++)
        {
            strNumbers[i] = to_string(numbers[i]);//一个int型数字最长就10位，加上一位\0
        }
        sort(strNumbers.begin(), strNumbers.end(), Compare);
        string res;
        for(int i = 0; i < length; i++)
        {
            res += strNumbers[i];
        }
        return res;
    }
};

int main()
{
    Solution sol;
    std::cout << sol.PrintMinNumber({3, 5, 1, 4, 2}) << std::endl;
}