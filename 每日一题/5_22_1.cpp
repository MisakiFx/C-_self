//https://www.nowcoder.com/practice/bd891093881d4ddf9e56e7cc8416562d?tpId=85&&tqId=29864&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
/**
 * 题目描述
读入一个字符串str，输出字符串str中的连续最长的数字串
输入描述:
个测试输入包含1个测试用例，一个字符串str，长度不超过255。
输出描述:
在一行内输出str中里连续最长的数字串。

示例1

输入
abcd12345ed125ss123456789

输出
123456789
*/
/*
#include <iostream>
#include <string>
#include <vector>

//想的太复杂了一次遍历即可
using namespace std;
int main()
{
    string str;
    cin >> str;
    string maxDigitStr;
    int maxLength = 0;
    for(int i = 0; i < str.size(); i++)
    {
        int length = 0;
        if(str[i] >= '0' && str[i] <= '9')
        {
            int j;
            length++;
            if(i < str.size() - 1);
            {
                for(j = i + 1; j < str.size(); j++)
                {
                    if(str[j] >= '0' && str[j] <= '9')
                    {
                        length++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if(length > maxLength)
            {
                maxDigitStr = str.substr(i, length);
                maxLength = length;
            }
            i = j - 1;
        }
    }
    cout << maxDigitStr << endl;
}
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str, cur, res;
    cin >> str;
    for(int i = 0; i <= str.size(); i++)
    {
        //遇到数字串
        if(str[i] >= '0' && str[i] <= '9')
        {
            cur += str[i];
        }
        //数字串结束
        else
        {
           if(cur.size() > res.size())
           {
               res = cur;
           } 
           cur.clear();
        }
    }
    cout << res << endl;
}
