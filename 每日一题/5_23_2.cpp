//https://www.nowcoder.com/practice/ac61207721a34b74b06597fe6eb67c52?tpId=85&&tqId=29862&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
/**
 * 题目描述
给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
输入描述:
输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。
输出描述:
为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10用A表示，等等）

示例1

输入
7 2

输出
111
*/
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int main()
{
    long long num = 0;
    cin >> num;
    int system = 0;
    cin >> system;
    stack<int> result;
    //要注意负数
    if (num < 0)
    {
        cout << "-";
        num = -num;
    }
    while (num > 0)
    {
        int temp = num % system;
        result.push(temp);
        num /= system;
    }
    while (!result.empty())
    {
        int temp = result.top();
        result.pop();
        if (temp > 9)
        {
            printf("%c", 'A' + temp - 10);
            continue;
        }
        cout << temp;
    }
    cout << endl;
}