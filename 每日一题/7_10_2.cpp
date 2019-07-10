// write your code here cpp
//溢出你妈隔壁
#include <iostream>
using namespace std;
int main()
{
    long long arr[80] = { 0 };
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2; i < 80; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    int from, to;
    while(cin >> from >> to)
    {
        long long sum = 0;
        for(int i = from - 1 ; i < to; i++)
        {
            sum += arr[i];
        }
       cout << sum << endl;
    }
}