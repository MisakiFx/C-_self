//https://www.nowcoder.com/practice/98dc82c094e043ccb7e0570e5342dd1b?tpId=37&&tqId=21298&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
/**
 * 题目描述
题目标题：

计算两个字符串的最大公共字串的长度，字符不区分大小写

详细描述：

接口说明

原型：

int getCommonStrLength(char * pFirstStr, char * pSecondStr);

输入参数：

     char * pFirstStr //第一个字符串

     char * pSecondStr//第二个字符串
 

输入描述:
输入两个字符串

输出描述:
输出一个整数

示例1
输入
asdfas werasdfaswer

输出
6
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
        string curString;
        string maxString;
        for(int i = 0; i < str1.size(); i++)
        {
            if(str1[i] >= 'A' && str1[i] <= 'Z')
            {
                str1[i] -= ' ';
            }
        }
        for(int i = 0; i < str2.size(); i++)
        {
            if(str2[i] >= 'A' && str2[i] <= 'Z')
            {
                str2[i] -= ' ';
            }
        }
        for(int i = 0; i < str1.size(); i++)
        {
            for(int j = 0; j < str2.size(); j++)
            {
                if(str1[i] == str2[j])
                {
                    int m = i;
                    int n = j;
                    while(str1[m] == str2[n] && str1[m] != '\0' && str2[n] !='\0')
                    {
                        curString += str1[m];
                        //cout << curString << endl;
                        m++;
                        n++;
                    }
                    if(curString.size() > maxString.size())
                    {
                        maxString = curString;
                    }
                    curString.resize(0);
                }
            }
        }
        cout << maxString.size() << endl;
    }
}
//动态规划做法
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string str1, str2;
    while(cin >> str1 >> str2)
    {
        int len1 = str1.size();
        int len2 = str2.size();
        int maxlen = 0;
        vector<vector<int>> lens(len1 + 1, vector<int>(len2 + 1, 0));
        for(int i = 1; i <= len1; i++)
        {
            for(int j = 1; j <= len2; j++)
            {
                if(str1[i - 1] == str2[j - 1])
                {
                    lens[i][j] = lens[i - 1][j - 1] + 1;
                }
                if(lens[i][j] > maxlen)
                {
                    maxlen = lens[i][j];
                }
            }
        }
        cout << maxlen << endl;
    }
}