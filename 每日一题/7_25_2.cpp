// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int num;
    while(cin >> num)
    {
        vector<int> arr(num, 0);
        vector<int> res(num, 1);
        for(int i = 0; i < num; i++)
        {
            cin >> arr[i];
        }
        //动态规划求最长递增子序列
        int result = 1;
        for(int i = 1; i < num; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(arr[j] < arr[i] && res[j] >= res[i])
                {
                    res[i] = res[j] + 1;
                }
            }
            if(res[i] > result)
            {
                result = res[i];
            }
        }
        cout << result << endl;
    }
}