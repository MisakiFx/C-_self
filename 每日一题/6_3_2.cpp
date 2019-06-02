#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
int main()
{
    int n = 0, m = 0;
    while(cin >> n >> m)
    {
        vector<int> board(m + 1, INT_MAX);
        board[n] = 0;//第0步
        for(int i = n; i <= m; i++)
        {
            if(board[i] == INT_MAX)
            {
                continue;
            }
            for(int j = 2; (j * j) <= i; j++)
            {
                if(i % j == 0)
                {
                    if(i + j <= m)
                    board[i + j] = min(board[i] + 1, board[i + j]);
                    if(i + (i / j) <= m)
                    board[i + (i / j)] = min(board[i] + 1, board[i + (i / j)]);
                }
            }
        }
        if(board[m] == INT_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << board[m] << endl;
        }
    }
}