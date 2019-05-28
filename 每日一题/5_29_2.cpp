//动态规划求路径
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