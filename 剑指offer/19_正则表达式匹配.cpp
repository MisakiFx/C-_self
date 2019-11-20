#include <iostream>

class Solution {
public:
    //这道题用递归解法才是最优解，之前用迭代判断三种情况累死个人
    bool matchCore(char* str, char* pattern)
    {
        if(*str == '\0' && *pattern == '\0')
        {
            return true;
        }
        //这种失败情况是pattern已经匹配完了，但是str没有匹配完，反之是可以继续匹配的
        if(*str != '\0' && *pattern == '\0')
        {
            return false;
        }
        //首先处理就是*的特殊情况
        //*有三种情况，匹配一个字符，匹配多个字符，匹配0个字符
        if(*(pattern + 1) == '*')
        {
            //如果此时上下字符相同或者可以匹配则三种情况都有可能
            if(*pattern == *str || *pattern == '.' && *str != '\0')
            {
                return matchCore(str + 1, pattern + 2)
                    || matchCore(str + 1, pattern)
                    || matchCore(str, pattern + 2);
            }
            //上下字符不同无法完成匹配，只能跳过pattern的*，只有这一种情况
            else 
            {
                return matchCore(str, pattern + 2);
            }
        }
        //其他情况
        else 
        {
            //可以匹配的情况，上下同时跳过一个字符
            if(*pattern == *str || *pattern == '.' && *str != '\0')
            {
                return matchCore(str + 1, pattern + 1);
            }
            //无法匹配就错误返回
            else 
            {
                return false;
            }
        }
    }
    bool match(char* str, char* pattern)
    {
        if(str == nullptr || pattern == nullptr)
        {
            return false;
        }
        return matchCore(str, pattern);
    }
};