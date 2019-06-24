//https://www.nowcoder.com/practice/7299c12e6abb437c87ad3e712383ff84?tpId=37&amp;&amp;tqId=21279&amp;rp=1&amp;ru
/**
 * 题目描述
完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。
它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。
例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1+2+4+7+14=28。
给定函数count(int n),用于计算n以内(含n)完全数的个数。计算范围, 0 < n <= 500000
返回n以内完全数的个数。 异常情况返回-1
输入描述:
输入一个数字

输出描述:
输出完全数的个数

示例1
输入
1000

输出
3
 */
#include <iostream>
#include <vector>
using namespace std;
bool isPerfect(int num)
{
    vector<int> primes;
    for(int i = 1; i < num; i++)
    {
        if(num % i == 0)
        {
            primes.push_back(i);
        }
    }
    int sum = 0;
    for(int i = 0; i < primes.size(); i++)
    {
        sum += primes[i];
    }
    if(sum == num)
    {
        return true;
    }
    return false;
}
int main()
{
    int num = 0;
    while(cin >> num)
    {
        int count = 0;
        for(int i = 1; i <= num; i++)
        {
            if(isPerfect(i))
            {
                count++;
            }
        }
        cout << count << endl;
    }
}