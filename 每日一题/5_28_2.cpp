//https://www.nowcoder.com/practice/22948c2cad484e0291350abad86136c3?tpId=37&&tqId=21331&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
/**
 * 题目描述
正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。

输入描述:
输入两个正整数A和B。

输出描述:
输出A和B的最小公倍数。

示例1

输入
5 
7

输出
35
*/
/*
#include <iostream>
using namespace std;
int main()
{
    int num1 = 0;
    int num2 = 0;
    cin >> num1 >> num2;
    int max = 1;
    for(int i = 2; i <= (num1 < num2 ? num1 : num2); i++)
    {
        if(num1 % i == 0 && num2 % i == 0)
        {
            max = i;
        }
    }
    int min = num1 * num2 / max;
    cout << min << endl;
}
*/
//辗转相除求最大公因数
#include <iostream>
using namespace std;
int main()
{
    int a = 0, b = 0;
    while(cin >> a >> b)
    {
        //这里不用进行大小数判断，会自动在循环中交换
        int max = 1;
        int at = a;
        int bt = b;
        while(a % b != 0)
        {
            max = a % b;
            a = b;
            b = max;
        }
        cout << (at * bt / max) << endl;
    }
}