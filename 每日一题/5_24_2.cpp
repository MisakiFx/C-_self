//https://www.nowcoder.com/practice/5a304c109a544aef9b583dce23f5f5db?tpId=85&&tqId=29858&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
/**
 * 题目描述
一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1,2,1]，和最大的连续子数组为[2,1]，其和为 3
输入描述:
输入为两行。 第一行一个整数n(1 <= n <= 100000)，表示一共有n个元素 第二行为n个数，即每个元素,每个整数都在32位int范围内。以空格分隔。
输出描述:
所有连续子数组中和最大的值。

示例1
输入
3 -1 2 1

输出
3
*/
#include <iostream>
#include <limits.h>
using namespace std;
int main()
{
    int num = 0;
    cin >> num;
    int curMax = 0;
    int max = INT_MIN;//最小值的宏
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