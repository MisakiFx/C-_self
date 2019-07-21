#include <iostream>
#include <vector>
using namespace std;
class Printer {
public:
    vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
        // write code here
        vector<int> result;
        while(n > 0 && m > 0)
        {
            for(int i = 0; i < m; i++)
            {
                result.push_back(mat[0][i]);
            }
            for(int i = 1; i < n; i++)
            {
                result.push_back(mat[i][m -1]);
            }
            if(n > 1)
            {
                for (int i = m - 2; i >= 0; i--)
                {
                    result.push_back(mat[n - 1][i]);
                }
            }
            if(m > 1)
            {
                for (int i = n - 2; i >= 1; i--)
                {
                    result.push_back(mat[i][0]);
                }
            }
            for(int i = 1; i < n - 1; i++)
            {
                for(int j = 1; j < m - 1; j++)
                {
                    mat[i - 1][j - 1] = mat[i][j];
                }
            }
            n -= 2;
            m -= 2;
        }
        return result;
    }
};
int main()
{
    Printer print;
    vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    vector<int> res = print.clockwisePrint(vec, 4, 3);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}