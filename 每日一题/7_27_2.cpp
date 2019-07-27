#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <windows.h>
//这类迷宫问题不能纯粹使用深度优先搜索，因为要完全遍历一遍很慢，还要加上动态规划算法（剪枝）
//记录到达每个点上的最少步数，如果大于这个步数则不再走这个点，可以剪掉大量冗余无效的走法
using namespace std;
int res[10][10] = { 0 };
vector<string> mess(10, string(10, 0));
int nextP[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void dfs(int i, int j)
{
    //继续向四周遍历
    for(int m = 0; m < 4; m++)
    {
        int newi = i + nextP[m][0];
        int newj = j + nextP[m][1];
        if(newi < 10 && newi >= 0 && newj < 10 && newj >= 0 && mess[newi][newj] != '#')
        {
            if(res[newi][newj] == 0 || res[newi][newj] > res[i][j] + 1)
            {
                res[newi][newj] = res[i][j] + 1;
                dfs(newi, newj);
            }
        }
    }
}
int main()
{
    while(cin >> mess[0])
    {
        for(int i = 1; i < 10; i++)
        {
            cin >> mess[i];
        }
        dfs(0, 1);
        cout << res[9][8] << endl;
        memset(res, 0, sizeof(res));
    }
}