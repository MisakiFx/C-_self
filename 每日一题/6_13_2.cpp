//https://www.nowcoder.com/practice/e896d0f82f1246a3aa7b232ce38029d4?tpId=37&&tqId=21282&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
/**
 * 题目描述
找出字符串中第一个只出现一次的字符

输入描述:
输入一个非空字符串

输出描述:
输出第一个只出现一次的字符，如果不存在输出-1

示例1
输入
asdfasdfo
输出
o
 */
/* 
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    int flag = 0;
    while(cin >> str)
    {    
        int i;
        for(i = 0; i < str.size(); i++)
        {
            int j;
            flag = 0;
            for(j = i + 1; j < str.size(); j++)
            {
                if(str[j] == str[i])
                {
                    flag = 1;
                    str.erase(j, 1);
                    j--;
                }
            }
            if(flag == 0)
            {
                cout << str[i] << endl;
                break;
            }
        }
        if(i == str.size())
        cout << "-1" << endl;
    }
}
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    string str;
    while(cin >> str)
    {
        map<char, int> count;
        for(int i = 0; i < str.size(); i++)
        {
            count[str[i]]++;
        }
        int i;
        //这里要用字符串进行遍历才能找到第一个出现的
        for(i = 0; i < str.size(); i++)
        {
            if(count[str[i]] == 1)
            {
                cout << str[i] << endl;
                break;
            }
        }
        if(i == str.size())
        {
            cout << -1 << endl;
        }
    }
}