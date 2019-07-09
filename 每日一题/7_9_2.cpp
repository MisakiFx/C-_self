#include <iostream>
using namespace std;
int main()
{
    int n;
    int arr[100001] = { 0 };
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2; i < 100001; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
        arr[i] %= 1000000;
    }
    while(cin >> n)
    {
        printf((n < 29 ? "%d\n" : "%06d\n"),arr[n]);
    }
}