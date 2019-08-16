//https://www.nowcoder.com/questionTerminal/3549ff22ae2c4da4890e9ad0ccb6150d
/**
 * 
NowCoder开了一家早餐店，这家店的客人都有个奇怪的癖好：他们只要来这家店吃过一次早餐，就会每天都过来；并且，所有人在这家店吃了两天早餐后，接下来每天都会带一位新朋友一起来品尝。
于是，这家店的客人从最初一个人发展成浩浩荡荡成百上千人：1、1、2、3、5……
现在，NowCoder想请你帮忙统计一下，某一段时间范围那他总共卖出多少份早餐（假设每位客人只吃一份早餐）。

输入描述:
测试数据包括多组。
每组数据包含两个整数from和to(1≤from≤to≤80)，分别代表开店的第from天和第to天。


输出描述:
对应每一组输入，输出从from到to这些天里（包含from和to两天），需要做多少份早餐。
*/
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