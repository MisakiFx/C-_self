//https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&&tqId=11202&rp=6&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
/**
 * 题目描述
将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0

示例1
输入
+2147483647
    1a33

输出
2147483647
    0
 */
/*
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
*/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int StrToInt(string str) {
        int symbal = 1;
        if(str[0] == '-')
        {
            symbal = -1;
            str[0] = '0';
        }
        if(str[0] == '+')
        {
            symbal = 1;
            str[0] = '0';
        }
        int num = 0;
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] > '9' || str[i] < '0')
            {
                return 0;
            }
            num *= 10;
            num += str[i] - '0';
        }
        return num * symbal;
    }
};
int main()
{

}