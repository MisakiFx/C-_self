#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n = 0, m = 0;
    while(cin >> n >> m)
    {
        //创建迷宫矩阵，用0表示没有蘑菇，1表示有蘑菇
        vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
        int k;
        cin >> k;
        for(int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            arr[x][y] = 1;
        }
        //创建结果矩阵，动态规划，每一个表示走到当前位置不触碰蘑菇的概率
        vector<vector<double>> resArr(n + 1, vector<double>(m + 1, 0));
        //初始状态,第一格没有蘑菇概率为1
        resArr[1][1] = 1;
        //遍历根据状态转移方程更新状态
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(i == 1 && j == 1)
                {
                    continue;
                }
                if(arr[i][j])
                {
                    resArr[i][j] = 0;
                    continue;
                }
                resArr[i][j] = resArr[i - 1][j] * (j == m ? 1 : 0.5) + resArr[i][j - 1] * (i == n ? 1 : 0.5);
            }
        }
        //输出最终状态
        printf("%.2lf\n", resArr[n][m]);
    }
}