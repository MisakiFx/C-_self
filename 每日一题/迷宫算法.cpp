#include <iostream>
#include <vector>
#include <string>
using namespace std;
int curTime = 0;
vector<string> maze;
int m, n, needTime;
void SearchMaze(int ii, int jj, int& sum, int& minTime)
{
    //cout << ii << " " << jj << endl;
    curTime++;
    if(ii >= n || ii < 0 || jj < 0 || jj >= m  || maze[ii][jj] == '#') //当不可走时，就退后，路程减一 
	{
        curTime--;
        return;
    } 
    if(maze[ii][jj] == 'C')//找到终点
    {
        if(curTime <= needTime + 1)
        {
            if(curTime < minTime)
            {
                sum = 0;
                minTime = curTime;
            }
            if(curTime == minTime)
            {
                sum += 1;
            }
        }
        curTime--;
        return;
    }
    maze[ii][jj] = '#';
    if(ii - 1 >= 0 && maze[ii - 1][jj] != '#')
    {
        SearchMaze(ii - 1, jj, sum, minTime);
    }
    if(jj - 1 >= 0 && maze[ii][jj - 1] != '#')
    {
        SearchMaze(ii, jj - 1, sum, minTime);
    }
    if(ii + 1 < m && maze[ii + 1][jj] != '#')
    {
        SearchMaze(ii + 1, jj, sum, minTime);
    }
    if(jj + 1 < n && maze[ii][jj + 1] != '#')
    {
        SearchMaze(ii, jj + 1, sum, minTime);
    }
    maze[ii][jj] = '*';
    curTime--;
}
int main()
{
    int t = 0;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        maze.clear();
        curTime = 0;
        cin >> m >> n >> needTime;
        for(int i = 0; i < m; i++)
        {
            string str;
            cin >> str;
            maze.push_back(str);
        }
        int ii, jj;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(maze[i][j] == 'L')
                {
                    ii = i;
                    jj = j;
                }
            }
        }
        int sum = 0;
        int minTime = 1000;
        SearchMaze(ii, jj, sum, minTime);
        if(minTime - 1 > needTime || sum == 0)
        {
            cout << "Case #" << i + 1 << ": " << "-1" << endl;
        }
        else
        {
            cout << "Case #" << i + 1 << ": " << minTime - 1 << " " << sum << endl;
        }
    }
}