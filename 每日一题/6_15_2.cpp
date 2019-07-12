//https://www.nowcoder.com/practice/cf24906056f4488c9ddb132f317e03bc?tpId=37&&tqId=21266&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
/**
 * 题目描述
定义一个二维数组N*M（其中2<=N<=10;2<=M<=10），如5 × 5数组下所示： 


int maze[5][5] = {


        0, 1, 0, 0, 0,


        0, 1, 0, 1, 0,


        0, 0, 0, 0, 0,


        0, 1, 1, 1, 0,


        0, 0, 0, 1, 0,


};


它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。入口点为[0,0],既第一空格是可以走的路。

Input

一个N × M的二维数组，表示一个迷宫。数据保证有唯一解,不考虑有多解的情况，即迷宫只有一条通道。

Output

左上角到右下角的最短路径，格式如样例所示。

Sample Input

0 1 0 0 0

0 1 0 1 0

0 0 0 0 0

0 1 1 1 0

0 0 0 1 0

Sample Output

(0, 0)

(1, 0)

(2, 0)

(2, 1)

(2, 2)

(2, 3)

(2, 4)

(3, 4)

(4, 4)

输入描述:
输入两个整数，分别表示二位数组的行数，列数。再输入相应的数组，其中的1表示墙壁，0表示可以走的路。数据保证有唯一解,不考虑有多解的情况，即迷宫只有一条通道。

输出描述:
左上角到右下角的最短路径，格式如样例所示。

示例1
输入
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
输出
(0,0)
(1,0)
(2,0)
(2,1)
(2,2)
(2,3)
(2,4)
(3,4)
(4,4)
 */
#include <iostream>
#include <vector>
using namespace std;
int m, n;
vector<vector<int>> maze;
vector<vector<int>> trackTemp;
vector<vector<int>> trackBest;
void MazeTrack(int i, int j)
{
    maze[i][j] = 1;
    trackTemp.push_back({i, j});
    if(i + 1 == m && j + 1 == n && (trackTemp.size() < trackBest.size() || trackBest.size() == 0))
    {
        trackBest = trackTemp;
    }
    if((i - 1 >= 0) && (maze[i - 1][j] == 0))
    {
        MazeTrack(i - 1, j);
    }
    if((i + 1 < m) && (maze[i + 1][j] == 0))
    {
        MazeTrack(i + 1, j);
    }
    if((j - 1 >= 0) && (maze[i][j - 1] == 0))
    {
        MazeTrack(i, j - 1);
    }
    if((j + 1 < n) && (maze[i][j + 1] == 0))
    {
        MazeTrack(i, j + 1);
    }
    maze[i][j] = 0;
    trackTemp.pop_back();
}
int main()
{
    while(cin >> m >> n)
    {
        maze = vector<vector<int>>(m, vector<int>(n, 0));
        trackTemp.clear();
        trackBest.clear();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> maze[i][j];
            }
        }
        MazeTrack(0, 0);
        for(int i = 0; i < trackBest.size(); i++)
        {
            cout << "(" << trackBest[i][0] << "," << trackBest[i][1] << ")" << endl;
        }
    }
}