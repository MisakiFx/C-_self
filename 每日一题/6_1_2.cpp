//https://www.nowcoder.com/practice/f8538f9ae3f1484fb137789dec6eedb9?tpId=37&&tqId=21283&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
/**
 * 题目描述
任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对
输入描述:
输入一个偶数

输出描述:
输出两个素数

示例1

输入
20
输出

7
13
*/
#include <iostream>
using namespace std;
bool isPrimeNum(int num)
{
    for(int i = 2; i < num; i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int num = 0;
    while(cin >> num)
    {
        int num1 = num / 2, num2 = num / 2;
        while(!isPrimeNum(num1) || !isPrimeNum(num2))
        {
            num1--;
            num2++;
        }
        cout << num1 << endl;
        cout << num2 << endl;
    }
}