//https://www.nowcoder.com/questionTerminal/d95d98a2f96e49078cd7df84ba0c9d79
/**
 * 链接：https://www.nowcoder.com/questionTerminal/d95d98a2f96e49078cd7df84ba0c9d79
来源：牛客网

和中国的节日不同，美国的节假日通常是选择某个月的第几个星期几这种形式，因此每一年的放假日期都不相同。具体规则如下：
* 1月1日：元旦
* 1月的第三个星期一：马丁·路德·金纪念日
* 2月的第三个星期一：总统节
* 5月的最后一个星期一：阵亡将士纪念日
* 7月4日：美国国庆
* 9月的第一个星期一：劳动节
* 11月的第四个星期四：感恩节
* 12月25日：圣诞节
现在给出一个年份，请你帮忙生成当年节日的日期。

输入描述:
输入包含多组数据，每组数据包含一个正整数year（2000≤year≤9999）。


输出描述:
对应每一组数据，以“YYYY-MM-DD”格式输出当年所有的节日日期，每个日期占一行。

每组数据之后输出一个空行作为分隔。
示例1
输入
2014
2013
输出
2014-01-01
2014-01-20
2014-02-17
2014-05-26
2014-07-04
2014-09-01
2014-11-27
2014-12-25

2013-01-01
2013-01-21
2013-02-18
2013-05-27
2013-07-04
2013-09-02
2013-11-28
2013-12-25
 */
//这道题要借助菜勒公式
// write your code here cpp
#include <iostream>
using namespace std;
int weekToDay(int y, int m, int c, int w, bool type)
{
    //菜勒公式的要求
    if(m == 1)
    {
        m = 13;
        y--;
    }
    if(m == 2)
    {
        m = 14;
        y--;
    }
    int i;
    //正数
    if(type == true)
    {
        int count = 0;
        for(i = 1; i <= 31; i++)
        {
            int week = (i + 2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;//蔡勒公式
            if(week + 1 == w)
            {
                count++;
            }
            if(count == c)
            {
                break;
            }
        }
    }
    //倒数
    else
    {
        int count = 0;
        for(i = 31; i >= 1; i--)
        {
            int week = (i + 2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;//蔡勒公式
            if(week + 1 == w)
            {
                count++;
            }
            if(count == c)
            {
                break;
            }
        }
    }
    return i;
}
int main()
{
    int y = 0;
    while(cin >> y)
    {
        printf("%d-01-01\n",y);
        printf("%d-01-%02d\n",y,weekToDay(y,1,3,1,1));
        printf("%d-02-%02d\n",y,weekToDay(y,2,3,1,1));
        printf("%d-05-%02d\n",y,weekToDay(y,5,1,1,0));//倒数
        printf("%d-07-04\n",y);
        printf("%d-09-%02d\n",y,weekToDay(y,9,1,1,1));
        printf("%d-11-%02d\n",y,weekToDay(y,11,4,4,1));
        printf("%d-12-25\n\n",y);
    }
}