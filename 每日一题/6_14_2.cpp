//https://www.nowcoder.com/practice/3959837097c7413a961a135d7104c314?tpId=37&&tqId=21275&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
/**
 * 题目描述
Levenshtein 距离，又称编辑距离，指的是两个字符串之间，由一个转换成另一个所需的最少编辑操作次数。许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。编辑距离的算法是首先由俄国科学家Levenshtein提出的，故又叫Levenshtein Distance。

Ex：

字符串A:abcdefg
字符串B: abcdef
通过增加或是删掉字符”g”的方式达到目的。这两种方案都需要一次操作。把这个操作所需要的次数定义为两个字符串的距离。
要求：
给定任意两个字符串，写出一个算法计算它们的编辑距离。
输入描述:
输入两个字符串
输出描述:
得到计算结果

示例1
输入
abcdefg
abcdef
输出
1
 */
//动态规划 
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string str1, str2;
    while(cin >> str1 >> str2)
    {
        int m = str1.size();
        int n = str2.size();
        //cout <<m << n << endl;
        //矩阵中每一格表示表示str1的前m个字符到str2d额前n个字符需要的最短步骤
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i <= n; i++)
        {
            dp[0][i] = 1 * i;
        }
        for(int i = 0; i <= m; i++)
        {
            dp[i][0] = 1 * i;
        }
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                int case1 = dp[i - 1][j - 1];//完全相等
                int case2 = dp[i][j - 1] + 1;//str2增加一个
                int case3 = dp[i - 1][j] + 1;//str1增加一个
                if(str1[i - 1] != str2[j - 1])
                {
                    case1 += 1;
                }
                dp[i][j] = min(min(case1, case2), case3);
            }
        }
        cout << dp[m][n] << endl;
    }
}