#include <iostream>
#include <vector>
#include <string>

//动态规划解法，f(i)表示以i结尾的子字符串不含重复字符的最长长度
int LongestSubstringWithoutDuplication(const std::string& str, std::string& maxString)
{
    int maxLength = 0;
    int curLength = 0;
    std::vector<int> lastPositions(26, -1);
    for(int i = 0; i < str.size(); i++)
    {
        int lastPos = lastPositions[str[i] - 'a'];
        if(lastPos < 0 || i - lastPos > curLength)
        {
            curLength++;
        }
        else 
        {
            if (curLength > maxLength)
            {
                maxLength = curLength;
                maxString = str.substr(i - (maxLength - 1), maxLength);
            }
            curLength = i - lastPos;
        }
        lastPositions[str[i] - 'a'] = i;
        if(curLength > maxLength)
        {
            maxLength = curLength;
            maxString = str.substr(i - (maxLength - 1), maxLength);
        }
    }
    return maxLength;
}

int main()
{
    std::string maxString;
    std::cout << LongestSubstringWithoutDuplication("arabcacfr", maxString) << std::endl;
    std::cout << maxString << std::endl;
}
