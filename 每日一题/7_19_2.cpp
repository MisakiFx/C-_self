//先对体重进行升序排序，如果体重相同，则身高高的放在前面，为后面动态规划找最长子序列做准备
//排序结束后动态规划找升高的最长升序子序列即可
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Actor
{
    int wight;
    int hight;
};
bool com(Actor a1, Actor a2)
{
    if(a1.wight != a2.wight)
    {
        return a1.wight < a2.wight;
    }
    else
    {
        return a1.hight > a2.hight;
    }
}
int main()
{
    int num;
    while(cin >> num)
    {
        vector<Actor> arr;
        for(int i = 0; i < num; i++)
        {
            Actor temp;
            int index;
            cin >> index >> temp.wight >> temp.hight;
            arr.push_back(temp);
        }
        sort(arr.begin(), arr.end(), com);
        vector<int> dp(num, 1);
        int max = -1;
        for(int i = 1; i < num; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if((arr[i].hight >= arr[j].hight) && (dp[j] + 1 > dp[i]))
                {
                    dp[i] = dp[j] + 1;
                }
            }
            if(dp[i] > max)
            {
                max = dp[i];
            }
        }
        cout << max << endl;
    }
}