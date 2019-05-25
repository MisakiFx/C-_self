//动态规划
#include <iostream>
using namespace std;
int main()
{
    int high = 0;
    int width = 0;
    cin >> width >> high;
    int result = 0;
    int arr[1000][1000] = {0};
    for(int i = 0; i < high; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(arr[i][j] != -1)
            {
                result++;
                if(i + 2 < high)
                {
                    arr[i + 2][j] = -1;
                }
                if(j + 2 < width)
                {
                    arr[i][j + 2] = -1;
                }
            }
        }
    }
    cout << result << endl;
}