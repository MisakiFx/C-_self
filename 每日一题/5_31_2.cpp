//这题有很大的问题，网上的解法都不是最好的解法
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int a = 0;
    while(cin >> a)
    {
        int cur = 0;
        int max = 0;
        while(a)
        {
            if((a & 1) == 1)
            {
                cur++;
                if(cur > max)
                {
                    max = cur;
                }
            }
            else
            {
                cur = 0;
            }
            a = a >> 1;
        }
        cout << max << endl;
        }
}