//https://www.nowcoder.com/practice/e2a22f0305eb4f2f9846e7d644dba09b?tpId=37&&tqId=21314&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
/**
 * 题目描述
请编写一个函数（允许增加子函数），计算n x m的棋盘格子（n为横向的格子数，m为竖向的格子数）沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，即：只能往右和往下走，不能往左和往上走。
输入描述:
输入两个正整数

输出描述:
返回结果

示例1
输入
2
2

输出
6
*/
//动态规划，路径和为当前格子的左一个和上一个格子路径之和
//最左侧和最上侧一行各自 的各自步数都为1
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n = 0, m = 0;
    while(cin >> n >> m)
    {
        vector<vector<int>> num(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i < n + 1; i++)
        {
            for(int j = 0; j < m + 1; j++)
            {
                if(i == 0 && j == 0)
                {
                    num[i][j] = 1;
                }
                else if(i == 0)
                {
                    num[i][j] = num[i][j - 1];
                }
                else if(j == 0)
                {
                    num[i][j] = num[i - 1][j];
                }
                else
                {
                    num[i][j] = num[i - 1][j] + num[i][j - 1];
                }
            }
        }
        cout << num[n][m] << endl;
    }
}
//递归算法
/*
#include <iostream>
using namespace std;
int steps(int n, int m)
{
    if(n > 1 && m > 1)
    {
        return steps(n - 1, m) + steps(n, m - 1);
    }
    else if((n >= 1 && m == 1) || (m >= 1 && n == 1))
    {
        return n + m;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n = 0, m = 0;
    while(cin >> n >> m)
    {
        cout << steps(n, m) << endl;
    }
}
*/