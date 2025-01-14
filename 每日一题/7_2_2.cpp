//https://www.nowcoder.com/questionTerminal/82424d93369649b98720743c25edc6ce
/**
 * 链接：https://www.nowcoder.com/questionTerminal/82424d93369649b98720743c25edc6ce
来源：牛客网

小喵们很喜欢把自己装进容器里的（例如碗），但是要是碗的周长比喵的身长还短，它们就进不去了。

现在告诉你它们的身长，和碗的半径，请判断一下能否到碗里去。

输入描述:
输入有多组数据。

每组数据包含两个整数n (1≤n≤2^128) 和r (1≤r≤2^128)，分别代表喵的身长和碗的半径。

圆周率使用3.14。


输出描述:
对应每一组数据，如果喵能装进碗里就输出“Yes”；否则输出“No”。
示例1
输入
6 1
7 1
9876543210 1234567890
输出
Yes
No
No
 */
#include <iostream>
#include <climits>
using namespace std;
int main()
{
    double n;
    double r;
    while(cin >> n >> r)
    {
        double c = 2 * r * 3.14;
        if(n <= c)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}