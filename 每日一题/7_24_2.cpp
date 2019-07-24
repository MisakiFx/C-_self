// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string str1, str2;
    while(cin >> str1 >> str2)
    {
        //动态规划求解，建立矩阵，行和列各代表一个字符串
        //子状态dp[i][j]表示str1从第0个字符起到第i个字符为止和str2从第0个字符起到第j个字符为止最长子串长度
        int row = str1.size();
        int col = str2.size();
        //定义初始状态，
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
        for(int i = 1; i <= row; i++)
        {
            for(int j = 1; j <= col; j++)
            {
                if(str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << dp[row][col] << endl;
    }
}