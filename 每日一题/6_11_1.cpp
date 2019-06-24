//https://www.nowcoder.com/practice/e45e078701ab4e4cb49393ae30f1bb04?tpId=37&&tqId=21235&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
/**
 * 题目描述
写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。例如：
输入描述:
输入N个字符

输出描述:
输出该字符串反转后的字符串

示例1
输入
abcd

输出
dcba
 */
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1;
    while(cin >> str1)
    {
        string str2;
        for(int i = str1.size() - 1; i >= 0; i--)
        {
            str2 += str1[i];
        }
        cout << str2 << endl;
    }
}