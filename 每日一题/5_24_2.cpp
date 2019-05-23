/**
 * 求连续的子序列最大和
 */ 
#include <iostream>
#include <limits.h>
using namespace std;
int main()
{
    int num = 0;
    cin >> num;
    int curMax = 0;
    int max = INT_MIN;
    for(int i = 0; i < num; i++)
    {
        int temp = 0;
        cin >> temp;
        curMax += temp;
        if(curMax > max)
        {
            max = curMax;
        }
        if(curMax < 0)
        {
            curMax = 0;
        }
    } 
    cout << max << endl;
}
/**
 * 拓展，实现求数值连续的子序列最大和
 */
/*
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int main()
{
    int num = 0;
    cin >> num;
    vector<int> array;
    array.resize(num);
    int curMax = 0;
    int max = INT_MIN;
    for(int i = 0; i < num; i++)
    {
        cin >> array[i];
    } 
    for(int i = 0;i < num - 1; i++)
    {
        curMax += array[i];
        while(((array[i + 1] == array[i] + 1) || (array[i + 1] == array[i] - 1)) && i < num - 1)
        {
            curMax += array[i + 1];
            i++;
        }
        if(curMax > max)
        {
            max = curMax;
        }
        curMax = 0;
    }
    if(array[num - 1] > max)
    {
        max = array[num - 1];
    }
    cout << max << endl;
}
*/