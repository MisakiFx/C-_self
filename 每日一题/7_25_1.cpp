// write your code here cpp
#include <iostream>
// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    //动态规划解错排问题，详见https://www.luogu.org/blog/P6174/post-cuo-pai
    int num = 0;
    while(cin >> num)
    {
        vector<long long> arr(num, 0);
        //初始状态
        arr[1] = 1;
        arr[2] = 2;
        for(int i = 3; i < num; i++)
        {
            arr[i] = i * (arr[i - 1] + arr[i - 2]);
        }
        cout << arr[num - 1] << endl;
    }
}