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