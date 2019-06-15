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
            cout << "(" << trackBest[i][0] << "," << trackBest[i][1] << ")" << endl;;
        }
    }
}