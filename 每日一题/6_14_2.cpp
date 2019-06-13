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
                int case2 = dp[i][j - 1] + 1;//增加一个
                int case3 = dp[i - 1][j] + 1;//删除一个
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