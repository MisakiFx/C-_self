//https://www.nowcoder.com/practice/43072d50a6eb44d2a6c816a283b02036?tpId=37&amp;&amp;tqId=21294&amp;rp=1&amp;r
/**
 * 
输入：
通配符表达式；
一组字符串。

输出：
返回匹配的结果，正确输出true，错误输出false

输入描述:
先输入一个带有通配符的字符串，再输入一个需要匹配的字符串

输出描述:
返回匹配的结果，正确输出true，错误输出false

示例1
输入
te?t*.*
txt12.xls

输出
false
 */
/*
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1;
    string str2;
    while(cin >> str1 >> str2)
    {
        int i = 0;
        int j = 0;
        while(str1[i] != '\0' && str2[j] != '\0')
        {
            if(str1[i] == '?')
            {
                i++;
                j++;
                continue;
            }
            if(str1[i] == '*')
            {
                i++;
                if(str1[i] == '?')
                {
                    i++;
                    j++;
                }
                while(str2[j] != str1[i] && str2[j] != '\0')
                {
                    j++;
                }
                if(str2[j] != str1[i] && str2[j] == '\0')
                {
                    continue;
                }
                else if(str2[j] == str1[i] && str2[j] == '\0')
                {
                    continue;
                }
                else
                {
                    j++;
                    i++;
                    while(str2[j] == str2[j - 1] && str2[j] != str1[i])
                    {
                        j++;
                    }
                    continue;
                }
            }
             if(str1[i] >= 'A' && str1[i] <= 'Z')
            {
                str1[i] -= ' ';
            }
            if(str2[j] >= 'A' && str2[j] <= 'Z')
            {
                str2[2] -= ' ';
            }
            if(str1[i] != str2[j])
            {
                //cout << str1[i] << " " << str2[j] << endl;
                break;
            }
            i++;
            j++;
        }
        if(str1[i] == '\0' && str2[j] == '\0')
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
}
*/
#include <iostream>
#include <string>
using namespace std;
bool Compare(const char* str1, const char* str2)
{
    if(*str1 == '\0' && *str2 == '\0')
    {
        return true;
    }
    if(*str1 == '\0' || *str2 == '\0')
    {
        return false;
    }
    if(*str1 == *str2)
    {
        return Compare(str1 + 1, str2 + 1);
    }
    else if(*str1 == '?')
    {
        return Compare(str1 + 1, str2 + 1);
    }
    else if(*str1 == '*')
    {
        return (Compare(str1 + 1, str2) || Compare(str1 + 1, str2 + 1) || Compare(str1, str2 + 1));
    }
    return false;
}
int main()
{
    string str1;
    string str2;
    while(cin >> str1 >> str2)
    {
        bool res = Compare(str1.c_str(), str2.c_str());
        if(res == true)
        {
            cout << "true" << endl;
        }
        else if(res == false)
        {
            cout << "false" << endl;
        }
    }
}