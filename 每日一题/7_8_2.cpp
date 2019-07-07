// write your code here cpp
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    int a = 0;
    while(cin >> a)
    {
        vector<int> arr;
        int temp = a;
        for(int i = 2; i <= a; i++)
        {
            if(a <= 1)
            {
                break;
            }
            if(a % i == 0)
            {
                while(a % i == 0)
                {
                    a /= i;
                    arr.push_back(i);
                }
            }
        }
        cout << temp << " = ";
        for(int i = 0; i < arr.size() - 1; i++)
        {
            cout << arr[i] << " * ";
        }
        cout << arr[arr.size() - 1] << endl;
    }
}