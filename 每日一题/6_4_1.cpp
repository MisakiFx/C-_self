//https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&amp;&amp;tqId=21296&amp;rp=1&amp;ru
/**
 * 题目描述
根据输入的日期，计算是这一年的第几天。。

详细描述：

输入某年某月某日，判断这一天是这一年的第几天？。

 
输入描述:
输入三行，分别是年，月，日

输出描述:
成功:返回outDay输出计算后的第几天;
失败:返回-1

示例1

输入
2012
12
31

输出
366
 */
#include <iostream>
using namespace std;
int main()
{
    int year = 0;
    int month = 0;
    int days = 0;
    while(cin >> year >> month >> days)
    {
        int outDay = 0;
        int daysOfMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i = 1; i < month; i++)
        {
            outDay += daysOfMonth[i];
        }
        outDay += days;
        if(((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && month > 2)
        {
            outDay += 1;
        }
        cout << outDay << endl;
    }
}