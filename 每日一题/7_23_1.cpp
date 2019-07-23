// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;
int m = 0, n = 0;
int count = 0;
//回溯法深度优先递归
void dps(vector<string>& arr, int i, int j)
{
    if(arr[i][j] == '.' || arr[i][j] == '@')
    {
        count++;
    }
    else
    {
        return;
    }
    arr[i][j] = '#';
    if(i + 1 < m)
    {
        dps(arr, i + 1, j);
    }
    if(i - 1 >= 0)
    {
        dps(arr, i - 1, j);
    }
    if(j + 1 < n)
    {
        dps(arr, i, j + 1);
    }
    if(j - 1 >= 0)
    {
        dps(arr, i, j - 1);
    }
}
int main()
{
    while(cin >> m >> n)
    {
        int posi, posj;
        vector<string> arr(m, string(n, '\0'));
        //输入矩阵
        for(int i = 0; i < m; i++)
        {
            cin >> arr[i];
            //查找起点坐标
            for(int j = 0; j < arr[i].size(); j++)
            {
                if(arr[i][j] == '@')
                {
                    posi = i;
                    posj = j;
                }
            }
        }
        count = 0;
        dps(arr, posi, posj);
        cout << count << endl;
    }
}