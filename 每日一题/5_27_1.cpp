//斐波那契数列问题
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int arr[3] = {0};
    arr[0] = 2;
    arr[1] = 3;
    arr[2] = 5;
    int num = 0;
    cin >> num;
    if(num <= 3)
    {
        cout << 0 << endl;
        return 0;
    }
    int pre = 3;
    while(num - arr[2] > 0)
    {
        pre = arr[2];
        arr[2] = pre + arr[1];
        arr[0] = arr[1];
        arr[1] = pre;
    }
    if((num - pre) > (arr[2] - num))
    {
        cout << (arr[2] - num) << endl;
    }
    else
    {
        cout << (num - pre) << endl;
    }
}